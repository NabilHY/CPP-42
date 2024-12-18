CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
INCLUDE = ./include
SRCS = srcs/Zombie.cpp \
srcs/zombieHorde.cpp
MAIN = main.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = zombie

all : $(NAME)

$(NAME): $(OBJS) $(MAIN) $(INCLUDE)
	$(CPP) $(FLAGS) -I$(INCLUDE) $(OBJS) $(MAIN) -o $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
