#include "so_long.h"

void	image_free(t_game *game)
{
	if(game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if(game->img_background)
		mlx_destroy_image(game->mlx, game->img_background);
	if(game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if(game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if(game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	return ;
}