#include "so_long.h"

int game_hook(int keycode, t_game *game)
{
    if (keycode == 13 || keycode == 126)
    {
        printf("keycode = %d\n", keycode);
        ft_move_player(game, -1, 0);
    }
    else if (keycode == 1 || keycode == 125)
    {
        printf("keycode = %d\n", keycode);
        ft_move_player(game, 1, 0);
    }
    else if (keycode == 0 || keycode == 123)
    {
		game->player_position = 1;
        printf("keycode = %d\n", keycode);
        ft_move_player(game, 0, -1);
    }
    else if (keycode == 2 || keycode == 124)
    {
		game->player_position = 0;
        printf("keycode = %d\n", keycode);
        ft_move_player(game, 0, 1);
    }

    if (keycode == 53)
    {
        printf("Bye\n");
        finish(game);
    }

    img_put(game);
    return (0);
}

int	finish(t_game *game)
{
	int	i;

	if (game->map_array)
	{
		i = 0;
		while (game->map_array[i])
			free(game->map_array[i++]);
		free(game->map_array);
	}
	// image_free(game);
	// free_stack(&game->
	ft_printf("Bye\n");
	exit(0);
}


int animate_player(t_game *game)
{
	static int count;
	if (count < 10)
	{
		if (game->player_position == 1)
			mlx_put_image_to_window(game->mlx, game->win, game->img_player_left, game->img_width * game->player_x, game->img_height * game->player_y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_player,	game->img_width * game->player_x, game->img_height * game->player_y);
	}
	else if (count <= 15)
	{
		if (game->player_position == 1)
			mlx_put_image_to_window(game->mlx, game->win, game->img_player_left2, game->img_width * game->player_x, game->img_height * game->player_y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_player2, game->img_width * game->player_x, game->img_height * game->player_y);
	}
	else if (count <= 20)
	{
		if (game->player_position == 1)
			mlx_put_image_to_window(game->mlx, game->win, game->img_player_left3, game->img_width * game->player_x, game->img_height * game->player_y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_player3, game->img_width * game->player_x, game->img_height * game->player_y);
	}
	else if (count <= 25)
	{
		if (game->player_position == 1)
			mlx_put_image_to_window(game->mlx, game->win, game->img_player_left4, game->img_width * game->player_x, game->img_height * game->player_y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_player4, game->img_width * game->player_x, game->img_height * game->player_y);
	}
	else if (count <= 30)
	{
		if (game->player_position == 1)
			mlx_put_image_to_window(game->mlx, game->win, game->img_player_left5, game->img_width * game->player_x, game->img_height * game->player_y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_player5, game->img_width * game->player_x, game->img_height * game->player_y);
	}
	else if (count <= 35)
	{
		if (game->player_position == 1)
			mlx_put_image_to_window(game->mlx, game->win, game->img_player_left6, game->img_width * game->player_x, game->img_height * game->player_y);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_player6, game->img_width * game->player_x, game->img_height * game->player_y);
	}
	count++;
	if (count == 35)
		count = 0;
	return (0);
}


int	img_put(t_game *game)
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
	game->img_player_left = mlx_xpm_file_to_image(game->mlx, "images/parrotleftxpm/parrotleft1.xpm",&game->img_width, &game->img_height);
	game->img_player_left2 = mlx_xpm_file_to_image(game->mlx, "images/parrotleftxpm/parrotleft2.xpm",&game->img_width, &game->img_height);
	game->img_player_left3 = mlx_xpm_file_to_image(game->mlx, "images/parrotleftxpm/parrotleft3.xpm",&game->img_width, &game->img_height);
	game->img_player_left4 = mlx_xpm_file_to_image(game->mlx, "images/parrotleftxpm/parrotleft4.xpm",&game->img_width, &game->img_height);
	game->img_player_left5 = mlx_xpm_file_to_image(game->mlx, "images/parrotleftxpm/parrotleft5.xpm",&game->img_width, &game->img_height);
	game->img_player_left6 = mlx_xpm_file_to_image(game->mlx, "images/parrotleftxpm/parrotleft6.xpm",&game->img_width, &game->img_height);
	game->player_y = 0;
	game->player_x = 0;
	if(game->img_background == NULL)
	{
		ft_printf("Error: Could not load wall image\n");
		exit(0);
	}
}

void	graphical_interface(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->length * 128, game->breadth * 128, "Falcon's So Long");
	load_images(game);
	img_put(game);
	mlx_hook(game->win, 2, 1L << 0, game_hook, game);
	mlx_hook(game->win, 17, 1L << 0, finish, &game);
	mlx_loop_hook(game->mlx, img_put, game);
	mlx_loop(game->mlx);
	return ;
}