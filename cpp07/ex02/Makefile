NAME := array

FLAGS := -Wall -Werror -Wextra -Wpedantic -std=c++11 -g

INCLUDES := -I.

all: $(NAME)

$(NAME): main.cpp
	g++ $^ $(FLAGS) $(INCLUDES) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all