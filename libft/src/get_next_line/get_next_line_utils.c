/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:17:14 by bade-lee          #+#    #+#             */
/*   Updated: 2022/03/08 15:12:37 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen_gnl(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	n;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (0);
		s1[0] = '\0';
	}
	result = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!result)
		return (0);
	i = -1;
	n = -1;
	while (s1[++i])
		result[i] = s1[i];
	while (s2[++n])
		result[i + n] = s2[n];
	result[ft_strlen_gnl(s1) + ft_strlen_gnl(s2)] = '\0';
	free(s1);
	return (result);
}
