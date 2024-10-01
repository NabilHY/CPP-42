CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = phonebook.cpp contact.cpp
INCLUDE = phonebook.hpp contact.hpp
NAME = phonebook

all: $(NAME)

$(NAME): $(INCLUDE)
	$(CPP) $(FLAGS) $(SRCS) -o $(NAME)
clean:
	rm $(NAME)
re : clean all