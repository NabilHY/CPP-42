CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
MAIN = main.cpp
NAME = cpp_sed

all : $(NAME)

$(NAME): $(MAIN)
	$(CPP) $(FLAGS) $(MAIN) -o $(NAME)

clean:
	find . -type f ! -name "Makefile" ! -name "*.cpp" -delete
fclean: clean
	rm -rf $(NAME)
re: fclean all
