/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:43:46 by agerbaud          #+#    #+#             */
/*   Updated: 2024/04/02 18:08:56 by agerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	b[1];

	count = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror(file), -1);
	while (read(fd, b, 1))
	{
		if (b[0] == '\n')
			count++;
	}
	close(fd);
	return (count);
}

void	free_gnl_error(char **map, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		free(map[i]);
	free(map);
}

char	**ft_reader(char *file)
{
	int		fd;
	int		lines;
	int		i;
	char	**map;

	i = -1;
	lines = count_lines(file);
	if (lines < 0)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * lines);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	while (++i < lines - 1)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			return (free_gnl_error(map, i), NULL);
		map[i][ft_strlen(map[i]) - 1] = 0;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
