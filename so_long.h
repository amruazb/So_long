#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdarg.h>

typedef struct 
{
    size_t length;//columns
    size_t breadth;//rows
}   t_dimensions;

typedef struct 
{
	char **map_array;
	size_t player_x;
	size_t player_y;
	int	num_of_collectibles;
	int count;
} t_map;

typedef struct
{
	void *mlx;
	void *win;
}	t_mlx;

int				ft_printf(const char *format,...);
int				berfile(char *s);
char			*get_next_line(int fd);
char			**ft_split(char *s);
int				ft_strcmp(const char *s1, const char *s2);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_realloc(void *ptr, size_t newsize);
size_t			ft_strlen(const char *s);
t_map			*get_map_array(char *filename, t_dimensions dimensions);
t_dimensions	get_map_dimensions(char *filename);

int				is_valid_map(t_map *map_array, t_dimensions dimensions);
int				is_valid_character(char c);
int				is_valid_map_character_count(t_map *map_array, t_dimensions dimensions);
int				is_valid_map_wall(t_map *map_array, t_dimensions dimensions);
int				is_valid_map_structure(t_map *map_array, t_dimensions dimensions);
int				dfs_is_valid_path(t_map *map_array1, t_dimensions dimensions, size_t x, size_t y);
int				get_number_of_collectibles(t_map *map_array, t_dimensions dimensions);




#endif

