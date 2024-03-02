#include "so_long.h"

void get_player_position(t_game *map_array, char character)
{
	size_t i = 0;
	size_t j = 0;


	while (i < map_array->breadth)
	{
		j = 0;
		while (j < map_array->length)
		{
			if (map_array->map_array[i][j] == character)
			{
				map_array->player_x = j;
				map_array->player_y = i;
				return;
			}
			j++;
		}
		i++;
	}
}


void get_number_of_collectibles(t_game *map_array, t_game dimensions)
{
    size_t i = 0;
    size_t j = 0;
    size_t collectible = 0;

    while (i < dimensions.breadth)
    {
        j = 0;
        while (j < dimensions.length)
        {
            if (map_array->map_array[i][j] == 'C')
                collectible++;
            j++;
        }
        i++;
    }

    map_array->num_of_collectibles = collectible;
}

// void flood_fill(t_game *map_array, t_game dimensions, size_t x, size_t y)
// {
// 	if (x < 0 || x >= dimensions.breadth || y < 0 || y >= dimensions.length)
// 		return;
// 	if (map_array->map_array[x][y] == '1' || map_array->map_array[x][y] == 'E')
// 		return;
// 	if (map_array->map_array[x][y] == 'C')
// 	{
// 		map_array->map_array[x][y] = 'E';
// 		map_array->num_of_collectibles++;
// 	}
// 	flood_fill(map_array, dimensions, x + 1, y);
// 	flood_fill(map_array, dimensions, x - 1, y);
// 	flood_fill(map_array, dimensions, x, y + 1);
// 	flood_fill(map_array, dimensions, x, y - 1);
// }







