CPP=c++
FLAGS= -Wall -Wextra -Werror -std=c++98
MAIN=main.cpp
INCLUDE=.
NAME=iter

all: $(NAME)

$(NAME):  $(MAIN) $(INCLUDE)
	$(CPP) $(FLAGS) -I$(INCLUDE) $(MAIN) -o $(NAME)

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all