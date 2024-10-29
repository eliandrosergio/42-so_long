/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:18:18 by efaustin          #+#    #+#             */
/*   Updated: 2024/10/24 14:18:21 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animation(t_game *game)
{
	if (game->loop < 10000)
	{
		game->loop++;
		return (0);
	}
	game->loop = 0;
	mlx_destroy_image(game->mlx, game->img_enemie);
	if (game->pos_enemies == 1)
		game->img_enemie = mlx_xpm_file_to_image
			(game->mlx, "assets/images/EN1.xpm", &game->img_w, &game->img_h);
	else if (game->pos_enemies == 2)
		game->img_enemie = mlx_xpm_file_to_image
			(game->mlx, "assets/images/EN2.xpm", &game->img_w, &game->img_h);
	else if (game->pos_enemies == 3)
		game->img_enemie = mlx_xpm_file_to_image
			(game->mlx, "assets/images/EN3.xpm", &game->img_w, &game->img_h);
	else if (game->pos_enemies == 4)
	{
		game->img_enemie = mlx_xpm_file_to_image
			(game->mlx, "assets/images/EN4.xpm", &game->img_w, &game->img_h);
		game->pos_enemies = 0;
	}
	map_draw(game);
	game->pos_enemies++;
	return (0);
}
