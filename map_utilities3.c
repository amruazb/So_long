#include "so_long.h"

t_map *get_player_position(t_map *map_array, t_dimensions dimensions, char character)
{
    t_map *map_array1 = malloc(sizeof(t_map));
    map_array1->map_array = map_array->map_array;
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
                printf("Player x: %zu\n", map_array1->player_x);
				printf("Player y: %zu\n", map_array1->player_y);
                return map_array1; // return the pointer to the updated structure
            }
            j++;
        }
        i++;
    }
    printf("Player not found\n");
    free(map_array1); // free the memory if the player is not found
    return NULL;
}

// void flood_fill(t_map *map_array, t_dimensions dimensions, size_t x, size_t y)
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







