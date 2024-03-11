/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabashee <aabashee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 04:30:44 by aabashee          #+#    #+#             */
/*   Updated: 2024/03/06 23:23:58 by aabashee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_character(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
	{
		ft_printf("Error: Invalid character in map\n");
		return (0);
	}
	return (1);
}

int	is_valid_map_structure(t_game *map_array, t_game dimensions)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (i < dimensions.breadth)
	{
		j = 0;
		while (j < dimensions.length)
		{
			if (!is_valid_character(map_array->map_array[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_map_character_count(t_game *map_array, t_game dimensions)
{
	size_t	exit;
	size_t	player;
	size_t	collectible;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	collectible = 0;
	player = 0;
	exit = 0;
	is_map_char_helper(&player, &exit, &collectible, map_array);
	if (exit != 1 || player != 1 || collectible < 1)
	{
		ft_printf("Error: 1 exit || 1 player || 1 collectibles\n");
		return (0);
	}
	return (1);
}

int	is_valid_map_wall(t_game *map_array, t_game dimensions)
{
	size_t	i;

	i = 0;
	while (i < dimensions.length)
	{
		if (map_array->map_array[0][i] != '1'
			|| map_array->map_array[dimensions.breadth - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < dimensions.breadth)
	{
		if (map_array->map_array[i][0] != '1'
			|| map_array->map_array[i][dimensions.length - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

bool	is_valid_path(t_game *game)
{
	bool	**visited;

	visited = malloc(sizeof(bool *) * (game->breadth + game->length));
	ft_memset(visited, false, sizeof(visited));
	game->exit_found = false;
	game->collectibles_found = 0;
	dfs(game, game->player_y, game->player_x, visited);
	return (game->exit_found
		&& (game->collectibles_found == game->num_of_collectibles));
}
