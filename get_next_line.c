#include "so_long.h"

void	*ft_realloc(void *ptr, size_t newsize);
void	*ft_memcpy(void *dst, const void *src, size_t n);

char *get_next_line(int fd)
{
    int index = 0;
    int bytes;
    char *buffer;
    char *new_buffer;
   
   buffer = malloc(BUFFER_SIZE + 1);
    if ((fd < 0) || (BUFFER_SIZE <= 0) || (buffer == NULL))
        return NULL;
    while ((bytes = read(fd, &buffer[index], 1)) > 0)
    {
        if (buffer[index] == '\n')
        {
            buffer[index + 1] = '\0';  
            return buffer;
        }
        index++;
        if (index == BUFFER_SIZE)
        {
            new_buffer = ft_realloc(buffer, 2 * BUFFER_SIZE + 1);
            if (new_buffer == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }
    }
    if ((bytes <= 0) && (index == 0))
    {
        free(buffer);
        return NULL;
    }
    buffer[index] = '\0'; 
    return buffer;
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	while (n-- > 0)
	{
		*d++ = *s++;
	}
	return (dst);
}
void	*ft_realloc(void *ptr, size_t newsize)
{
	char	*newptr;
	size_t	cursize;

	if (ptr == 0)
		return (malloc(newsize));
	cursize = sizeof(ptr);
	if (newsize <= cursize)
		return (ptr);
	newptr = malloc(newsize);
	ft_memcpy(ptr, newptr, cursize);
	free(ptr);
	return (newptr);
}
/* int main()
{
    int fd = open("so_long.c", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    return 0;
} */

