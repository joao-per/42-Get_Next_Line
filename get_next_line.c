/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:25:45 by joao-per          #+#    #+#             */
/*   Updated: 2023/02/23 21:25:45 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	resto[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || FOPEN_MAX < fd)
		return (NULL);
	line = NULL;
	while (resto[fd][0] || read(fd, resto[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, resto[fd]);
		if (ft_strlen(resto[fd]) == 0)
			return (line);
		if (find_nl_clean(resto[fd]) == 1)
			break ;
		if (read(fd, resto[fd], 0) < 0)
		{
			free (line);
			return (NULL);
		}
	}
	return (line);
}
