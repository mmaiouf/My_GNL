/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:56:23 by momaiouf          #+#    #+#             */
/*   Updated: 2023/02/16 21:51:54 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*read_file(int fd, char *backup)
{
	int		nb_read;
	char	*buffer;
	
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return(NULL);
	nb_read = 1;
	while (nb_read)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		printf("nb_read : %d\n", nb_read);
	}
	return (buffer);
}

char	*get_a_line(char *backup)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (line == NULL)
		return (NULL);
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return(line);
}

char	*get_next_buffer(char *backup, char *line)
{
	int		i;
	int		j;
	int		len_previous_line;
	int		len_previous_file;
	char	*next_buffer;
	
	len_previous_line = ft_strlen(line);
	len_previous_file = ft_strlen(backup);
	i = len_previous_line;
	j = 0;
	next_buffer = malloc(sizeof(char) * (len_previous_file - len_previous_line) + 1);
	if (next_buffer == NULL)
		return (NULL);
	while(backup[i])
	{
		next_buffer[j] = backup[i];
		i++;
		j++;
	}
	next_buffer[j] = '\0';
	return (next_buffer);
}

char    *get_next_line(int fd)
{
    char        *line;
    static char    	*backup;

    backup = read_file(fd, backup);
    line = get_a_line(backup);
    backup = get_next_buffer(backup, line);
    return (line);
}
