/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabashee <aabashee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 04:27:40 by aabashee          #+#    #+#             */
/*   Updated: 2024/03/06 17:41:12 by aabashee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(t_game *game, char character)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (i < game->breadth)
	{
		j = 0;
		while (j < game->length)
		{
			if (game->map_array[i][j] == character)
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	get_number_of_collectibles(t_game *map_array, t_game dimensions)
{
	size_t	i;
	size_t	j;
	size_t	collectible;

	collectible = 0;
	j = 0;
	i = 0;
	while (i < dimensions.breadth)
	{
		j = 0;
		while (j < dimensions.length)
		{
			if (map_array->map_array[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	map_array->num_of_collectibles = collectible;
}

bool	dfs(t_game *game, size_t x, size_t y, bool visited[][game->length])
{
	if (x < 0 || x >= game->breadth || y < 0 || y >= game->length
		|| game->map_array[x][y] == '1' || visited[x][y])
		return (false);
	visited[x][y] = true;
	if (game->map_array[x][y] == 'E')
		game->exit_found = true;
	else if (game->map_array[x][y] == 'C')
		game->collectibles_found++;
	dfs(game, x + 1, y, visited);
	dfs(game, x - 1, y, visited);
	dfs(game, x, y + 1, visited);
	dfs(game, x, y - 1, visited);
	return (true);
}

int	is_valid_map(t_game *map_array, t_game dimensions)
{
	if (!is_valid_map_wall(map_array, dimensions))
		return (0);
	else if (!is_valid_map_structure(map_array, dimensions))
		return (0);
	else if (!is_valid_map_character_count(map_array, dimensions))
		return (0);
	else if (is_valid_path(map_array) == false)
		return (0);
	return (1);
}
