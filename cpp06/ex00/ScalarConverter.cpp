#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Constructor" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs)
{
    (void)rhs;
    std::cout << "Copy constructor" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &rhs) {
    std::cout << "Copy assignment operator" << std::endl;
    return rhs;
}

const char *ScalarConverter::ImpossibleConversion::what() const throw() { return "Impossible conversion."; };

const char *ScalarConverter::NonDisplayable::what() const throw() { return "Non Displayable."; };

const char *ScalarConverter::OutOfRange::what() const throw() { return "Numero fuera de covertura !"; };

void toFloat(std::ostream &os, double value, int prec, std::string &literal) {

    int decimalDigits = Helpers::digitsBeforeDecimal(literal); 

    if (decimalDigits > 10) {
        throw ScalarConverter::OutOfRange();
    }

    float floatVal = static_cast<float>(value);
    if (prec == 0) {
        os << std::fixed << std::setprecision(prec) << floatVal << ".0f";
    } else if (prec == -1 || decimalDigits >= 9) {
        os << std::scientific << std::setprecision(6) << floatVal << "f";
    } else {
        os << std::fixed << std::setprecision(prec) << floatVal << "f";
    }
}

void toDouble(std::ostream &os, double value, int prec, std::string &literal)
{
    if (Helpers::digitsBeforeDecimal(literal) > 15) {
        throw ScalarConverter::OutOfRange();
    }

    if (prec != -1)
        os << std::fixed << std::setprecision(prec) << value;
    else
        os << std::scientific << std::setprecision(prec) << value;
}

void toChar(std::ostream &os, double doubleVal)
{
    char charVal = static_cast<char>(doubleVal);
    try {
        if (doubleVal > 127 || doubleVal < 0) {
            throw ScalarConverter::ImpossibleConversion();
        } else if (charVal >= 32 && charVal <= 126) {
            os << "'" << static_cast<char>(charVal) << "'";
        }
        else {
            throw ScalarConverter::NonDisplayable();
        }
    }
    catch (const std::invalid_argument &e)
    {
        throw ScalarConverter::ImpossibleConversion(); // Invalid argument for double conversion
    }
    catch (const std::out_of_range &e)
    {
        throw ScalarConverter::ImpossibleConversion(); // Out of range value for double
    }
}

void toInt(std::ostream &os, double value)
{
    long intVal = static_cast<long>(value);
    if (std::isnan(intVal) || std::isinf(intVal) || intVal > INT_MAX || intVal < INT_MIN) {
        
        throw ScalarConverter::ImpossibleConversion();
    }
    os << static_cast<int>(intVal);
}

void ScalarConverter::convert(std::string &literal)
{

    if (literal.empty())
        throw std::invalid_argument("Literal is Empty !");

    Helpers::trim(literal);

    const std::string specials[] = {
        "+inf",
        "-inf",
        "+inff",
        "-inff",
        "nan",
        "nanf"
    };

    for (size_t i = 0; i < 6; i++)
    {
        if (specials[i] == literal)
        {
            Helpers::handleSpecials(literal);
            return;
        }
    }

    double value;
    if (!Helpers::scientificNot(literal) && !Helpers::intChecker(literal) && !Helpers::floatingPointChecker(literal) && !Helpers::isChar(literal))
        throw std::invalid_argument("Argument format is invalid!");

    if (!Helpers::isChar(literal))
        value = Helpers::stringToDouble(literal.c_str());
    else
        value = static_cast<double>(literal[0]);

    try
    {
        std::cout << "char: ";
        toChar(std::cout, value);
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "int: ";
        toInt(std::cout, value);
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "float: ";
        toFloat(std::cout, value, Helpers::decCount(literal, true), literal);
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "double: ";
        toDouble(std::cout, value, Helpers::decCount(literal, false), literal);
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}