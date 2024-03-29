/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Basile19 <Basile19@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:17:14 by bade-lee          #+#    #+#             */
/*   Updated: 2022/04/27 14:23:42 by Basile19         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	g_ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_get_line(char *str)
{
	int		x;
	char	*line;

	x = 0;
	if (!str[x])
		return (NULL);
	while (str[x] && str[x] != '\n')
		x++;
	line = (char *)malloc(sizeof(char) * (x + 2));
	if (!line)
		return (NULL);
	x = 0;
	while (str[x] && str[x] != '\n')
	{
		line[x] = str[x];
		x++;
	}
	if (str[x] == '\n')
	{
		line[x] = str[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}

char	*ft_update(char *str)
{
	char	*line;
	int		a;
	int		b;

	a = 0;
	while (str[a] && str[a] != '\n')
		a++;
	if (!str[0])
	{
		free(str);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (g_ft_strlen(str) - a + 1));
	if (!line)
	{
		free(str);
		return (NULL);
	}
	a++;
	b = 0;
	while (str[a])
		line[b++] = str[a++];
	line[b] = '\0';
	free(str);
	return (line);
}
