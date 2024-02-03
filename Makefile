SRC				=	main.c \
					terminate.c \
					init/errors.c \
					init/node.c \
					init/stack.c \
					sort/path.c \
					sort/push.c \
					sort/r_rotate.c \
					sort/rotate.c \
					sort/sort.c \
					sort/swap.c \
					sort/utility.c

SRC_DIR			:=	sources/
OBJ_DIR			:=	objects/
INC_DIR			:= 	includes
SRC				:=	$(addprefix $(SRC_DIR), $(SRC))
OBJ				:=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

NAME			:=	push_swap
CC				:=	gcc
FLAGS			=	-Wall -Werror -Wextra -I $(INC_DIR)

all: $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $@
	@echo "$(CC) $(FLAGS) -o $@"

debug: $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) -g $(OBJ) -o $(NAME)
	@echo "$(CC) $(FLAGS) -g -o $(NAME)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)init $(OBJ_DIR)sort

clean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

fclean: clean
	@rm -rf $(OBJ_DIR)

re: clean all

.PHONY: all clean fclean re