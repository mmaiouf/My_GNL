/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:56:23 by momaiouf          #+#    #+#             */
/*   Updated: 2023/02/28 02:58:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *backup)
{
	int		nb_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return(NULL);
	nb_read = 1;
	//printf("backup au debut : %s\n", backup);
	while (!check_nbread_and_linebreak(backup, nb_read)) // while 0, donc tant tant qu'il y a encore des choses a lire et qu'on ne trouve pas de \n dans la backup
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		backup = ft_strjoin(backup, buffer);
		//printf("buffer : %s\n", buffer);
		//printf("backup : %s\n", backup);
	//	printf("nbread : %d\n", nb_read);
	//	printf("----------------\n");
	}
	free(buffer);
	return (backup);
}

int		check_nbread_and_linebreak(char *str, int nb_read)
{
	int             i;

	i = 0;
	if (str == NULL)
		return (0);
	if (nb_read == 0) // quand il y a plus rien à lire, on rentre pas dans la boucle, on sort direct pour pouvoir retourner priut
		return (1);
	while (str[i] != 0)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_a_line(char *backup)
{
	int		i;
	int		len_line;
	char	*line;
	
	i = 0;
	if (!backup[i])
		return (NULL);
	len_line = get_len_line(backup);
	line = malloc(sizeof(char) * (len_line + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return(line);
}

char	*get_next_line_start(char *backup)
{
	int		i;
	int		j;
	int		len_next_buffer;
	char	*next_buffer;
	
	i = get_index_linebreak(backup);
	//printf("get index linebreak : %d\n", i);
	j = 0;
	if (backup[i] == '\0')
	{
		free(backup);
		return (NULL);
	}
	len_next_buffer = ft_strlen(backup) - i;
	//printf("len next buffer after parsing : %d\n", len_next_buffer);
	//printf("i after parsing : %d\n", i);
	next_buffer = malloc(sizeof(char) * (len_next_buffer + 1));
	if (next_buffer == NULL)
		return (NULL);
	i++;
	//printf("i - len_next_buffer : %d\n", i);
	while(backup[i])
	{
		next_buffer[j] = backup[i];
		i++;
		j++;
	}
	if (backup)
		next_buffer[j] = '\0';
	//printf("nextbuff : %s\n", next_buffer);
	free(backup);
	return (next_buffer);
}

char    *get_next_line(int fd)
{
    char        	*line;
    static char		*backup;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		free(backup);
		backup = NULL;
		return (NULL);
		//return (free(backup), backup = NULL, NULL);
	}
    backup = read_file(fd, backup);
	if (backup == NULL)
	{
		free(backup);
		return (NULL);
	}
    line = get_a_line(backup);
    backup = get_next_line_start(backup);
    return (line);
}
