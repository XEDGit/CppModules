NAME := iter

FLAGS := -Wall -Werror -Wextra -std=c++98

INCLUDES := -I.

all: $(NAME)

$(NAME): main.cpp
	g++ $^ $(FLAGS) $(INCLUDES) -o $@

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all