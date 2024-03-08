#include "so_long.h"

int is_valid_character(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
	{
		ft_printf("Error: Invalid character in map\n");
		return 0;
	}
	return 1;
}

int is_valid_map_structure(t_game *map_array, t_game dimensions)
{
	size_t i = 0;
	size_t j = 0;
	while (i < dimensions.breadth)
	{
		j = 0;
		while (j < dimensions.length)
		{
			if (!is_valid_character(map_array->map_array[i][j]))
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

int is_valid_map_character_count(t_game *map_array, t_game dimensions)
{
	size_t exit = 0;
	size_t player = 0;
	size_t collectible = 0;
	size_t i = 0;
	size_t j = 0;
	while (i < dimensions.breadth)
	{
		j = 0;
		while (j < dimensions.length)
		{
			if(map_array->map_array[i][j] == 'P')
				player++;
			else if(map_array->map_array[i][j] == 'E')
				exit++;
			else if(map_array->map_array[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	if (exit != 1 || player != 1 || collectible < 1)
	{
		ft_printf("Error: Must have only 1 exit, 1 player and more than 1 collectibles\n");
		return 0;
	}
	return 1;
}

int is_valid_map_wall(t_game *map_array, t_game dimensions)
{
	size_t i = 0;

	while (i < dimensions.length)
	{
		if(map_array->map_array[0][i] != '1' || map_array->map_array[dimensions.breadth - 1][i] != '1')
			return 0;
		i++;
	}
	i = 0;
	while (i < dimensions.breadth)
	{
		if(map_array->map_array[i][0] != '1' || map_array->map_array[i][dimensions.length - 1] != '1')
			return 0;
		i++;
	}
	return 1;
}

bool dfs(t_game *game, size_t x, size_t y, bool visited[][game->length]) 
{
	if (x < 0 || x >= game->breadth || y < 0 || y >= game->length || game->map_array[x][y] == '1' || visited[x][y]) 
		return false;
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


bool is_valid_path(t_game *game) 
{
	bool visited[game->breadth][game->length];

	memset(visited, false, sizeof(visited));
	game->exit_found = false;
	game->collectibles_found = 0;
	dfs(game, game->player_y, game->player_x, visited);
	return game->exit_found && (game->collectibles_found == game->num_of_collectibles);
}


int is_valid_map(t_game *map_array, t_game dimensions) 
{
	if(!is_valid_map_wall(map_array, dimensions))
		return 0;
	else if(!is_valid_map_structure(map_array, dimensions))
		return 0;
	else if(!is_valid_map_character_count(map_array, dimensions))
		return 0;
	else if (is_valid_path(map_array) == false)
		return 0;
	return (1);
}
