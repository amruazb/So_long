#include "so_long.h"

void	img_put(t_game *game, int i, int j)
{
	i = 0;
	game->player_y = 0;
	game->player_x = 0;
	printf("i = %d\n", i);
	printf("game->map_array[i] %s \n", game->map_array[i]);
	while (game->map_array[i])
	{
		j = -1;
		game->player_x = 0;
		while (game->map_array[i][++j])
		{
			printf("(%d %d)", j, i);
			if (game->map_array[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, game->player_x , game->player_y );
			else if (game->map_array[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_background, game->player_x , game->player_y);
			else if (game->map_array[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, game->player_x , game->player_y);
			else if (game->map_array[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, game->player_x , game->player_y);
			else if (game->map_array[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->player_x , game->player_y);
			game->player_x += 128;
		}
		i++;
		game->player_y += 128;
	}	
	// printf ("i = %d\n", i);
	
}

static void	load_images(t_game *game)
{
	printf("hii\n");
	game->img_width = 128;
	game->img_height = 128;
	game->img_background = mlx_xpm_file_to_image(game->mlx, "images/wall2.xpm", &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "images/fence.xpm", &game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "images/exit_opened_door.xpm", &game->img_width, &game->img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "images/tomato32.xpm", &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "images/bird1.xpm", &game->img_width, &game->img_height);
	if(game->img_background == NULL)
	{
		ft_printf("Error: Could not load wall image\n");
		exit(0);
	}
}



	// game->floor.img = mlx_xpm_file_to_image(game->mlx, "images/floor.xpm", &game->floor.width, &game->floor.height);
	// game->collectible.img = mlx_xpm_file_to_image(game->mlx, "images/collectible.xpm", &game->collectible.width, &game->collectible.height);
	// game->exit.img = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", &game->exit.width, &game->exit.height);
	// game->player.img = mlx_xpm_file_to_image(game->mlx, "images/player.xpm", &game->player.width, &game->player.height);
// }

// static void	draw_map(t_game *game)
// {
// 	size_t	x;
// 	size_t	y;

// 	y = 0;
// 	while (y < game->breadth)
// 	{
// 		x = 0;
// 		while (x < game->length)
// 		{
// 			// if (game->map_array[y][x] == '1')
// 			// 	mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * 128, y * 128);
// 			// else if (game->map_array[y][x] == '0')
// 			// 	mlx_put_image_to_window(game->mlx, game->win, game->floor.img, x * 128, y * 128);
// 			// else if (game->map_array[y][x] == 'C')
// 			// 	mlx_put_image_to_window(game->mlx, game->win, game->collectible.img, x * 128, y * 128);
// 			// else if (game->map_array[y][x] == 'E')
// 			// 	mlx_put_image_to_window(game->mlx, game->win, game->exit.img, x * 128, y * 128);
// 			// else if (game->map_array[y][x] == 'P')
// 			// 	mlx_put_image_to_window(game->mlx, game->win, game->player.img, x * 128, y * 128);
// 			x++;
// 		}
// 		y++;
// 	}

// }

// int game_hook(int keycode, t_game *game)
// {
// 	printf("keycode = %d\n", keycode);
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 		exit(0);
// 	}
// 	return (0);
// }

void	graphical_interface(t_game *game)
{
	printf("game->length = %zu \n", game->length);
	printf("game->breadth = %zu \n", game->breadth);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->length*128, game->breadth*128, "Falcon's So Long");

	printf("**********************\n");
	// draw_map(game);
	load_images(game);
	img_put(game, -1, -1);
	printf("**********************");
	// mlx_hook(game.win, 2, 1L << 0, game_hook, &game);
	// mlx_hook(game.win, 17, 1L << 0, finish, &map);

	mlx_loop(game->mlx);

}