CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = ./srcs/ClapTrap.cpp \
./srcs/ScavTrap.cpp \
./srcs/FragTrap.cpp
OBJS = $(SRCS:%.cpp=%.o)
INCLUDE = ./include
MAIN = main.cpp
NAME = fragtrap

all: $(NAME)

$(NAME): $(OBJS) $(MAIN) $(INCLUDE)
	$(CPP) $(FLAGS) -I$(INCLUDE) $(OBJS) $(MAIN) -o $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
re: fclean all