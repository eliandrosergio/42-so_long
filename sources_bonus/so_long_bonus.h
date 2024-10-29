/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:03:22 by efaustin          #+#    #+#             */
/*   Updated: 2024/10/24 15:03:24 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	void	*img_enemie;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_colect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		moves;
	int		endgame;
	int		check;
	int		clb_access;
	int		exit_alter;
	int		pos_enemies;
	int		loop;
	int		counter;
	int		time;
}	t_game;

# define KEY_ESC 65307
# define KEY_Q 113

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

void	img_draw(t_game *game, void *image, int x, int y);
int		map_draw(t_game *game);
void	game_init(t_game *game);
char	**read_map(char *path);
char	**dup_map(char **map);
int		is_map_empty(char **map);
int		map_checker(t_game *game);
int		check_map_ec(t_game *game);
void	gameplay(t_game *game);
void	player_w(t_game *game);
void	player_d(t_game *game);
void	player_s(t_game *game);
void	player_a(t_game *game);
int		exit_game(t_game *game);
void	display_moves(t_game *game);
int		animation(t_game *game);
int		tombstone_timer(t_game *game);
void	tombstone_draw(t_game *game);
void	free_map(char **map);
void	fill_c(char **map, int y, int x, t_game *game);
void	ft_printf_colored(const char *color, const char *format);

#endif
