NAME:= minitalk
SRCS_DIRS:= ./
SRCS_SERVER:= server.c
SRCS_CLIENT:= client.c
GCC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -L./ft_printf -lftprintf
OBJS_SERVER := $(SRCS_SERVER:.c=.o)
OBJS_CLIENT := $(SRCS_CLIENT:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) server client

$(LIBFT):
	cd ft_printf && make

server: server.o
	$(GCC) $(FLAGS) $(OBJS_SERVER) $(LIBRARIES) -o server

client: client.o
	$(GCC) $(FLAGS) $(OBJS_CLIENT) $(LIBRARIES) -o client

clean:
	cd ft_printf && make clean
	rm -fr $(OBJS_CLIENT)
	rm -fr $(OBJS_SERVER)

fclean: clean
	cd ft_printf && make fclean
	rm server client

re: fclean all

