CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = ./srcs/newZombie.cpp \
./srcs/randomChump.cpp \
./srcs/Zombie.cpp
OBJS = $(SRCS:%.cpp=%.o)
INCLUDE = ./include/Zombie.hpp
MAIN = main.cpp
NAME = zombie

all: $(NAME)


$(NAME): $(MAIN) $(OBJS) $(INCLUDE)
	$(CPP) $(FLAGS) -I$(INCLUDE) $(OBJS) $(MAIN) -o $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
