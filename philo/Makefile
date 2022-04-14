NAME = philo

SRC_DIR = ./src
SRC = main.c libft.c check_args.c
SRC_PATH = $(addprefix$(SRC_DIR)/, $(SRC))
OBJ_DIR = ./objs
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INCLUDES = -I philo.h
MKDIR = mkdir -p $(@D)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ_FILES)
		$(MKDIR)
		$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_FILES) -o $(NAME)

clean:
		$(RM) $(OBJ_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

