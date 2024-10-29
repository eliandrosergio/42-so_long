/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fts2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:02:48 by efaustin          #+#    #+#             */
/*   Updated: 2024/10/24 15:02:50 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_printf_colored(const char *color, const char *format)
{
	ft_printf(color);
	ft_printf(format);
	ft_printf("\033[0m");
}

int	tombstone_timer(t_game *game)
{
	while (game->counter < 228572)
	{
		if (game->counter % 57143 == 0 || game->counter == 0)
		{
			ft_printf("Tempo restante: ");
			ft_printf("\033[0;34m%d\033[0m", game->time);
			ft_printf(" segundos\n");
			game->time--;
		}
		game->counter++;
		return (0);
	}
	exit_game(game);
	return (0);
}
