NAME = cast
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Base.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) && clear

fclean: clean
	rm -f $(NAME)

re: fclean all