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
INCLUDES		:=	-I $(INC_DIR)

B_SRC			= main.c

B_SRC_DIR		:=	sources_bonus/
B_OBJ_DIR		:=	objects_bonus/
B_INC_DIR		:= 	includes_bonus
B_SRC			:=	$(addprefix $(B_SRC_DIR), $(B_SRC))
B_OBJ			:=	$(subst $(B_SRC_DIR), $(B_OBJ_DIR), $(B_SRC:.c=.o))
B_NAME			:=	checker
B_INCLUDES		:=	-I $(B_INC_DIR)

CC				:=	gcc
FLAGS			:=	-Wall -Werror -Wextra
# DEBUG			:=	-g

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(FLAGS) $(DEBUG) $(INCLUDES) $(OBJ) -o $@
	@echo "$(CC) $(FLAGS) $(DEBUG) $(INCLUDES) -o $(NAME)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) $(DEBUG) $(INCLUDES) -c $< -o $@
	@echo "$(CC) $< $@"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)init $(OBJ_DIR)sort

re: clean all

norm:
	@norminette $(SRC) $(INC_DIR) || true

bonus: $(B_NAME)

$(B_NAME): $(B_OBJ_DIR) $(B_OBJ)
	@$(CC) $(FLAGS) $(DEBUG) $(B_INCLUDES) $(B_OBJ) -o $@
	@echo "$(CC) $(FLAGS) $(DEBUG) $(B_INCLUDES) -o $(B_NAME)"

$(B_OBJ_DIR)%.o: $(B_SRC_DIR)%.c
	@$(CC) $(FLAGS) $(DEBUG) $(B_INCLUDES) -c $< -o $@
	@echo "$(CC) $< $@"

$(B_OBJ_DIR):
	mkdir -p $(B_OBJ_DIR)

re_bonus: clean bonus

norm_bonus:
	@norminette $(B_SRC) $(B_INC_DIR) || true

clean:
	@rm -f $(OBJ) $(B_OBJ)
	@rm -f $(NAME) $(B_NAME)

fclean: clean
	@rm -rf $(OBJ_DIR) $(B_OBJ_DIR)

.PHONY: all re norm bonus re_bonus norm_bonus clean fclean