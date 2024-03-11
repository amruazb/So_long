/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabashee <aabashee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 23:14:06 by aabashee          #+#    #+#             */
/*   Updated: 2024/03/06 23:22:56 by aabashee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_free(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_background)
		mlx_destroy_image(game->mlx, game->img_background);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	return ;
}

void	free_array(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->breadth)
	{
		free(game->map_array[i]);
		i++;
	}
	free(game->map_array);
	return ;
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
	ft_printf("Bye\n");
	exit(0);
}
