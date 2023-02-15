/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:56:26 by momaiouf          #+#    #+#             */
/*   Updated: 2023/02/15 19:55:48 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

int				ft_strlen(char const *str);	
char			*get_next_line(int fd);
char			*get_a_line(char *backup);
char    		*ft_strjoin(char const *s1, char const *s2);
void    		*ft_memcpy(void *dest, const void *src, size_t size);
char			*read_file(int fd, char *backup);
char			*get_next_buffer(char *backup, char *line);

#endif