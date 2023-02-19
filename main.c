#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*backup;
	char 	*line;
	char	*read;
	fd = open("file_test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed\n");
		return(1);
	}
		read = read_file(fd, backup);
		printf("%s\n", read);
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
	//printf("%s\n", get_next_line(fd));
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
