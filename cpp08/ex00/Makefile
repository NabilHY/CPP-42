CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
INCLUDE = .
MAIN = main.cpp
NAME = easyfind

all: $(NAME)

$(NAME):  $(MAIN) $(INCLUDE)
	$(CPP) $(FLAGS) -I$(INCLUDE)  $(OBJS) $(MAIN) -o $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

fclean:
	rm -rf $(NAME)
re: fclean all