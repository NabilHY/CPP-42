CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
INCLUDE = .
OBJS = $(SRCS:.cpp=.o)
MAIN = main.cpp
NAME = mutantStack

all: $(NAME)

$(NAME):  $(MAIN) $(INCLUDE)
	$(CPP) $(FLAGS) -I$(INCLUDE)  $(OBJS) $(MAIN) -o $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
re: fclean all