# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

int main(void)
{
	int		fd;
	//char 	*line;
	fd = open("file_test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed\n");
		return(1);
	}
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
