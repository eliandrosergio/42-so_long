#include "so_long.h"

void fill_e(char **map, int y, int x, int *found_exit)
{
	if (map[y][x] == 'E')
		*found_exit = 1;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return;
	map[y][x] = 'F';
	fill_e(map, y, x - 1, found_exit);
	fill_e(map, y, x + 1, found_exit);
	fill_e(map, y - 1, x, found_exit);
	fill_e(map, y + 1, x, found_exit);
}

void fill_c(char **map, int y, int x, int *found, int *clb_count)
{
	if (map[y][x] == 'C')
		(*clb_count)++;
	if (map[y][x] == 'E' || map[y][x] == 'C')
		*found = 1;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return;
	map[y][x] = 'F';
	fill_c(map, y, x - 1, found, clb_count);
	fill_c(map, y, x + 1, found, clb_count);
	fill_c(map, y - 1, x, found, clb_count);
	fill_c(map, y + 1, x, found, clb_count);
}

int	is_e_validate(char **map)
{
	int	i;
	int	j;
	int	found_exit;
	char **temp_map;

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

int	is_c_validate(char **map, t_game *game)
{
	int	i;
	int	j;
	int found;
	int c_count;
	char **temp_map;

	i = -1;
	found = 0;
	c_count = 0;
	temp_map = dup_map(map);
	while (temp_map[++i])
	{
		j = -1;
		while (temp_map[i][++j])
		{
			if (temp_map[i][j] == 'P')
			{
				fill_c(temp_map, i, j, &found, &c_count);
				free_map(temp_map);
				return (c_count == game->n_colect && found == 1);
			}
		}
	}
	free_map(temp_map);
	return (0);
}

int check_map_ec(t_game *game)
{
	if (!is_e_validate(game->map))
		return (0);
	if (!is_c_validate(game->map, game))
		return (0);
	return (1);
}
