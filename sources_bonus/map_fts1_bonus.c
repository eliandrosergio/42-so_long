/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fts1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:02:42 by efaustin          #+#    #+#             */
/*   Updated: 2024/10/24 15:02:43 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_e(char **map, int y, int x, int *found_exit)
{
	if (map[y][x] == 'E')
		*found_exit = 1;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	fill_e(map, y, x - 1, found_exit);
	fill_e(map, y, x + 1, found_exit);
	fill_e(map, y - 1, x, found_exit);
	fill_e(map, y + 1, x, found_exit);
}

int	is_e_validate(char **map)
{
	int		i;
	int		j;
	int		found_exit;
	char	**temp_map;

	i = -1;
	found_exit = 0;
	temp_map = dup_map(map);
	while (temp_map[++i])
	{
		j = -1;
		while (temp_map[i][++j])
		{
			if (temp_map[i][j] == 'P')
			{
				fill_e(temp_map, i, j, &found_exit);
				free_map(temp_map);
				return (found_exit == 1);
			}
		}
	}
	free_map(temp_map);
	return (0);
}

int	check_clbs_access(char **map, int i, int j, t_game *game)
{
	char	**temp_map;

	game->check = 0;
	game->clb_access = 0;
	temp_map = dup_map(map);
	fill_c(temp_map, i, j, game);
	if (game->clb_access < game->n_colect)
	{
		free_map(temp_map);
		return (0);
	}
	else if (game->check == 1)
	{
		free_map(temp_map);
		return (1);
	}
	free_map(temp_map);
	return (0);
}

int	is_c_validate(char **map, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				return (check_clbs_access(map, i, j, game));
		}
	}
	return (0);
}

int	check_map_ec(t_game *game)
{
	if (!is_e_validate(game->map))
		return (0);
	if (!is_c_validate(game->map, game))
		return (0);
	return (1);
}
