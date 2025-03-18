CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = BitcoinExchange.cpp \
Line.cpp
OBJS = $(SRCS:%.cpp=%.o)
INCLUDE = .
MAIN = main.cpp
NAME = btc

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
