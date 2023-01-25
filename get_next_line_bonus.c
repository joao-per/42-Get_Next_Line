/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:51:30 by joao-per          #+#    #+#             */
/*   Updated: 2023/01/25 12:51:30 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdio.h>

char	*read_line(int fd, char *line)
{
	char	*buff;
	int		size;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	size = 1;
	while (!ft_strchr(line, '\n') && size != 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[size] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

// the first "resto" is the full line but, when I = it to "resto_da_str",
// it's value is going to be the rest of the string that wasn't returned
char	*get_next_line(int fd)
{
	static char	*resto[4096];
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	resto[fd] = read_line(fd, resto[fd]);
	if (!resto[fd])
		return (NULL);
	line = ft_get_line(resto[fd]);
	resto[fd] = resto_da_str(resto[fd]);
	return (line);
}
