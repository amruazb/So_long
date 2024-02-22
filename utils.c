#include "so_long.h"

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
