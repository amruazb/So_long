#include "so_long.h"

size_t ft_strlen(const char *s)
{
    int i = 0;
    while(s[i])
        i++;
    return i;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while(*s1 && (*s1 == *s2))
	{
		s1++;
	       	s2++;
	}
	return (*s1 - *s2);
}

void *ft_realloc(void *ptr, size_t newsize)
{
    char *newptr;
    size_t cursize;
    if (ptr == NULL)
        return malloc(newsize);
    cursize = sizeof(ptr);
    if (newsize <= cursize)
        return ptr;
    newptr = malloc(newsize);
	size_t i = 0;
	while(i < cursize) 
    {
        ((char *)newptr)[i] = ((char *)ptr)[i];
			i++;
    }
    free(ptr);
    return newptr;
}
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	uc;

	uc = c;
	ptr = s;
	while (n-- > 0)
		*ptr++ = uc;
	return (s);
}