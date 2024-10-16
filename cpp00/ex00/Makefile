CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = megaphone.cpp
NAME = megaphone

all: $(NAME)

$(NAME): $(SRCS)
	$(CPP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm $(NAME)
re : clean all