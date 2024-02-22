#include "so_long.h"

int main(int ac, char **av)
{
	t_game game;
    if(ac != 2)
    {
       ft_printf("Error: <usage> <so_long> <.ber-file>\n");
           return 0;
    }
       game = get_map_dimensions(av[1]);
    if (berfile(av[1]))
    {
		printf("Map Dimensions:\nLength: %zu\nBreadth: %zu\n",game.length,game.breadth);
		t_game *map_array = get_map_array(av[1], game);
		// while(*map_array->map_array)
		// {
		// 	printf("%s\n", *map_array->map_array);
		// 	map_array->map_array++;
		// }
		map_array->count = 0;
		map_array->num_of_collectibles = 0;
		if (is_valid_map(map_array, game))	
			ft_printf("map is valid\n");
		else
			ft_printf("not valid map\n");
        // printf("Map Dimensions:\nLength: %zu\nBreadth: %zu\n",dimensions.length,dimensions.breadth);
		get_player_position(map_array, game, 'P');
		printf("Player x: %zu\n", map_array->player_x);
		printf("Player y: %zu\n", map_array->player_y);
		// game.mlx = mlx_init();
		// game.win = mlx_new_window(game.mlx, game.length * 128, game.breadth * 128, "Falcon's So Long");
		// mlx_loop(game.mlx);
		map_array->breadth = game.breadth;
		map_array->length = game.length;
		graphical_interface(map_array);
		
	
		// (map->mlx, dimensions.length, dimensions.breadth, "Falcon's So Long");
		// graphical_interface(map_array,dimensions);
		// printf("Player x: %zu\n", map_array->player_x);
		// printf("Player y: %zu\n", map_array->player_y);
        // ft_printf("it is a valid .ber file\n");

    }
	
}

