CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = Bureaucrat.cpp \
Form.cpp
INCLUDE = .
OBJS = $(SRCS:%.cpp=%.o)
MAIN = main.cpp
NAME = forms
# SANITIZE = -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE) $(MAIN) $(INCLUDE)
	$(CPP) $(FLAGS) $(OBJS) $(MAIN) -o $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
re: fclean all