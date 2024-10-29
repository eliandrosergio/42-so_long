/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:15:11 by efaustin          #+#    #+#             */
/*   Updated: 2024/10/18 19:15:12 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, image, x * 32, y * 32);
}

static void	player_draw(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	img_draw(game, image, x, y);
}

static void	exit_draw(t_game *game, int x, int y)
{
	if (game->n_colect == 0 && game->exit_alter == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image
			(game->mlx, "assets/images/E2.xpm", &game->img_w, &game->img_h);
		game->exit_alter = 1;
	}
	img_draw(game, game->img_exit, x, y);
}

int	map_draw(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				img_draw(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				img_draw(game, game->img_backg, x, y);
			else if (game->map[y][x] == 'P')
				player_draw(game, game->img_player, x, y);
			else if (game->map[y][x] == 'C')
				img_draw(game, game->img_colect, x, y);
			else if (game->map[y][x] == 'E')
				exit_draw(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
