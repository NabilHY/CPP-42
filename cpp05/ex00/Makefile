CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = Bureaucrat.cpp
OBJS = $(SRCS:%.cpp=%.o)
INCLUDE = .
NAME = bureaucrat
MAIN = main.cpp
# SANITIZE = -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE) $(MAIN) $(INCLUDE)
	$(CPP) $(FLAGS) -I. $(OBJS) $(MAIN) -o $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
re: fclean all