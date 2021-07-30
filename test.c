#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("fail\n");
		return (-1);
	}
	printf("%d\n", fd);
	close(fd);
	return (0);
}
