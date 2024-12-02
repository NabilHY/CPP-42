CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = ./srcs/AMateria.cpp \
./srcs/IMateriaSource.cpp \
./srcs/ICharacter.cpp \
./srcs/Ice.cpp \
./srcs/MateriaSource.cpp \
./srcs/Cure.cpp \
./srcs/Character.cpp 
OBJS = $(SRCS:%.cpp=%.o)
INCLUDE = ./include
MAIN = main.cpp
NAME = armageddon
SANITIZE = -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS) $(MAIN) $(INCLUDE)
	$(CPP) $(FLAGS)  -I$(INCLUDE)  $(OBJS) $(MAIN) -o $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
re: fclean all
