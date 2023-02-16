/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:56:26 by momaiouf          #+#    #+#             */
/*   Updated: 2023/02/16 20:46:37 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif


# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int				ft_strlen(char const *str);	
char			*get_next_line(int fd);
char			*get_a_line(char *backup);
char    		*ft_strjoin(char const *s1, char const *s2);
void    		*ft_memcpy(void *dest, const void *src, size_t size);
char			*read_file(int fd, char *backup);
char			*get_next_buffer(char *backup, char *line);

#endif