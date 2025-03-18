#include "BitcoinExchange.hpp"

/*

    Each ilne in the file must use the format
        Date    |   Value
         ---------------
        A Valid date will have the following format
            Year - Month - Day
            int - int - int
            They need to be in format of int to be valid
                Edge Case ====>  Leap Year --- Feb is 29 days
                                Non Leap Year --- Feb is 28 Days
        A Vaid value must be either a float or a positive int between 0 and 100

*/

int main(int ac, char **av) {
    try {
        BitcoinExchange::btc(ac, av);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    };
}