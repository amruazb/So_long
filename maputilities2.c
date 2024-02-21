#include "so_long.h"

int is_valid_character(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
	{
		ft_printf("Error: Invalid character in map\n");
		return 0;
	}
	return 1;
}

int is_valid_map_structure(t_game *map_array, t_game dimensions)
{
	size_t i = 0;
	size_t j = 0;
	while (i < dimensions.breadth)
	{
		j = 0;
		while (j < dimensions.length)
		{
			if (!is_valid_character(map_array->map_array[i][j]))
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

int is_valid_map_character_count(t_game *map_array, t_game dimensions)
{
	size_t exit = 0;
	size_t player = 0;
	size_t collectible = 0;
	size_t i = 0;
	size_t j = 0;
	while (i < dimensions.breadth)
	{
		j = 0;
		while (j < dimensions.length)
		{
			if(map_array->map_array[i][j] == 'P')
				player++;
			else if(map_array->map_array[i][j] == 'E')
				exit++;
			else if(map_array->map_array[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	if (exit != 1 || player != 1 || collectible < 1)
	{
		ft_printf("Error: Must have only 1 exit, 1 player and more than 1 collectibles\n");
		return 0;
	}
	return 1;
}

int is_valid_map_wall(t_game *map_array, t_game dimensions)
{
	size_t i = 0;

	while (i < dimensions.length)
	{
		if(map_array->map_array[0][i] != '1' || map_array->map_array[dimensions.breadth - 1][i] != '1')
			return 0;
		i++;
	}
	i = 0;
	while (i < dimensions.breadth)
	{
		if(map_array->map_array[i][0] != '1' || map_array->map_array[i][dimensions.length - 1] != '1')
			return 0;
		i++;
	}
	return 1;
}
int is_valid_map(t_game *map_array, t_game dimensions) 
{
	map_array->num_of_collectibles = get_number_of_collectibles(map_array, dimensions);
	if(!is_valid_map_wall(map_array, dimensions) || !is_valid_map_structure(map_array, dimensions) ||
		!is_valid_map_character_count(map_array, dimensions))
		//|| !dfs_is_valid_path(map_array, dimensions, 0, 0))
	{
        return 0;
    }
	return 1;
}
