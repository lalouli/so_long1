NAME = so_long
INC = so_long.h get_next_line/get_next_line.h
SRCS = main.c \
        check_map1.c\
        check_maps.c \
        find_playe.c \
        map.c \
        utils.c \
        get_next_line/get_next_line_utils.c \
        get_next_line/get_next_line.c \
		handl.c \
		mlx_u.c \
		render.c \

OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)
	@echo "███████╗ ██████╗     ██╗      ██████╗ ███╗   ██╗ ██████╗"
	@echo "██╔════╝██╔═══██╗    ██║     ██╔═══██╗████╗  ██║██╔════╝"
	@echo "███████╗██║   ██║    ██║     ██║   ██║██╔██╗ ██║██║  ███╗"
	@echo "╚════██║██║   ██║    ██║     ██║   ██║██║╚██╗██║██║   ██║"
	@echo "███████║╚██████╔╝    ███████╗╚██████╔╝██║ ╚████║╚██████╔╝"
	@echo "╚══════╝ ╚═════╝     ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all