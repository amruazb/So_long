/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphicsadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabashee <aabashee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 04:43:29 by aabashee          #+#    #+#             */
/*   Updated: 2024/03/06 23:13:04 by aabashee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	animate_player(t_game *game)
{
	static int	count;

	if (count < 10)
	{
		if (game->player_position == 1)
			put_image(game, game->img_player_left);
		else
			put_image(game, game->img_player);
	}
	else if (count <= 15)
	{
		if (game->player_position == 1)
			put_image(game, game->img_player_left2);
		else
			put_image(game, game->img_player2);
	}
	else
		animate_help_function(game, count);
	count++;
	if (count == 35)
		count = 0;
	return (0);
}

void	put_image_to_window(t_game *game, int i, int j)
{
	if (game->map_array[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
			game->img_width * j, game->img_height * i);
	else if (game->map_array[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_background, game->img_width * j,
			game->img_height * i);
	else if (game->map_array[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit, game->img_width * j,
			game->img_height * i);
	else if (game->map_array[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_collectible, game->img_width * j,
			game->img_height * i);
	else if (game->map_array[i][j] == 'P')
	{
		game->player_x = j;
		game->player_y = i;
		animate_player(game);
	}
}

int	img_put(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_array[i])
	{
		j = -1;
		while (game->map_array[i][++j])
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_background, game->img_width * j,
				game->img_height * i);
			put_image_to_window(game, i, j);
		}
		i++;
	}
	return (0);
}

void	load_images(t_game *game)
{
	game->img_width = 128;
	game->img_height = 128;
	load_imagesto_load(game);
	game->img_player_left2 = mlx_xpm_file_to_image(game->mlx,
			"images/parrotleftxpm/parrotleft2.xpm", &game->img_width,
			&game->img_height);
	game->img_player_left3 = mlx_xpm_file_to_image(game->mlx,
			"images/parrotleftxpm/parrotleft3.xpm", &game->img_width,
			&game->img_height);
	game->img_player_left4 = mlx_xpm_file_to_image(game->mlx,
			"images/parrotleftxpm/parrotleft4.xpm", &game->img_width,
			&game->img_height);
	game->img_player_left5 = mlx_xpm_file_to_image(game->mlx,
			"images/parrotleftxpm/parrotleft5.xpm", &game->img_width,
			&game->img_height);
	game->img_player_left6 = mlx_xpm_file_to_image(game->mlx,
			"images/parrotleftxpm/parrotleft6.xpm", &game->img_width,
			&game->img_height);
	game->player_y = 0;
	game->player_x = 0;
	if (game->img_background == NULL)
	{
		ft_printf("Error: Could not load wall image\n");
		exit(0);
	}
}

void	graphical_interface(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->length * 128,
			game->breadth * 128, "Falcon's So Long");
	load_images(game);
	img_put(game);
	mlx_hook(game->win, 2, 1L << 0, game_hook, game);
	mlx_hook(game->win, 17, 1L << 0, finish, &game);
	mlx_loop_hook(game->mlx, img_put, game);
	mlx_loop(game->mlx);
	return ;
}
