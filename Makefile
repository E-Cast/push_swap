NAME				:= push_swap
# >------------------------------< source files
SRCS	= main.c node.c errors.c stack.c utility.c push.c r_rotate.c rotate.c \
		swap.c path.c sort.c

SRCS 	:= $(addprefix $(SRC_DIR), $(SRCS))

# >------------------------------< object files
OBJS	= $(addprefix $(CACHE), $(notdir $(SRCS:.c=.o)))

# >------------------------------< directories
CACHE	:= .cache/
SRC_DIR	:= src/

# >------------------------------< compilation/archival
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror

all: $(NAME)

$(OBJS): | $(CACHE)

$(CACHE)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	chmod +x $(NAME)

$(CACHE):
	mkdir -p $(CACHE)

# >------------------------------< clean directories
REMOVE				:= rm -f
clean:
	$(REMOVE) $(OBJS)
fclean: clean
	$(REMOVE) $(NAME)
	$(REMOVE) -r $(CACHE)
re: fclean all

# >------------------------------< protect makefile
.PHONY: all clean fclean re
