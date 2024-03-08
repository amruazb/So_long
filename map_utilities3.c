#include "so_long.h"

void get_player_position(t_game *game, char character)
{
	size_t i = 0;
	size_t j = 0;


	while (i < game->breadth)
	{
		j = 0;
		while (j < game->length)
		{
			if (game->map_array[i][j] == character)
			{
				game->player_x = j;
				game->player_y = i;
				return ;
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







