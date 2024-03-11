/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabashee <aabashee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 04:19:43 by aabashee          #+#    #+#             */
/*   Updated: 2024/03/06 23:23:25 by aabashee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "./mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct s_game
{
	size_t	length;
	size_t	breadth;
	char	**map_array;
	size_t	player_x;
	size_t	player_y;
	size_t	num_of_collectibles;
	int		count;
	int		collect_n;
	void	*mlx;
	void	*win;
	int		player_position;
	char	*img_background;
	char	*img_wall;
	char	*img_exit;
	char	*img_collectible;
	char	*img_player;
	char	*img_player2;
	char	*img_player3;
	char	*img_player4;
	char	*img_player5;
	char	*img_player6;
	char	*img_player_left;
	char	*img_player_left2;
	char	*img_player_left3;
	char	*img_player_left4;
	char	*img_player_left5;
	char	*img_player_left6;
	int		move_count;
	int		end_game;
	int		img_width;
	int		img_height;
	char	**dup_map;
	bool	exit_found;
	size_t	collectibles_found;
}	t_game;

char	*ft_strtrim(char	const *s1, char const *set);
int		sub_find(char c, char const *set);
int		ft_printf(const char *format, ...);
int		berfile(char *s);
char	*get_next_line(int fd);
char	**ft_split(char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_realloc(void *ptr, size_t newsize);
size_t	ft_strlen(const char *s);
int		finda(char const *s1, char const *set);
void	init_struct(t_game **game);
t_game	*get_map_array(char *filename, t_game *game);
t_game	*get_map_dimensions(char *filename);
int		is_valid_map(t_game *map_array, t_game dimensions);
int		is_valid_character(char c);
int		is_valid_map_character_count(t_game *map_array, t_game dimensions);
void	is_map_char_helper(size_t *pl, size_t *ex, size_t *col, t_game *game);
int		is_valid_map_wall(t_game *map_array, t_game dimensions);
int		is_valid_map_structure(t_game *map_array, t_game dimensions);
void	get_player_position(t_game *game, char character);
void	get_number_of_collectibles(t_game *map_array, t_game dimensions);
void	graphical_interface(t_game *game);
void	load_images(t_game *game);
void	load_imagesto_load(t_game *game);
int		game_hook(int key_code, t_game *game);
int		img_put(t_game *game);
void	put_image(t_game *game, char *image);
void	ft_move_player(t_game *game, size_t x, size_t y);
int		finish(t_game *game);
void	printing(t_game *game);
bool	is_valid_path(t_game *map_array);
int		animate_player(t_game *game);
void	animate_help_function(t_game *game, int count);
void	animate_help_function2(t_game *game, int count);
void	*ft_memset(void *s, int c, size_t n);
bool	dfs(t_game *game, size_t x, size_t y, bool visited[][game->length]);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
