NAME := libftprintf.a
SRCS := ft_printf.c ft_print_memory.c ft_printf_chars.c ft_printf_handle_nums.c
SRCS_DIRS := ./
OBJS := ${SRCS:.c=.o}
LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a
CC := gcc
FLAGS = -Wall -Werror -Wextra
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

all: $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): ${OBJS}
	cd $(LIBFT_DIR) && make
	@cp $(LIBFT) ./
	@mv $(LIBFT_NAME) $(NAME)
	ar crs $(NAME) $(OBJS)

clean: 
	cd $(LIBFT_DIR) && make clean
	rm -f $(OBJS)

fclean: clean
	cd $(LIBFT_DIR) && make fclean
	rm -f $(NAME)

re: fclean all
