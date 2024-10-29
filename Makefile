NAME			=	so_long
NAME_BONUS		=	so_long_bonus

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS 		= 	-lm -lXext -lX11

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MINILIBX_PATH	=	./minilibx-linux
MINILIBX		=	$(MINILIBX_PATH)/libmlx_Linux.a

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

SOURCES_BONUS	=	main_bonus.c \
					draw_bonus.c \
					init_bonus.c \
					read_map_bonus.c \
					map_fts1_bonus.c \
					map_fts2_bonus.c \
					map_validate_bonus.c \
					player_update_bonus.c \
					gameplay_bonus.c \
					exit_game_bonus.c \
					moves_bonus.c \
					animation_bonus.c

SOURCES_DIR		=	sources
BONUS_DIR		=	sources_bonus

HEADER			=	$(SOURCES_DIR)/so_long.h
HEADER_BONUS	=	$(BONUS_DIR)/so_long_bonus.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
BONUS_FILES		=	$(addprefix $(BONUS_DIR)/, $(SOURCES_BONUS))

OBJECTS			= 	$(SOURCES:.c=.o)
OBJECTS_BONUS	= 	$(BONUS_FILES:.c=.o)

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(LIBFT) $(MINILIBX) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(NAME_BONUS):	$(LIBFT) $(MINILIBX) $(OBJECTS_BONUS) $(HEADER_BONUS)
				$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME_BONUS)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX):
				$(MAKE) -C $(MINILIBX_PATH)

clean:
				$(MAKE) -C $(MINILIBX_PATH) clean
				$(MAKE) -C $(LIBFT_PATH) clean
				$(RM) $(OBJECTS_BONUS)
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME_BONUS)
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all bonus clean fclean re libft minilibx
