# SRCS		=	src/main.c \
# 				src/terminate.c \
# 				src/init/errors.c \
# 				src/init/node.c \
# 				src/init/stack.c \
# 				src/sort/path.c \
# 				src/sort/push.c \
# 				src/sort/r_rotate.c \
# 				src/sort/rotate.c \
# 				src/sort/sort.c \
# 				src/sort/swap.c \
# 				src/sort/utility.c

# OBJS			= $(addprefix $(OBJ_DIR),$(notdir $(patsubst %.c,%.o,$(SRCS))))

# OBJ_DIR			= obj/
# INC_DIR			= include/
# NAME			= push_swap
# CC				= gcc
# CFLAGS			= -Wall -Wextra -Werror -I $(INC_DIR)
# REMOVE			:= rm -f

# all: $(OBJ_DIR)

# # $(NAME): $(OBJS)
# # 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
# # 	chmod +x $(NAME)
# $(OBJ_DIR)%.o: $(SRCS) | $(OBJ_DIR) 
# 	$(CC) $(CFLAGS) -c $< -o $@
# $(OBJ_DIR):
# 	mkdir -p $(OBJ_DIR)

# clean:
# 	$(REMOVE) $(OBJS)
# fclean: clean
# 	$(REMOVE) $(NAME)
# 	$(REMOVE) -r $(OBJ_DIR)
# re: fclean all

# .PHONY: all clean fclean re

# FILES			=	main.c \
# 					terminate.c \
# 					init/errors.c \
# 					init/node.c \
# 					init/stack.c \
# 					sort/path.c \
# 					sort/push.c \
# 					sort/r_rotate.c \
# 					sort/rotate.c \
# 					sort/sort.c \
# 					sort/swap.c \
# 					sort/utility.c
FILES			=	$(subst src/,, $(shell find src/ -name "*.c"))

TEST			= 	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR			=	src/
OBJ_DIR			=	obj/
SRC				=	$(addprefix $(SRC_DIR), $(FILES))
# OBJ				=	$(addprefix $(OBJ_DIR), $(FILES:.c=.o))
OBJ				=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

CC				=	gcc

NAME			= 	push_swap
HEADER_DIR		= 	include

INCLUDES		= 	-I $(HEADER_DIR)
FLAGS 	= 	-Wall -Werror -Wextra

all: $(NAME)
	# @echo $(TEST)
	# @echo $(OBJ)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(INCLUDES) $(FLAGS) -c $< -o $@ -g

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)init $(OBJ_DIR)sort

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean: clean
	rm -rf $(OBJ_DIR)

re: clean all

.PHONY: all clean fclean re
