#include <cctype> // for std::isdigit
#include <iostream>
#include <string>

bool	isValidInteger(const std::string &input)
{

	if (input.empty())
		return (false);
	for (int i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
			return (false);
	}
	return (true); // All characters are digits
}


int	main(void)
{
	std::string input;
	int index;

	// Continuously prompt the user until a valid integer is entered
	while (true)
	{
		std::cout << "Please enter a valid index (integer): ";
		std::cin >> input;

		// Check if the input is a valid integer
		if (isValidInteger(input))
		{
			index = std::stoi(input); // Convert the valid string to an integer
			break ;                    // Exit the loop if input is valid
		}
		else
		{
			std::cout << "Invalid input. Please enter an integer.\n";
		}
	}

	std::cout << "You entered a valid index: " << index << std::endl;

	return (0);
}