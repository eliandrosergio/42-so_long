#include "so_long.h"

int	is_map_empty(char **map)
{
	if (!map || !map[0])
		return (1);
	return (0);
}

char **dup_map(char **map)
{
	int i = 0;
	char **new_map;

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
