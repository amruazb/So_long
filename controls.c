#include "so_long.h"	

void	ft_move_player(t_game *game, size_t a, size_t b)
{

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

