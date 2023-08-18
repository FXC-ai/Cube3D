NAME = cub3D

INCLUDES = includes

MAC_FLAGS = -framework OpenGL -framework AppKit

SRCS =  $(addprefix includes/get_next_line/, get_next_line.c get_next_line_utils.c) \
		$(addprefix srcs/, main.c init_window.c hook.c display.c display2.c main_utils.c) \
		$(addprefix srcs/render2D/, minimap.c render_wall.c) \
		$(addprefix srcs/parsing/, initializer.c args_manager.c copy_file_utils.c parsing.c parsing2.c parsing3.c wall_manager.c wall_manager2.c wall_manager3.c map_parser.c map_parser_utils.c map_parser_utils2.c map_parser_utils3.c map_parser_utils4.c map_parser_utils5.c map_parser_utils6.c map_parser_utils7.c) \
		$(addprefix srcs/game_tools/, utils.c utils2.c utils3.c draw_segment.c key_moves.c) \
		$(addprefix srcs/render3D/, ray_caster.c get_color.c 3D_wall_render.c find_pixel_screen.c utils.c) \
		$(addprefix srcs/render3D/ray_caster_utils/, utils1.c utils2.c utils3.c utils4.c) 


LIBS 	= $(addprefix includes/, libft/libft.a)
OBJS	= ${SRCS:.c=.o}
CFLAGS	=  -Wall -Wextra -Werror
CC		= gcc
RM		= rm -f


%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C includes/mlx
	make -C includes/libft
	cp includes/mlx/libmlx.dylib .
	$(CC)   $(CFLAGS) $(OBJS) $(LIBS) -L includes/mlx -lmlx $(MAC_FLAGS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C includes/mlx

fclean:		clean
			$(RM) $(NAME)
			rm libmlx.dylib
			make fclean -C includes/libft

re:			fclean all

.PHONY: all clean fclean re