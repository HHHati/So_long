/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Basile19 <Basile19@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:17:24 by bade-lee          #+#    #+#             */
/*   Updated: 2022/04/27 14:30:43 by Basile19         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//          ----------========== {   INCLUDES   } ==========----------

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stddef.h>
# include "libft.h"

//          ----------========== {    DEFINE    } ==========----------

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

//          ----------========== {  GNL  UTILS  } ==========----------

size_t	g_ft_strlen(char *s);
char	*ft_get_line(char *str);
char	*ft_update(char *str);

//          ----------========== {   GNL FCTS   } ==========----------

char	*ft_read(int fd, char *str);
char	*get_next_line(int fd);

#endif