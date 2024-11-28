CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = ./srcs/Animal.cpp \
./srcs/Cat.cpp \
./srcs/Dog.cpp \
./srcs/WrongCat.cpp \
./srcs/WrongAnimal.cpp 
OBJS = $(SRCS:%.cpp=%.o)
INCLUDE = ./include
NAME = animal
MAIN = main.cpp
# SANITIZE = -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS) $(MAIN) $(INCLUDE)
	$(CPP) $(FLAGS) -I$(INCLUDE) $(OBJS) $(MAIN) -o $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
re: fclean all