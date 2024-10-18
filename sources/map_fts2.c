/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fts2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:21:58 by efaustin          #+#    #+#             */
/*   Updated: 2024/10/18 19:22:01 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_empty(char **map)
{
	if (!map || !map[0])
		return (1);
	return (0);
}

char	**dup_map(char **map)
{
	int		i;
	char	**new_map;

	i = 0;
	while (map[i])
		i++;
	new_map = malloc((i + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_map(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	fill_c(char **map, int y, int x, t_game *game)
{
	if (map[y][x] == 'C')
	{
		game->check = 1;
		game->clb_access++;
	}
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	fill_c(map, y, x - 1, game);
	fill_c(map, y, x + 1, game);
	fill_c(map, y - 1, x, game);
	fill_c(map, y + 1, x, game);
}
