/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:52:11 by joao-per          #+#    #+#             */
/*   Updated: 2023/01/25 12:52:11 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
// it's value is going to be the rest of the string that wasn't returned.
// FIX FOR VALGRIND after line 45 
//	if (ft_strlen(resto) == 0)
//        free(resto);
char	*get_next_line(int fd)
{
	static char	*resto;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	resto = read_line(fd, resto);
	if (!resto)
		return (NULL);
	line = ft_get_line(resto);
	resto = resto_da_str(resto);
	if (ft_strlen(resto) == 0)
        free(resto);
	return (line);
}

/* #include <unistd.h>
#include <fcntl.h>
int	main(void)
{
	char	*line;
	int	i;
	int	text1;

	text1 = open("test/test.txt", O_RDONLY);
	i = 1;

	while(i < 4)
	{
		line = get_next_line(text1);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(text1);
	return (0);
} */