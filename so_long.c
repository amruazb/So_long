#include "so_long.h"

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

int game_hook(int keycode, t_game *game)
{
    printf("game_hook\n");
    printing(game);

    // Get the current player position
    // int current_x = (int)game->player_x;
    // int current_y = (int)game->player_y;

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
        printf("keycode = %d\n", keycode);
        ft_move_player(game, 0, -1);
    }
    else if (keycode == 2 || keycode == 124)
    {
        printf("keycode = %d\n", keycode);
        ft_move_player(game, 0, 1);
    }

    if (keycode == 53)
    {
        printf("Bye\n");
        // finish(game);
    }

    // img_put(game);
    return (0);
}


int	img_put(t_game *game)
{
	int i;
	int j;
	game->player_y = 0;
	game->player_x = 0;
	i = 0;
	j = -1;
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
				mlx_put_image_to_window(game->mlx, game->win, game->img_player,	game->img_width * j, game->img_height * i);
		}
		i++;
	}
	return (0);
}

void	load_images(t_game *game)
{
	printing(game);
	printf("\n\n-------------Loading images\n");
	game->img_width = 128;
	game->img_height = 128;
	game->img_background = mlx_xpm_file_to_image(game->mlx,"images/wall2.xpm", &game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "images/fence.xpm",&game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,"images/exit_opened_door.xpm", &game->img_width, &game->img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,"images/tomato32.xpm", &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "images/bird1.xpm",&game->img_width, &game->img_height);
	if(game->img_background == NULL)
	{
		ft_printf("Error: Could not load wall image\n");
		exit(0);
	}
	printf("Loading images completed\n");
}

void	graphical_interface(t_game *game)
{
	printf("game->length = %zu \n", game->length);
	printf("game->breadth = %zu \n", game->breadth);
	printf("\n\n********grap interface***************\n\n");
	printing(game);
	printf("\n\n********grap interface***************\n\n");
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->length * 128, game->breadth
			* 128, "Falcon's So Long");
	load_images(game);
	img_put(game);
	printf("***********************img_put_finished\n");
	mlx_hook(game->win, 2, 1L << 0, game_hook, game);
	printf("***********************mlx hook\n");
	mlx_hook(game->win, 17, 1L << 0, finish, &game);
	// printf("***********************finish\n");
	mlx_loop(game->mlx);
	// printf("**********************loop*\n");
	return ;
}

void	printing(t_game *game)
{
	int	i;

	printf("Map_array :\n");
	i = 0;
	while (game->map_array[i])
	{
		printf("%s\n", game->map_array[i]);
		i++;
	}
	printf("Map_dimensions:\n");
	printf("Length: %zu\nBreadth: %zu\n", game->length, game->breadth);
	printf("Number of collectibles: %zu\n", game->num_of_collectibles);
	// printf("Number of exits: %d\n",game->num_of_exits);
	printf("Player position: %zu, %zu\n", game->player_x, game->player_y);
}

void	init_struct(t_game **game)
{
	(*game)->length = 0;
	(*game)->breadth = 0;
	(*game)->map_array = NULL;
	(*game)->player_x = 0;
	(*game)->player_y = 0;
	(*game)->num_of_collectibles = 0;
	(*game)->count = 0;
	(*game)->mlx = NULL;
	(*game)->win = NULL;
	(*game)->img_background = NULL;
	(*game)->img_wall = NULL;
	(*game)->img_exit = NULL;
	(*game)->img_collectible = NULL;
	(*game)->img_player = NULL;
	(*game)->move_count = 0;
	(*game)->end_game = 0;
	(*game)->img_width = 0;
	(*game)->img_height = 0;
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		ft_printf("Error: <usage> <so_long> <.ber-file>\n");
		return (0);
	}
	// init_struct(&game);
	game = get_map_dimensions(av[1]);
	if (berfile(av[1]))
	{
		printf("Map Dimensions:\nLength: %zu\nBreadth: %zu\n", game->length,
			game->breadth);
		game = get_map_array(av[1], game);
		game->count = 0;
		get_number_of_collectibles(game, *game);
		if (!is_valid_map(game, *game))
			printf("Error: Invalid map\n");
		else
			printf("Map is valid\n");
		get_player_position(game, 'P');
		printing(game);
		graphical_interface(game);
		mlx_hook(game->win, 2, 1L << 0, game_hook, &game);
		printf("***********************mlx hook\n");
		mlx_hook(game->win, 17, 1L << 0, finish, &game);
		mlx_loop_hook(game->mlx, img_put, &game);
		printf("***********************finish\n");
		mlx_loop(game->mlx);
	}
}
