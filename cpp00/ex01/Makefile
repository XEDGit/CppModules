SRC_DIR := src

INCLUDE := inc

SRC := $(wildcard $(SRC_DIR)/*.cpp)

FLAGS := -std=c++98 -Wall -Wextra -Werror -I $(INCLUDE)

NAME := phonebook

$(NAME): $(SRC)
	$(info Compiling executable...)
	$(CXX) $(FLAGS) $^ -o $@

re: clean $(NAME)

clean:
	rm -f $(NAME)

rebug: clean debug

debug: FLAGS  = -std=c++98 -I $(INCLUDE) -g
debug: $(NAME)