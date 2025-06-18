NAME = libftprintf.a

SRC = ft_printf.c ft_putstr.c ft_putptr.c ft_puthex.c \
		ft_put_nbr_fd.c ft_put_u_nbr_fd.c ft_get_num_length.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc

INCLUDES = -I. -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


MAIN = main.c
EXEC = main

run: all $(EXEC)
	./$(EXEC)

$(EXEC): $(MAIN) $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(MAIN) -L. -lftprintf -L$(LIBFT_DIR) -lft -o $(EXEC)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
