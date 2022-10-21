/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-per <joao-per@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:07:38 by joao-per          #+#    #+#             */
/*   Updated: 2022/10/21 17:07:38 by joao-per         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*novo;
	int		i;

	i = 0;
	novo = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!novo)
		return (0);
	while (*s)
		novo[i++] = *s++;
	novo[i] = '\0';
	return (novo);
}