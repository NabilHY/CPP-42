CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = ./srcs/Fixed.cpp ./srcs/Point.cpp
MAIN = main.cpp
OBJS = $(SRCS:%.cpp=%.o)
INCLUDE = ./include
NAME = fixed

all : $(NAME)

$(NAME): $(OBJS) $(INCLUDE) $(MAIN)
	$(CPP) -I$(INCLUDE) $(OBJS) $(MAIN) -o $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all