SRC_DIR := src

INCLUDE := inc

SRC := $(wildcard $(SRC_DIR)/*.cpp)

INC := $(wildcard $(INCLUDE)/*.hpp)

OBJ_DIR := obj

OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))

FLAGS := -I $(INCLUDE) -fconcepts -O3 -flto

NAME := PmergeMe

$(NAME): $(OBJ) | $(SRC_DIR)
	$(info Compiling executable...)
	$(CXX) $(FLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC) | $(OBJ_DIR)
	$(CXX) $(FLAGS) $< -o $@ -c

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

re: fclean $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

rebug: fclean debug

debug: FLAGS  = -I $(INCLUDE) -fconcepts -g
debug: $(NAME)
