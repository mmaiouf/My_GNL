/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:56:23 by momaiouf          #+#    #+#             */
/*   Updated: 2023/02/19 22:31:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*read_file(int fd, char *backup)
{
	int		nb_read;
	char	*buffer;
	
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	backup = 0;
	if (buffer == NULL)
		return(NULL);
	nb_read = 1;
	while (nb_read)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		buffer[nb_read] = '\0';
		backup = ft_strjoin(backup, buffer);
		printf("buffer : %s\n", buffer);
		printf("backup : %s\n\n\n", backup);
		//printf("nb_read : %d\n", nb_read);
	}
	free(buffer);
	return (backup);
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

char	*get_next_line_start(char *backup, char *line)
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
    backup = get_next_line_start(backup, line);
    return (line);
}
