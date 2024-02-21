#include "so_long.h"

// typedef struct
// {
// 	t_game dimensions;
// 	char **map_array;
// 	size_t player_x;
// 	size_t player_y;
// 	int	num_of_collectibles;
// 	int count;
// } t_map;

// typedef struct
// {
// 	void *mlx;
// 	void *win;
// 	char *exit_img_path;
// 	char *collectible_img_path;
// 	char *player_img_path;
// } t_mlx;



// void add_images(t_mlx *mlx, t_map *map_array, t_game dimensions)
// {
// 	//add a background image
// 	mlx->background_img_path = "./images/wall/wallnew.xpm";
	

// 	mlx->background_img_path = mlx_xpm_file_to_image(mlx->mlx, mlx->background_img_path, dimensions.length, dimensions.breadth);
// 	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->background_img_path, 0, 0);

// }


// t_map graphical_interface(t_map *map_array, t_game dimensions)
// {
// 	t_mlx *mlx = malloc(sizeof(t_mlx));
// 	mlx->mlx = mlx_init();
// 	mlx->win = mlx_new_window(mlx->mlx, dimensions.length, dimensions.breadth, "Falcon's So Long");
// 		add_images(mlx, map_array, dimensions);
// 	return (*map_array);
// }


// t_game *initialize_game(t_game *game)
// {
// 	game->mlx = malloc(sizeof(t_mlx));

