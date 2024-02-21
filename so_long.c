#include "so_long.h"

int main(int ac, char **av)
{
    if(ac != 2)
    {
       ft_printf("Error: <usage> <so_long> <.ber-file>\n");
           return 0;
    }
        t_game dimensions = get_map_dimensions(av[1]);
    if (berfile(av[1]))
    {
		printf("Map Dimensions:\nLength: %zu\nBreadth: %zu\n",dimensions.length,dimensions.breadth);
		t_game *map_array = get_map_array(av[1], dimensions);
		map_array->count = 0;
		map_array->num_of_collectibles = 0;
		if (is_valid_map(map_array, dimensions))	
			ft_printf("map is valid\n");
		else
			ft_printf("not valid map\n");
        printf("Map Dimensions:\nLength: %zu\nBreadth: %zu\n",dimensions.length,dimensions.breadth);
		get_player_position(map_array, dimensions, 'P');
	
		// (map->mlx, dimensions.length, dimensions.breadth, "Falcon's So Long");
		// graphical_interface(map_array,dimensions);
		// printf("Player x: %zu\n", map_array->player_x);
		// printf("Player y: %zu\n", map_array->player_y);
        // ft_printf("it is a valid .ber file\n");

    }
	
}

