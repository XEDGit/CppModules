NAME := array

FLAGS := -Wall -Werror -Wextra -std=c++98

INCLUDES := -I.

all: $(NAME)

$(NAME): main.cpp
	g++ $^ $(FLAGS) $(INCLUDES) -o $@

clean:
	rm -f array

fclean:
	rm -f array

re: fclean all