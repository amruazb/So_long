#include "so_long.h"

t_map *get_charater_postion(t_map *map_array, t_dimensions dimensions, char character)
{
	t_map *map_array1 = map_array;
	size_t i = 0;
	size_t j = 0;
	while (i < dimensions.breadth)
	{
		j = 0;
		while (j < dimensions.length)
		{
			if (map_array1->map_array[i][j] == character)
			{
				map_array1->player_x = i;
				map_array1->player_y = j;
				return map_array1;
			}
			j++;
		}
		i++;
	}
	return NULL;
}
int get_number_of_collectibles(t_map *map_array, t_dimensions dimensions)
{
	size_t i = 0;
	size_t j = 0;
	size_t collectible = 0;
	while (i < dimensions.breadth)
	{
		j = 0;
		while (j < dimensions.length)
		{
			if(map_array->map_array[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	return collectible;
}

int dfs_is_valid_path(t_map *map_array1, t_dimensions dimensions, size_t x, size_t y)
{
    char **map_array_cpy = map_array1->map_array;
	t_map *map_cpy = map_array1;

	map_cpy =  get_charater_postion(map_array1, dimensions, 'P');
	x = map_cpy->player_x;
	y = map_cpy->player_y;

    // Base cases
    if (x < 0 || y < 0 || x >= dimensions.length || y >= dimensions.breadth || map_array_cpy[x][y] == '1')
        return -1;

    if (map_array_cpy[x][y] == 'E')
        return 1;
	if (map_array_cpy[x][y] == 'C')
	{
		map_cpy->count++;
		if (map_cpy->count == map_array1->num_of_collectibles)
			return 1;
	}


    // Mark the current cell as visited
	map_array_cpy[x][y] = '1';

    // Recursive DFS in all four directions
    if (dfs_is_valid_path(map_array1, dimensions, x + 1, y) == 1)
        return 1;
    if (dfs_is_valid_path(map_array1, dimensions, x, y + 1) == 1)
        return 1;
    if (dfs_is_valid_path(map_array1, dimensions, x - 1, y) == 1)
        return 1;
    if (dfs_is_valid_path(map_array1, dimensions, x, y - 1) == 1)
        return 1;

    return -1; // No valid path found from this cell
}

// int is_valid_path(t_map *map_array)
// {
//     t_dimensions start_position = {0, 0}; // Update with the actual starting position

//     int result = dfs_is_valid_path(game_map, start_position.length, start_position.breadth);

//     if (result == 1)
//         ft_printf("Valid path found!\n");
//     else
//         ft_printf("No valid path found!\n");

//     return result;
// }


