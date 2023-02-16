#include "get_next_line.h"

/*
int main (void)
{
	int fd;
	int	nb_read;
	char *buff; // the buffer that will contains the result of the read file
d)
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
		printf("%s\n", buff);
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
*/

int main(void)
{
	int		fd;
	char	*backup;
	char 	*line;
	fd = open("file_test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed\n");
		return(1);
	}
	/*
		backup = read_file(fd);
		printf("%s\n", backup);
		printf("\n\n");
		line = get_a_line(backup);
		printf("%s\n", line);
		printf("\n\n");
		backup = get_next_buffer(backup, line);
		printf("%s\n", backup);
	*/
/*
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
*/
	printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));

	if (close(fd) == -1)
	{
		printf("close() failed\n");
		return(1);
	}
	return(0);
}
