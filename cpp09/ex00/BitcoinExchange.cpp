#include "BitcoinExchange.hpp"

std::map<std::string, double> BitcoinExchange::db;

BitcoinExchange::BitcoinExchange() {};
BitcoinExchange::~BitcoinExchange() {};
BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs) { *this = rhs; };
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &rhs) {
    if (this != &rhs) {
        this->db = rhs.db;
    };
    return *this;
};

const char * BitcoinExchange::InvalidArgument::what() const throw () {
    return "Error: could not open file.";
};

const char * BitcoinExchange::MissingRow::what() const throw () {
    return "Error: Missing Top Row: (date | value)";
};

bool    fileExists(char *filename) {
    std::ifstream file(filename);
    std::ifstream dbFile("data.csv");

    return file.good() && dbFile.good();
}


void BitcoinExchange::loadDatabaseFromCSV() {
    std::ifstream dbFile("data.csv");
    std::string line;
    
    // Read each line from the CSV file and update the map
    while (std::getline(dbFile, line)) {
        std::stringstream ss(line);
        std::string curDate;
        double rate;
        std::getline(ss, curDate, ',');
        ss >> rate;
        BitcoinExchange::db[curDate] = rate;
    }
}

std::string BitcoinExchange::doubleToString(double num) {
    std::ostringstream oss;
    oss << num;
    return oss.str();
}

void BitcoinExchange::printExchangeRate(const std::string &date, const std::string &value, double rate) {
    double count = std::atof(value.c_str());
    double result = rate * count;

    std::cout << date << " => " << std::fixed 
              << std::setprecision(Line::digitsAfterDecimal(BitcoinExchange::doubleToString(count))) 
              << count << " = " << std::fixed 
              << std::setprecision(Line::digitsAfterDecimal(BitcoinExchange::doubleToString(result))) 
              << result << std::endl;
}

std::map<std::string, double>::iterator BitcoinExchange::getClosestDate(const std::string &date) {
    std::map<std::string, double>::iterator it_lower = BitcoinExchange::db.lower_bound(date);
    
    // If we found a date that is >= the given date
    if (it_lower != BitcoinExchange::db.begin()) {
        --it_lower;  // Move the iterator back to the closest previous date
    }
    
    return it_lower;
}

void BitcoinExchange::findExchangeRate(const std::string &date, const std::string &value) {
    std::map<std::string, double>::iterator it = BitcoinExchange::db.find(date);

    if (it != BitcoinExchange::db.end())
        BitcoinExchange::printExchangeRate(date, value, it->second);
    else {
        loadDatabaseFromCSV();  // Load the database from the CSV file if not found
        std::map<std::string, double>::iterator it_lower = BitcoinExchange::getClosestDate(date);
        if (it_lower != BitcoinExchange::db.end() && !it_lower->first.empty()) {
            BitcoinExchange::printExchangeRate(date, value, it_lower->second);
        }
    }
}

void    initSearch(std::string filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::ios_base::failure("Error: File Not open!");
    }
    std::string line;
    std::getline(file, line);
    if (line != "date | value")
        throw BitcoinExchange::MissingRow();
    while (std::getline(file, line)) {
        try {
            Line currentLine = Line(line);
            (void)currentLine;
            BitcoinExchange::findExchangeRate(Line::date, Line::value);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        };
    };
    file.close();
}

void    BitcoinExchange::btc(int ac, char **av) {
    std::string filename;
    if (ac == 2 && fileExists(av[1])) {
        initSearch(av[1]);
    } else {
        throw BitcoinExchange::InvalidArgument();
    }
};

/*
    Using std::map 
*/