#include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE 1000

/*
int main (void)
{
	int fd;
	int	nb_read;
	char *buff; // the buffer that will contains the result of the read file

	buff = malloc(sizeof(char) * BUFF_SIZE + 1);
	//if (buff == NULL)
		//return(NULL);
	// Open the file
	fd = open("file_test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (1);
	}
	printf("Fd : %d\n\n", fd);
	
	// Read the file until EndOfFile (0)
	while ((nb_read = read(fd, buff, BUFF_SIZE)))
	{
		buff[nb_read] = '\0';
		printf("Buffer \n: %s\n", buff);
		printf("Nb read : %d\n\n", nb_read);
	}
	// Close the file
	if (close(fd) == -1)
	{
		printf("close() failed\n");
		return (1);
	}
	free(buff);
	return (0);
}





char    ft_prout(char *str)
{
    static int        i = -1;

    while(str[++i])
    {
		printf("index : %d\n", i);
        return(str[i]);
    }
    return (0);
}
int main(void)
{
    printf("%c\n", ft_prout("Mou3aad"));
    printf("%c\n", ft_prout("Mou3aad"));
    printf("%c\n", ft_prout("Mou3aad"));
    return(0);
}

int main(void)
{
	int		fd;
	fd = open("file_test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed\n");
		return(1);
	}
	printf("%s\n", get_next_line(fd));
	printf("\n");
	printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	if (close(fd) == -1)
	{
		printf("close() failed\n");
		return(1);
	}
	return(0);
}
*/

int main(void)
{
	
	return(0);
}
