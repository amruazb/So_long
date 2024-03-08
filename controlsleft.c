#include "so_long.h"

void	ft_move_player_left(t_game *game, size_t a, size_t b)
{

	// get_player_position(game, 'P');
		if (game->map_array[game->player_y + a][game->player_x+b] == 'E' && game->num_of_collectibles == 0)
		{
			game->map_array[game->player_y][game->player_x] = '0';
			game->move_count++;
			ft_printf("YOU WON !!!\n");
			finish(game);
		}
		else if (game->map_array[game->player_y + a][game->player_x+b] == 'E' && game->num_of_collectibles != 0)
			ft_printf("You need to collect all the collectibles before you can exit\n");
		else if (game->map_array[game->player_y + a][game->player_x+b] == '1')
			ft_printf("You can't move into a wall\n");
		else if (game->map_array[game->player_y + a][game->player_x+b] == '0' || game->map_array[game->player_y + a][game->player_x+b] == 'C')
		{
			if (game->map_array[game->player_y+a][game->player_x+b] == 'C')
				game->num_of_collectibles--;
			game->map_array[game->player_y + a][game->player_x+b] = 'P';
			game->map_array[game->player_y][game->player_x] = '0';
			game->move_count++;
			ft_printf("Move count: %d\n", game->move_count);
			game->player_y += a;
			game->player_x += b;
		}
}

int	img_put_left(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (game->map_array[i])
	{
		j = -1;
		while (game->map_array[i][++j])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_background,game->img_width * j, game->img_height * i);
			if (game->map_array[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall,game->img_width * j, game->img_height * i);
			else if (game->map_array[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win,game->img_background, game->img_width * j, game->img_height* i);
			else if (game->map_array[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit,game->img_width * j, game->img_height * i);
			else if (game->map_array[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,game->img_collectible, game->img_width * j, game->img_height* i);
			else if (game->map_array[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				animate_player(game);
			}
		}
		i++;
	}
	return (0);
}

void	load_images(t_game *game)
{
	game->img_width = 128;
	game->img_height = 128;
	game->img_background = mlx_xpm_file_to_image(game->mlx,"images/wall2.xpm", &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "images/fence.xpm",&game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,"images/exit_opened_door.xpm", &game->img_width, &game->img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,"images/tomato32.xpm", &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "images/bird1.xpm",&game->img_width, &game->img_height);
	game->img_player2 = mlx_xpm_file_to_image(game->mlx, "images/bird2.xpm",&game->img_width, &game->img_height);
	game->img_player3 = mlx_xpm_file_to_image(game->mlx, "images/bird3.xpm",&game->img_width, &game->img_height);
	game->img_player4 = mlx_xpm_file_to_image(game->mlx, "images/bird4.xpm",&game->img_width, &game->img_height);
	game->img_player5 = mlx_xpm_file_to_image(game->mlx, "images/bird5.xpm",&game->img_width, &game->img_height);
	game->img_player6 = mlx_xpm_file_to_image(game->mlx, "images/bird6.xpm",&game->img_width, &game->img_height);
	game->player_y = 0;
	game->player_x = 0;
	if(game->img_background == NULL)
	{
		ft_printf("Error: Could not load wall image\n");
		exit(0);
	}
}