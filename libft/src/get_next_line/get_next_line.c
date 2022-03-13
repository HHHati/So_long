/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:17:21 by bade-lee          #+#    #+#             */
/*   Updated: 2022/03/08 15:33:21 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *s)
{
	char	*buffer;
	ssize_t	r;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	r = 1;
	while (r != 0 && !ft_strchr_gnl(s, '\n'))
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[r] = '\0';
		s = ft_strjoin_gnl(s, buffer);
	}
	free(buffer);
	return (s);
}

char	*ft_get_line(char *s)
{
	int		i;
	char	*line;

	if (!s[0])
		return (0);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_stat(char *s)
{
	char	*new;
	int		i;
	int		n;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (!s[i])
		return (ft_free(s));
	new = malloc(sizeof(char) * (ft_strlen_gnl(s) - i + 1));
	if (!new)
		return (ft_free(s));
	n = 0;
	i++;
	while (s[i] != '\0')
	{
		new[n] = s[i];
		i++;
		n++;
	}
	new[n] = '\0';
	free(s);
	return (new);
}

char	*ft_free(char *s)
{
	free(s);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	s = ft_read_line(fd, s);
	if (!s)
		return (0);
	line = ft_get_line(s);
	s = ft_new_stat(s);
	return (line);
}
