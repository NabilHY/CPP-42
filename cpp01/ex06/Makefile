CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = ./srcs/Harl.cpp
OBJS = $(SRCS:%.cpp=%.o)
MAIN = main.cpp
INCLUDE = ./include/Harl.hpp
NAME = harlFilter

all : $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

$(NAME): $(MAIN) $(OBJS) $(INCLUDE)
	$(CPP) $(FLAGS) $(INCLUDE) $(OBJS) $(MAIN) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
