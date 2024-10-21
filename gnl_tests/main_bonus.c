#include "get_next_line_bonus.h"
#include <stdio.h>

int main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	char	*line1;
	char	*line2;
	char	*line3;
	char	*line4;

	fd1 = open("1char.txt", O_RDONLY);
	if (fd1 == -1)
	{
		printf("Error opening file");
		return (1);
	}

	fd2 = open("lines_around_10.txt", O_RDONLY);
	if (fd2 == -1)
	{
		printf("Error opening file");
		return (1);
	}

	fd3 = open("giant_line.txt", O_RDONLY);
	if (fd3 == -1)
	{
		printf("Error opening file");
		return (1);
	}

	fd4 = open("multiple_nl.txt", O_RDONLY);
	if (fd4 == -1)
	{
		printf("Error opening file");
		return (1);
	}

	while ((line1 = get_next_line(fd1)) != NULL)
	{
		printf("File 1: %s\n", line1);
		free(line1);
	}
	close(fd1);

	while ((line2 = get_next_line(fd2)) != NULL)
	{
		printf("File 2: %s\n", line2);
		free(line2);
	}
	close(fd2);

	while ((line3 = get_next_line(fd3)) != NULL)
	{
		printf("File 3: %s\n", line3);
		free(line3);
	}
	close(fd3);

	while ((line4 = get_next_line(fd4)) != NULL)
	{
		printf("File 4: %s\n", line4);
		free(line4);
	}
	close(fd4);

	return (0);
}
