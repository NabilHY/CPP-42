CPP=c++
FLAGS= -Wall -Wextra -Werror -std=c++11
MAIN=main.cpp
SRCS=Serializer.cpp
OBJS=$(SRCS:%.cpp=%.o)
INCLUDE=.
NAME=serialize

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