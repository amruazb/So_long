#include "so_long.h"


t_game game_dimensions = {
    .length = 0,
    .breadth = 0,
    .map_array = NULL,
    .player_x = 0,
    .player_y = 0,
    .num_of_collectibles = 0,
    .count = 0,
    .mlx = NULL,
    .win = NULL,
    .img_background = NULL,
    .img_wall = NULL,
    .img_exit = NULL,
    .img_collectible = NULL,
    .img_player = NULL,
    .move_count = 0,
    .end_game = 0,
    .img_width = 0,
    .img_height = 0
};

char **ft_split(char *s)
{
	int i = 0;
	int j = 0;
	int k;
	char **split = malloc(sizeof(t_game) * 1024);
	while(s[i] == 32)
		i++;
	while(s[i])
	{
		if(s[i] > 32)
		{
			k = 0;
			split[j] = malloc(sizeof(t_game) * 1024);
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

t_game *get_map_dimensions(char *filename)
{
    t_game *game;

	game = malloc(sizeof(t_game));
    int fd;
    char *line;
    size_t expected_length;
    size_t line_length;

    fd = open(filename,O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file\n");
		return (game);
	}
	init_struct(&game);
    while ((line = get_next_line(fd)))
    {

		line = ft_strtrim(line, "\n");
        line_length = ft_strlen(line);
        if (game->breadth == 0)
       	{     
		expected_length = line_length;
	   	}
		else if (expected_length != line_length)
		{
			ft_printf("Error: Map file is not rectangular\n");
			free(line);
			close(fd);
			exit(1);
		}
		if (line_length > game->length)
			game->length = line_length;
		game->breadth++;
		free(line);
	}
	close(fd);
    return (game);
}

int berfile(char *filename)
{
    const char *extension = ".ber";
    size_t len = ft_strlen(extension);
    if (ft_strcmp(filename + ft_strlen(filename) - len, extension) == 0)
        return 1;
    ft_printf("Error: It is Not a valid file extension!\n");
    ft_printf("Try a '.ber' file");
    return 0;
}


t_game *get_map_array(char *filename, t_game *game)
{
	
	int fd;
	int i;
	char *line;
	line = malloc((game->length * game->breadth + game->breadth) + 1);
	fd = open(filename, O_RDONLY);
	i = read(fd, line, game->length * game->breadth + game->breadth);
	line[i] = '\0';
	close(fd);
	game->map_array = ft_split(line);
	game->dup_map = ft_split(line);
	free(line);
	return game;
}

