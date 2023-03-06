/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:09:34 by joao-per          #+#    #+#             */
/*   Updated: 2023/03/06 10:41:24 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		i;
	int		text1;
	int		text2;
	int		text3;

	text1 = open("test/test.txt", O_RDONLY);
	text2 = open("test/test2.txt", O_RDONLY);
	text3 = open("test/test3.txt", O_RDONLY);
	i = 1;

	printf("||Test Number 1: Chorus||\n");
	while (i < 7)
	{
		line = get_next_line(text1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(text1);
	printf("\n\n||Test Number 2: Stanzas||\n");
	i = 1;
	while (i < 10)
	{
		line = get_next_line(text2);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(text2);
	printf("\n\n||Test Number 3: Null lines and spaces||\n");
	i = 1;
	while (i < 11)
	{
		line = get_next_line(text3);
		if (!line)
			printf("\n");
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(text3);

/* 	int text4;
	printf("\n\n||Test Number 4: Full Song||\n");
	text4 = open("test/test4.txt", O_RDONLY);
	i = 1;
	while (i < 39)
	{
		line = get_next_line(text4);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(text4); */
	return (0);
}
