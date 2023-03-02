/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:56:26 by momaiouf          #+#    #+#             */
/*   Updated: 2023/03/02 17:28:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int					check_nbread_and_linebreak(char *str, int nb_read);
char				*read_file(int fd, char *backup);
char				*get_a_line(char *backup);
char				*get_next_line_start(char *backup);
char				*get_next_line(int fd);
size_t				get_index_linebreak(char *str);
size_t				get_len_line(char *str);
size_t				ft_strlen(char *str);
void				*ft_memcpy(void *dest, void *src, size_t size);
char				*ft_strjoin(char *s1, char *s2);

#endif
