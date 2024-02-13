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
    size_t length;
    size_t breadth;
}   t_dimensions;

typedef struct 
{
	char **map_array;

} t_map;

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
int				is_valid_path(t_map *map_array, t_dimensions dimensions, int x, int y);


#endif

