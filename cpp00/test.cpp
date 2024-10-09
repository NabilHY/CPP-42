#include <cctype> // for std::isdigit
#include <iostream>
#include <string>
#include <ctime>

int	main(void)
{
	time_t timestamp;
	char output[50];
	struct tm *datetime;

	time(&timestamp);
	strftime(cur_time);
	cur_time = ctime(&timestamp);

	std::cout << cur_time << std::endl;
	return (0);
}