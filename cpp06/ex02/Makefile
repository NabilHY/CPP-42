CPP=c++
FLAGS= -Wall -Wextra -Werror -std=c++98
MAIN=main.cpp
SRCS=Base.cpp
OBJS=$(SRCS:%.cpp=%.o)
INCLUDE=.
NAME=base

all: $(NAME)

$(NAME): $(OBJS) $(MAIN) $(INCLUDE)
	$(CPP) $(FLAGS) -I$(INCLUDE)  $(OBJS) $(MAIN) -o $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
re: fclean all