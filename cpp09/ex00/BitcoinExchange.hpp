#pragma once

#include "Line.hpp"

class BitcoinExchange {
    private:
        static std::map<std::string, double> db;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &rhs);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        BitcoinExchange(const BitcoinExchange &);
        static  void    printExchangeRate(const std::string &date, const std::string &value, double rate);
        static  void    btc(int ac, char **av);
        static  void    findExchangeRate(const std::string &, const std::string &);
        static  void    loadDatabaseFromCSV();
        static  std::string     doubleToString(double);
        static  std::map<std::string, double>::iterator     findRateForDate(const std::string &date);
        static  std::map<std::string, double>::iterator     getClosestDate(const std::string &date);
        
        class InvalidArgument : public std::exception {
            const char * what() const throw();
        };
        class MissingRow : public std::exception {
            const char * what() const throw();
        };
};