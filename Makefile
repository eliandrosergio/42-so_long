LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	main.c \
					draw.c \
					init.c \
					read_map.c \
					map_fts1.c \
					map_fts2.c \
					map_validate.c \
					player_update.c \
					gameplay.c \
					exit_game.c

SOURCES_DIR		=	sources
HEADER			=	$(SOURCES_DIR)/so_long.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
OBJECTS			= 	$(SOURCES:.c=.o)

NAME			=	so_long
CC				=	gcc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
MLX_FLAGS 		= 	-L./minilibx-linux -lmlx_Linux -lm -lXext -lX11

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJECTS) $(HEADER)
			make -C minilibx-linux
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

clean:
				make clean -C minilibx-linux
				$(MAKE) -C $(LIBFT_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re libft
