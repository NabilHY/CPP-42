CPP = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
MAIN = tests.cpp
SRCS = Account.cpp
OBJS = $(SRCS:%.cpp=%.o)
INCLUDE = Account.hpp
NAME = $(%.log)
EXEC = account
LOG_FILE = $(shell date +%Y%m%d"_"%H%M%S".log")
LOG_FILE_CP = $(LOG_FILE)

all: $(LOG_FILE)

$(EXEC): $(INCLUDE) $(OBJS) $(MAIN)
	$(CPP) $(FLAGS) $(OBJS) $(MAIN) -o $(EXEC)

$(LOG_FILE): $(EXEC) $(INCLUDE) $(MAIN) $(OBJS)
	./$(EXEC) > $(LOG_FILE)

%.o:%.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm $(EXEC)
fclean: clean
	rm -rf *.log
re: clean fclean