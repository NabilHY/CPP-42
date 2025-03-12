CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
INCLUDE = .
OBJS = $(SRCS:.cpp=.o)
MAIN = main.cpp
NAME = span
SRCS = Span.cpp

all: $(NAME)

$(NAME): $(OBJS) $(MAIN) $(INCLUDE)
	$(CPP) $(FLAGS) -I$(INCLUDE)  $(OBJS) $(MAIN) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
re: fclean all