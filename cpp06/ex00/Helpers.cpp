#include "Helpers.hpp"

void Helpers::handleSpecials(const std::string &lit)
{
    std::cerr << "char: impossible" << std::endl;
    std::cerr << "int: impossible" << std::endl;

    if (lit.length() == 5 || lit == "nanf")
    {
        std::cout << "float: " << lit << std::endl;
    }
    else
    {
        std::cout << "float: " << lit << "f" << std::endl;
    }
    std::cout << "double: " << lit << std::endl;
}

bool Helpers::intChecker(const std::string &literal)
{
    unsigned int i = 0;
    unsigned int len = literal.length();

    if (literal[0] == '+' || literal[0] == '-')
    {
        i++;
    }

    if (i >= len || !isdigit(literal[i]))
    {
        return false;
    }

    while (i < len && isdigit(literal[i]))
    {
        i++;
    }

    return i == len;
}

bool Helpers::floatingPointChecker(const std::string &literal)
{
    unsigned int i = 0;
    unsigned int len = literal.length();

    if (len == 0)
        return false;

    if (literal[i] == '+' || literal[i] == '-')
    {
        i++;
    }

    bool hasDigits = false;
    while (i < len && isdigit(literal[i]))
    {
        hasDigits = true;
        i++;
    }

    if (i < len && literal[i] == '.')
    {
        i++;
        while (i < len && isdigit(literal[i]))
        {
            hasDigits = true;
            i++;
        }
    }

    if (i == len && hasDigits)
        return true;

    if (i < len && literal[i] == 'f')
    {
        i++;
    }

    return hasDigits && i == len;
}

bool Helpers::scientificNot(const std::string &literal)
{
    size_t ePos = literal.find_first_of("eE");
    if (ePos == std::string::npos)
        return false; // No 'e' or 'E' found


    // Check the part before 'e' or 'E'
    std::string mantissa = literal.substr(0, ePos);
    if (!floatingPointChecker(mantissa) && !intChecker(mantissa))
        return false; // Invalid mantissa

    // Check the part after 'e' or 'E'
    std::string exponent = literal.substr(ePos + 1);
    if (exponent.empty())
        return false; // No exponent

    // Check for optional sign in the exponent
    size_t i = 0;
    if (exponent[i] == '+' || exponent[i] == '-')
        i++;

    // Check that the rest of the exponent is digits
    if (i >= exponent.length())
        return false; // No digits after the sign

    while (i < exponent.length())
    {
        if (!isdigit(exponent[i]))
            return false; // Invalid character in exponent
        i++;
    }

    return true;
}

bool Helpers::isChar(const std::string &literal)
{
    if (literal.length() == 1 && literal[0] >= 32 && literal[0] <= 126 && !isdigit(literal[0]))
        return true;
    return false;
}

void Helpers::trim(std::string &str)
{

    if (!str.empty() && (str[0] == ' '))
        return ;

    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    size_t last = str.find_last_not_of(" \t\n\r\f\v");

    if (first == std::string::npos)
        str.clear(); // The string is all spaces
    else
        str = str.substr(first, last - first + 1);
}

bool Helpers::initialChecks(std::string &literal)
{
    if (literal.empty())
        throw std::invalid_argument("Literal is Empty !");

    trim(literal);
 
    const std::string specials[] = {
        "+inf",
        "-inf",
        "+inff",
        "-inff",
        "nan",
        "nanf"};

    for (size_t i = 0; i < 6; i++)
    {
        if (specials[i] == literal)
        {
            handleSpecials(literal);
            return true;
        }
    }

    if (!Helpers::scientificNot(literal) && !Helpers::intChecker(literal) 
        && !Helpers::floatingPointChecker(literal) && !Helpers::isChar(literal))
        return false;

    return false;
}

bool Helpers::all_digits(std::string literal)
{
    for (unsigned int i = 0; i < literal.length(); i++)
    {
        if (!isdigit(literal[i]))
            return false;
    }
    return true;
}

bool Helpers::is_valid(std::string literal)
{
    int intVal = atoi(literal.c_str());
    if (intVal >= 32 && intVal <= 126)
    {
        return true;
    }
    return false;
}

int Helpers::digitsBeforeDecimal(const std::string &str) {
    // Find the position of the decimal point
    size_t decimalPos = str.find('.');

    // If the decimal point is found, return its position
    if (decimalPos != std::string::npos) {
        return static_cast<int>(decimalPos);
    }

    // If no decimal point is found, return the length of the string
    return static_cast<int>(str.length());
}


int Helpers::decCount(const std::string &literal, bool isFloat) {
    char *endPtr;
    double value = std::strtod(literal.c_str(), &endPtr);

    (void)value;
    size_t precLimit = isFloat ? 6 : 14;
    size_t decimalPos = literal.find('.');


    if (decimalPos == std::string::npos) {
        return 1;
    }

    // Calculate the number of digits after the decimal point
    size_t lengthAfterDecimal = 0;
    for (size_t i = decimalPos + 1; i < literal.length(); ++i) {
        if (std::isdigit(static_cast<unsigned char>(literal[i]))) {
            lengthAfterDecimal++;
        } else {
            break;  // Stop at the first non-digit character
        }
    }

    // Remove trailing zeros from the count
    for (size_t i = literal.length() - 1; literal[i] == '.'; i--) {
        if (literal[i] == '0') {
            lengthAfterDecimal--;
        } else {
            break;  // Stop at the first non-zero character
        }
    }

    if (isFloat && lengthAfterDecimal == 0)
        return 0;
    else if (lengthAfterDecimal > precLimit)
        return -1;
    return (lengthAfterDecimal > precLimit ? 1 : static_cast<int>(lengthAfterDecimal));

}

double Helpers::stringToDouble(const char* str) {
    char* endPtr;
    double value = std::strtod(str, &endPtr);

    return value;
}
