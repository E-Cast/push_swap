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
SRC				:=	$(addprefix $(SRC_DIR), $(SRC))
OBJ				:=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))
NAME			:=	push_swap

B_SRC			=	main.c \
					terminate.c \
					init/errors.c \
					init/node.c \
					init/stack.c \
					sort/push.c \
					sort/r_rotate.c \
					sort/rotate.c \
					sort/swap.c \

B_SRC_DIR		:=	sources_bonus/
B_OBJ_DIR		:=	objects_bonus/
B_SRC			:=	$(addprefix $(B_SRC_DIR), $(B_SRC))
B_OBJ			:=	$(subst $(B_SRC_DIR), $(B_OBJ_DIR), $(B_SRC:.c=.o))
B_NAME			:=	checker

CC				:=	gcc
FLAGS			:=	-Wall -Werror -Wextra
# DEBUG			:=	-g 
INC_DIR			:= 	includes
INCLUDES		:=	-I $(INC_DIR) -I $(LIBFT_DIR)includes
LIBFT_DIR		:=	libft/
LIBFT			:=	$(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(FLAGS) $(DEBUG) $(INCLUDES) $(OBJ) $(LIBFT) -o $@
	@echo "$(CC) $(FLAGS) $(DEBUG)-o $(NAME)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) $(DEBUG) $(INCLUDES) -c $< -o $@
	@echo "$(CC) $(DEBUG)$< $@"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)init $(OBJ_DIR)sort

re: clean all

bonus: $(B_NAME)

$(B_NAME): $(B_OBJ_DIR) $(B_OBJ) $(LIBFT)
	@$(CC) $(FLAGS) $(DEBUG) $(INCLUDES) $(B_OBJ) $(LIBFT) -o $@
	@echo "$(CC) $(FLAGS) $(DEBUG)-o $(B_NAME)"

$(B_OBJ_DIR)%.o: $(B_SRC_DIR)%.c
	@$(CC) $(FLAGS) $(DEBUG) $(INCLUDES) -c $< -o $@
	@echo "$(CC) $< $@"

$(B_OBJ_DIR):
	mkdir -p $(B_OBJ_DIR)init $(B_OBJ_DIR)sort

re_bonus: clean bonus

libft:
	@git submodule init
	@git submodule update --remote

$(LIBFT): libft
	@make --no-print-directory -C $(LIBFT_DIR)

norm:
	@norminette $(SRC) $(B_SRC) $(INC_DIR) || true

clean:
	@rm -f $(OBJ) $(B_OBJ)
	@rm -f $(NAME) $(B_NAME)

fclean: clean
	@rm -rf $(OBJ_DIR) $(B_OBJ_DIR)
	@make --no-print-directory -C $(LIBFT_DIR) fclean

.PHONY: all re norm bonus re_bonus norm_bonus clean fclean