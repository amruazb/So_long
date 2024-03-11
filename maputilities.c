/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabashee <aabashee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 03:47:47 by aabashee          #+#    #+#             */
/*   Updated: 2024/03/06 17:23:13 by aabashee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_split(char *s)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	split = malloc(sizeof(t_game) * 1024);
	j = 0;
	i = 0;
	while (s[i] < 32)
		i++;
	while (s[i])
	{
		if (s[i] > 32)
		{
			k = 0;
			split[j] = malloc(sizeof(t_game) * 1024);
			while (s[i] > 32)
				split[j][k++] = s[i++];
			split[j++][k] = '\0';
		}
		else
			i++;
	}
	split[j] = 0;
	return (split);
}

void	something(int fd, t_game **game)
{
	char	*line;
	size_t	expected_length;
	size_t	line_length;

	line = get_next_line(fd);
	while (line != NULL)
	{
		line = ft_strtrim(line, "\n");
		line_length = ft_strlen(line);
		if ((*game)->breadth == 0)
			expected_length = line_length;
		else if (expected_length != line_length)
		{
			ft_printf("Error: Map file is not rectangular\n");
			free(line);
			close(fd);
			exit(1);
		}
		if (line_length > (*game)->length)
			(*game)->length = line_length;
		(*game)->breadth++;
		free(line);
		line = get_next_line(fd);
	}
}

t_game	*get_map_dimensions(char *filename)
{
	t_game	*game;
	int		fd;
	char	*line;
	size_t	expected_length;
	size_t	line_length;

	game = malloc(sizeof(t_game));
	init_struct(&game);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file\n");
		return (game);
	}
	something(fd, &game);
	close(fd);
	return (game);
}

int	berfile(char *filename)
{
	const char	*extension;
	size_t		len;

	extension = ".ber";
	len = ft_strlen(extension);
	if (ft_strcmp(filename + ft_strlen(filename) - len, extension) == 0)
		return (1);
	ft_printf("Error: It is Not a valid file extension!\n");
	ft_printf("Try a '.ber' file");
	return (0);
}

t_game	*get_map_array(char *filename, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	line = malloc((game->length * game->breadth + game->breadth) + 1);
	fd = open(filename, O_RDONLY);
	i = read(fd, line, game->length * game->breadth + game->breadth);
	line[i] = '\0';
	close(fd);
	game->map_array = ft_split(line);
	game->dup_map = ft_split(line);
	free(line);
	return (game);
}
