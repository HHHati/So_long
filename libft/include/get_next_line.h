/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bade-lee <bade-lee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:17:24 by bade-lee          #+#    #+#             */
/*   Updated: 2022/03/13 13:52:27 by bade-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//          ----------========== {   INCLUDES   } ==========----------

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stddef.h>

//          ----------========== {    DEFINE    } ==========----------

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

//          ----------========== {  GNL  UTILS  } ==========----------

char	*ft_strchr_gnl(char *s, int c);
size_t	ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);

//          ----------========== {   GNL FCTS   } ==========----------

char	*ft_read_line(int fd, char *s);
char	*ft_get_line(char *s);
char	*ft_new_stat(char *s);
char	*ft_free(char *s);
char	*get_next_line(int fd);

#endif