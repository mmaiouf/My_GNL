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
		//backup = read_file(fd, backup);
		//printf("read = %s\n\n", backup);
		//printf("\n\n");
		//line = get_a_line(backup);
		//printf("line = %s\n", line);
		//printf("\n\n");
		//backup = get_next_line_start(backup);
		//printf("next buff : %s\n", backup);
	//line = get_next_line(fd);
	//while (line)
	//{
	//	printf("Line : %s\n", line);
	//	free(line);
	//	line = get_next_line(fd);
	//}
	printf("GNL : %s\n", get_next_line(fd)) ;
	printf("----------------\n\n\n");
	printf("GNL : %s\n", get_next_line(fd));
	printf("----------------\n\n\n");
	printf("GNL : %s\n", get_next_line(fd));
	printf("----------------\n");
	printf("GNL : %s\n", get_next_line(fd));
	printf("----------------\n\n\n");
	printf("GNL : %s\n", get_next_line(fd));
	printf("----------------\n\n\n");
	if (close(fd) == -1)
	{
		printf("close() failed\n");
		return(1);
	}
	return(0);
}
