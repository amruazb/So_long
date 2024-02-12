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
size_t			ft_strlen(char *s);
t_dimensions	get_map_dimensions(char *filename);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_realloc(void *ptr, size_t newsize);
void 			get_map_array(char *filename, t_dimensions dimensions);



#endif

