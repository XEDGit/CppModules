NAME := polymorphism

SRC_DIR	:= src

OBJ_D := obj

SRC := $(wildcard src/*.cpp)

OBJS := $(addprefix $(OBJ_D)/, $(notdir $(SRC:.cpp=.o)))

HEADERS := -Iinc

FLAGS := -Wextra -Wall -Werror -std=c++98

all: $(NAME)

debug: FLAGS = -g -fsanitize=address
debug: MAKE_RULE = debug
debug: fclean $(NAME)

$(OBJ_D):
	@mkdir $(OBJ_D)
	@echo "\033[32mCreated $(OBJ_D)/ directory!\033[0m"

run: all
	./$(NAME)

$(OBJ_D)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_D)
	@$(CXX) $< -o $@ -c $(FLAGS) $(HEADERS)
	@echo "\033[32mCompiled $@!"

$(NAME): $(OBJS)
	@$(CXX) $^ -o $@ $(FLAGS) $(HEADERS)
	@echo "\033[32mCompiled $@!"
	@echo
	@echo "Done!\033[0m"


clean:
	@rm -rf $(OBJ_D)
	@echo "\033[32mRemoved $(OBJ_D) folder!\033[0m"

fclean:
	@rm -rf $(NAME) $(OBJ_D)
	@echo "\033[32mRemoved $(NAME) and $(OBJ_D) folder!\033[0m"

re: fclean all
