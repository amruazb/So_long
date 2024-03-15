/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabashee <aabashee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 04:15:20 by aabashee          #+#    #+#             */
/*   Updated: 2024/03/06 17:08:59 by aabashee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
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
	printf("Player position: %zu, %zu\n", game->player_x, game->player_y);
}

void	init_struct2(t_game **game)
{
	(*game)->img_collectible = NULL;
	(*game)->img_player = NULL;
	(*game)->img_player2 = NULL;
	(*game)->img_player3 = NULL;
	(*game)->img_player4 = NULL;
	(*game)->img_player5 = NULL;
	(*game)->img_player6 = NULL;
	(*game)->img_player_left = NULL;
	(*game)->img_player_left2 = NULL;
	(*game)->img_player_left3 = NULL;
	(*game)->img_player_left4 = NULL;
	(*game)->img_player_left5 = NULL;
	(*game)->img_player_left6 = NULL;
	(*game)->move_count = 0;
	(*game)->player_position = 0;
	(*game)->end_game = 0;
	(*game)->img_width = 0;
	(*game)->collect_n = 0;
	(*game)->img_height = 0;
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
	init_struct2(game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		ft_printf("Error: <usage> <so_long> <.ber-file>\n");
		return (0);
	}
	game = get_map_dimensions(av[1]);
	if (berfile(av[1]))
	{
		printf("Map Dimensions:\nLength: %zu\nBreadth: %zu\n", game->length,
			game->breadth);
		game = get_map_array(av[1], game);
		get_player_position(game, 'P');
		game->count = 0;
		get_number_of_collectibles(game, *game);
		if (!is_valid_map(game, *game))
		{
			printf("Error: Invalid map\n");
			return (0);
		}
		else
			printf("Map is valid\n");
		graphical_interface(game);
	}
}
