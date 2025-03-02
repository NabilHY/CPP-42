CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
OBJS = $(SRCS:%.cpp=%.o)
INCLUDE = .
MAIN = main.cpp
NAME = array

all: $(NAME)

$(NAME): $(OBJS) $(MAIN) $(INCLUDE)
	$(CPP) $(FLAGS) $() -I$(INCLUDE)  $(OBJS) $(MAIN) -o $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

fclean: clean
	rm -rf $(NAME)
re: fclean all