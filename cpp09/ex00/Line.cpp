#include "Line.hpp"

std::string Line::date;
std::string Line::value;

size_t Line::digitsAfterDecimal(const std::string &str) {
    size_t decimalPos = str.find('.');
    if (decimalPos != std::string::npos) {
        size_t endPos = str.find_last_not_of('0');
        if (endPos == decimalPos) {
            return 0;
        }
        return static_cast<int>(endPos - decimalPos);
    }
    return 0;
}

bool Line::doublePointChecker(const std::string &literal) {
    if (literal.empty()) {
        return false;
    }
    std::stringstream ss(literal);
    double num;
    ss >> num;
    if (ss.fail()) {
        return false;
    }
    char remainingChar;
    if (ss >> remainingChar) {
        return false;
    }
    return true;
}

Line::Line(std::string line) {
    std::stringstream ss(line);
    std::string datePart;
    double val;

    std::getline(ss, datePart, '|');
    std::string valuePart;
    std::getline(ss, valuePart);

    datePart.erase(0, datePart.find_first_not_of(' '));
    datePart.erase(datePart.find_last_not_of(' ') + 1);

    if (!doublePointChecker(valuePart)) {
        throw Line::InvalidLine();
    }

    std::stringstream(valuePart) >> val;
    Line::date = datePart;
    Line::value = std::to_string(val);

    if (datePart.empty()) {
        throw Line::InvalidLine();
    }
    std::stringstream dateStream(datePart);
    int year, month, day;
    char dash1, dash2;
    dateStream >> year >> dash1 >> month >> dash2 >> day;
    setYear(year);
    setMonth(month);
    setDay(year, month, day);
    setValue(val);
}
void Line::setValue(int value) {
    if (value < 0) {
        throw Line::NegativeVal();
    } else if (value > 1000) {
        throw Line::LargeVal();
    }
}

void Line::setYear(int y) {
    if (y <= 0 || y > 9999) {
        throw Line::BadInput();
    }
}

void Line::setMonth(int m) {
    if (m < 1 || m > 12) {
        throw Line::BadInput();
    }
}

void Line::setDay(int y, int m, int d) {
    bool isLeap = (y % 4) == 0 && ((y % 100) != 0 || (y % 400) == 0);
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (m == 2 && isLeap) {
        daysInMonth[1] = 29;
    }

    if (d < 1 || d > daysInMonth[m - 1]) {
        throw Line::BadInput();
    }
}