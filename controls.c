#include "so_long.h"	


void	update_player(t_game *game, int x, int y)
{
	if (game->map_array[game->player_y + y][game->player_x + x] == 'E')
	{
		if (game->num_of_collectibles == 0)
		{
			ft_printf("Game over\n");
			finish(game);
		}
	}
	if (game->map_array[game->player_y + y][game->player_x + x] == 'C')
	{
		game->num_of_collectibles--;
	}
	game->map_array[game->player_y][game->player_x] = '0';
	game->map_array[game->player_y + y][game->player_x + x] = 'P';
	game->player_x += x;
	game->player_y += y;
}

int is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->length || new_y < 0 || new_y >= game->breadth)
		return 0;
	if (game->map_array[new_y][new_x] == '1')
		return 0;
	return 1;
}


// void	ft_move_player(t_game *game, size_t a, size_t b)
// {
// 	size_t new_x = game->player_x + b;
//     size_t new_y = game->player_y + a;

// 	if (is_valid_move(game, new_x, new_y))
// 	{
// 		// Store the previous position of the player
// 		game->player_x = new_x;
// 		game->player_y = new_y;
// 		size_t prev_x = game->player_x;
// 		size_t prev_y = game->player_y;

// 		// Update the player's position
// 		game->player_x = new_x;
// 		game->player_y = new_y;

// 		// Check if the player won
// 		if (game->map_array[new_y][new_x] == 'E' && game->num_of_collectibles == 0)
// 		{
// 			game->map_array[new_y][new_x] = '0';
// 			game->move_count++;
// 			ft_printf("YOU WON !!!\n");
// 			// finish(game);
// 		}
// 		// Check if the player can continue
// 		else if (game->map_array[new_y][new_x] == 'E' && game->num_of_collectibles != 0)
// 		{
// 			ft_printf("You need to collect all the collectibles before you can exit\n");
// 			// Restore the player's position if needed
// 			game->player_x = prev_x;
// 			game->player_y = prev_y;
// 		}
// 		// Check if the player hit a wall
// 		else if (game->map_array[new_y][new_x] == '1')
// 		{
// 			ft_printf("You can't move into a wall\n");
// 			// Restore the player's position if needed
// 			game->player_x = prev_x;
// 			game->player_y = prev_y;
// 		}
// 		// Check if the player collected a coin or moved to an empty space
// 		else if (game->map_array[new_y][new_x] == '0' || game->map_array[new_y][new_x] == 'C')
// 		{
// 			if (game->map_array[new_y][new_x] == 'C')
// 				game->num_of_collectibles--;

// 			// Update the map after the player's move
// 			game->map_array[new_y][new_x] = 'P';
// 			game->map_array[prev_y][prev_x] = '0';

// 			game->move_count++;
// 			ft_printf("Move count: %d\n", game->move_count);
// 		}
// 	}

// }
void	ft_move_player(t_game *game, int x_offset, int y_offset)
{
    size_t new_x = game->player_x + x_offset;
    size_t new_y = game->player_y + y_offset;

    // Check if the new position is within the boundaries of the map
    if (new_x >= 0 && new_x < game->length && new_y >= 0 && new_y < game->breadth)
    {
        // Check if the new position is a valid move (empty space '0', collectible 'C', or exit 'E')
        if (game->map_array[new_y][new_x] == '0' || game->map_array[new_y][new_x] == 'C' || game->map_array[new_y][new_x] == 'E')
        {
            // Check if the new position is not a wall ('1')
            if (game->map_array[new_y][new_x] != '1')
            {
                // Update the player's position and handle collectibles/exits
                update_player(game, x_offset, y_offset);

                // Print the updated map
                printing(game);

                // Check if the player reached the exit after the move
                if (game->map_array[game->player_y][game->player_x] == 'E')
                {
                    if (game->num_of_collectibles == 0)
                    {
                        ft_printf("Congratulations! You've won!\n");
                        finish(game);
                    }
                }
            }
        }
    }
}
