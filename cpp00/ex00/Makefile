SRC := main.cpp

FLAGS := -std=c++98 -Wall -Wextra -Werror

NAME := megaphone

$(NAME): $(SRC)
	$(info Compiling executable...)
	$(CXX) $(FLAGS) $^ -o $@

clean:
	rm -f $(NAME)