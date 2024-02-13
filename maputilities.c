#include "so_long.h"

char **ft_split(char *s)
{
	int i = 0;
	int j = 0;
	int k;
	char **split = malloc(1024);
	while(s[i] == 32)
		i++;
	while(s[i])
	{
		if(s[i] > 32)
		{
			k = 0;
			split[j] = malloc(1024);
			while(s[i] > 32)
			{
				split[j][k++] = s[i++];
			}
			split[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	split[j] = 0;
	return split;
}

t_dimensions get_map_dimensions(char *filename)
{
    t_dimensions dimensions = {0, 0};
    int fd;
    char *line;
    size_t expected_length;
    size_t line_length;

    fd = open(filename,O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file\n");
		return dimensions;
	}
    while ((line = get_next_line(fd)))
    {
        line_length = ft_strlen(line);
        if (dimensions.breadth == 0)
            expected_length = line_length;
		else if (expected_length != line_length)
		{
			ft_printf("Error: Map file is not rectangular\n");
			free(line);
			close(fd);
			exit(1);
		}
		if (line_length > dimensions.length)
			dimensions.length = line_length;
		dimensions.breadth++;
		free(line);
	}
	close(fd);
	dimensions.length--;
	printf("Length: %zu\nBreadth: %zu\n", dimensions.length, dimensions.breadth);
    return dimensions;
}

size_t ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
        i++;
    return i;
}

int berfile(char *filename)
{
    char *fileextension;
   
   fileextension = ".ber";
    while(*filename)
    {
        if(*filename == *fileextension)
            fileextension++;
        filename++;
    }
    if(!*filename && !*fileextension)
        return 1;

    ft_printf("Error:It is Not a valid file extension!\n");
    usleep(1000000);
    ft_printf("Try a '.ber' file");
    return 0;
}
t_map *get_map_array(char *filename, t_dimensions dimensions)
{
	int fd;
	char *line;
	t_map *map = malloc(sizeof(t_map)* 1024);

	line = malloc(dimensions.length * dimensions.breadth);
	fd = open(filename, O_RDONLY);
	read(fd, line, dimensions.length * dimensions.breadth + dimensions.breadth);
	close(fd);
	map->map_array = ft_split(line);
	////
	char **tmp = map->map_array;
	while(*tmp)
		printf("%s\n",*tmp++);
	////
	return map; // final line
}

