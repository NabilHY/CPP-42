CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = Harl.cpp
OBJS = $(SRCS=.cpp:.o)
INCLUDE = ./include
MAIN = main.cpp
NAME = harl

all : $(NAME)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INCLUDE)
	$(CPP) $(FLAGS) $(OBJS) $(MAIN) -o $(NAME)

clean:
	rm -rf $
