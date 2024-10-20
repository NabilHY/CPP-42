CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
MAIN = main.cpp
NAME = program

all: $(NAME)

$(NAME): $(MAIN)
	$(CPP) $(FLAGS) $(MAIN) -o $(NAME)
clean:
	rm -rf $(NAME)
re: clean all
