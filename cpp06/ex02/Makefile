SRC_DIR := src

INCLUDE := inc

SRC := $(wildcard $(SRC_DIR)/*.cpp)

OBJ_DIR := obj

OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))

FLAGS := -std=c++98 -Wall -Wextra -Werror -I $(INCLUDE)

NAME := identify

$(NAME): $(OBJ) | $(SRC_DIR)
	$(info Compiling executable...)
	$(CXX) $(FLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(FLAGS) $< -o $@ -c

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

re: fclean $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

rebug: fclean debug

debug: FLAGS  = -std=c++98 -I $(INCLUDE) -g
debug: $(NAME)
