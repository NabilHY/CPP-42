CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = contact.cpp
MAIN = phonebook.cpp
OBJS = $(SRCS:%.cpp=%.o)
INCLUDE = phonebook.hpp contact.hpp
NAME = phonebook

all: $(NAME)

$(NAME): $(MAIN) $(OBJS)  $(INCLUDE)
	$(CPP) $(FLAGS) $(OBJS) $(MAIN) -o $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
fclean:
	rm -rf $(NAME)

re : clean all