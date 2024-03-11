/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabashee <aabashee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 04:49:48 by aabashee          #+#    #+#             */
/*   Updated: 2024/03/06 23:13:32 by aabashee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"	

void	ft_move_player(t_game *game, size_t a, size_t b)
{
	if (game->map_array[game->player_y + a][game->player_x + b] == 'E'
		&& game->num_of_collectibles == 0)
	{
		game->map_array[game->player_y][game->player_x] = '0';
		game->move_count++;
		ft_printf("YOU WON !!!\n");
		finish(game);
	}
	else if (game->map_array[game->player_y + a][game->player_x + b] == 'E'
		&& game->num_of_collectibles != 0)
		ft_printf("You need to collect all the collectibles before you exit\n");
	else if (game->map_array[game->player_y + a][game->player_x + b] == '1')
		ft_printf("You can't move into a wall\n");
	else if (game->map_array[game->player_y + a][game->player_x + b] == '0'
		|| game->map_array[game->player_y + a][game->player_x + b] == 'C')
	{
		if (game->map_array[game->player_y + a][game->player_x + b] == 'C')
			game->num_of_collectibles--;
		game->map_array[game->player_y + a][game->player_x + b] = 'P';
		game->map_array[game->player_y][game->player_x] = '0';
		game->move_count++;
		ft_printf("Move count: %d\n", game->move_count);
		game->player_y += a;
		game->player_x += b;
	}
}

int	game_hook(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 126)
	{
		ft_move_player(game, -1, 0);
	}
	else if (keycode == 1 || keycode == 125)
	{
		ft_move_player(game, 1, 0);
	}
	else if (keycode == 0 || keycode == 123)
	{
		game->player_position = 1;
		ft_move_player(game, 0, -1);
	}
	else if (keycode == 2 || keycode == 124)
	{
		game->player_position = 0;
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

void	animate_help_function2(t_game *game, int count)
{
	if (count <= 35)
	{
		if (game->player_position == 1)
			put_image(game, game->img_player_left6);
		else
			put_image(game, game->img_player6);
	}
}

void	animate_help_function(t_game *game, int count)
{
	if (count <= 20)
	{
		if (game->player_position == 1)
			put_image(game, game->img_player_left3);
		else
			put_image(game, game->img_player3);
	}
	else if (count <= 25)
	{
		if (game->player_position == 1)
			put_image(game, game->img_player_left4);
		else
			put_image(game, game->img_player4);
	}
	else if (count <= 30)
	{
		if (game->player_position == 1)
			put_image(game, game->img_player_left5);
		else
			put_image(game, game->img_player5);
	}
	else
		animate_help_function2(game, count);
}

void	load_imagesto_load(t_game *game)
{
	game->img_background = mlx_xpm_file_to_image(game->mlx, "images/wall2.xpm",
			&game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "images/fence.xpm",
			&game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"images/exit_opened_door.xpm", &game->img_width, &game->img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"images/tomato32.xpm", &game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "images/bird1.xpm",
			&game->img_width, &game->img_height);
	game->img_player2 = mlx_xpm_file_to_image(game->mlx, "images/bird2.xpm",
			&game->img_width, &game->img_height);
	game->img_player3 = mlx_xpm_file_to_image(game->mlx, "images/bird3.xpm",
			&game->img_width, &game->img_height);
	game->img_player4 = mlx_xpm_file_to_image(game->mlx, "images/bird4.xpm",
			&game->img_width, &game->img_height);
	game->img_player5 = mlx_xpm_file_to_image(game->mlx, "images/bird5.xpm",
			&game->img_width, &game->img_height);
	game->img_player6 = mlx_xpm_file_to_image(game->mlx, "images/bird6.xpm",
			&game->img_width, &game->img_height);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx,
			"images/parrotleftxpm/parrotleft1.xpm", &game->img_width,
			&game->img_height);
}
