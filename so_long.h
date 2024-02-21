#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

# include "./mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdarg.h>


# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124



typedef struct
{
	size_t length;//columns
    size_t breadth;//rows
	char **map_array;
	size_t player_x;
	size_t player_y;
	int	num_of_collectibles;
	int count;
	void *mlx;
	void *win;
	char *img_background;
	char *img_wall;
	char *img_exit;
	char *img_collectible;
	char *img_player;
	int move_count;
	int end_game;
} t_game;

int				ft_printf(const char *format,...);
int				berfile(char *s);
char			*get_next_line(int fd);
char			**ft_split(char *s);
int				ft_strcmp(const char *s1, const char *s2);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_realloc(void *ptr, size_t newsize);
size_t			ft_strlen(const char *s);
t_game			*get_map_array(char *filename, t_game dimensions);
t_game	get_map_dimensions(char *filename);

int				is_valid_map(t_game *map_array, t_game dimensions);
int				is_valid_character(char c);
int				is_valid_map_character_count(t_game *map_array, t_game dimensions);
int				is_valid_map_wall(t_game *map_array, t_game dimensions);
int				is_valid_map_structure(t_game *map_array, t_game dimensions);
int				get_number_of_collectibles(t_game *map_array, t_game dimensions);
t_game			*get_player_position(t_game *map_array, t_game dimensions, char character);
//void			add_images(t_game *mlx, t_game *map_array, t_game dimensions);

//int				dfs_is_valid_path(t_game *map_array1, t_game dimensions, size_t x, size_t y);
t_game		graphical_interface(t_game *map_array, t_game dimensions);

// void 			animate_birds(int keycode, void *param);
//int				key_controls(int keycode, t_game *map_array);

// void			move_player_left(t_game *map_array);
// void			move_player_down(t_game *map_array);
// void			move_player_right(t_game *map_array);
// void			move_player_up(t_game *map_array);


#endif

// void graphical_interface(t_game *map_array, t_game dimensions)
// {
//     void *mlx;
//     void *win;
//     void *background_img;
//     void *bird_sprites[6];
//     void *exit_img;
//     void *collectible_img;
//     // Initialize mlx and create a window
//     // Load the background image
//     background_img = mlx_xpm_file_to_image(mlx, "./images/wall/wall2.xpm", NULL, NULL);
//     exit_img = mlx_xpm_file_to_image(mlx, "./images/flybirds128/bird_exit.xpm", NULL, NULL);
//     collectible_img = mlx_xpm_file_to_image(mlx, "./images/collectables/tomato32.xpm", NULL, NULL);
//     // Load bird frames outside the loop
//     for (int i = 0; i < 6; i++)
//     {
//         char filename[50];
//         sprintf(filename, "./images/flybirds128/bird%d.xpm", i + 1);
//         bird_sprites[i] = mlx_xpm_file_to_image(mlx, filename, NULL, NULL);
//     }
//     size_t i = 0;
//     while (i < dimensions.breadth)
//     {
//         size_t j = 0;
//         while (j < dimensions.length)
//         {
//             mlx_put_image_to_window(mlx, win, background_img, j * 128, i * 128);
//             // Draw other game elements based on the map_array
//             if (map_array->map_array[i][j] == '1')
//             {
//                 mlx_put_image_to_window(mlx, win, background_img, j * 128, i * 128);
//             }
//             else if (map_array->map_array[i][j] == 'C')
//             {
//                 mlx_put_image_to_window(mlx, win, collectible_img, j * 128, i * 128);
//             }
//             else if (map_array->map_array[i][j] == 'P')
//             {
//                 // Use the current frame for bird animation
//                 mlx_put_image_to_window(mlx, win, bird_sprites[current_frame], j * 128, i * 128);
//             }
//             else if (map_array->map_array[i][j] == 'E')
//             {
//                 mlx_put_image_to_window(mlx, win, exit_img, j * 128, i * 128);
//             }
//             j++;
//         }
//         i++;
//     }
//     mlx_hook(win, 2, 1L << 0, key_controls, map_array);
//     mlx_loop(mlx);
// }