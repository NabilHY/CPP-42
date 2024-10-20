CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = srcs/Weapon.cpp \
srcs/HumanA.cpp \
srcs/HumanB.cpp
INCLUDE = include
MAIN = main.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = program

all : $(NAME)


$(NAME): $(OBJS) $(INCLUDE) $(SRCS) $(MAIN)
	$(CPP) $(FLAGS) -I$(INCLUDE) $(OBJS) $(MAIN) -o $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
