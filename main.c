#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_sts_lk()
{
	system("leaks main");
}

int main()
{
	// int fd = open("text.txt", O_RDONLY);
	// if (fd < 0)
	// {
	// 	perror("fd failed\n");
	// 	return 1;
	// }
	// char *test = get_next_line(fd);
	// if (!test)
	// {
	// 	printf("test failed\n");
	// 	close(fd);
	// 	return 1;
	// }
	// printf("test = %s", test);
	// free(test);
	// test = get_next_line(fd);
	// if (!test)
	// {
	// 	printf("test failed\n");
	// 	close(fd);
	// 	return 1;
	// }
	// printf("test = %s", test);
	// free(test);
	// test = get_next_line(fd);
	// if (!test)
	// {
	// 	printf("test failed\n");
	// 	close(fd);
	// 	return 1;
	// }
	// printf("test = %s\n", test);
	// free(test);
	int fd = open("text.txt", O_RDONLY);
	char *test;
	
	int i = 0;
	while (i < 3)
	{
		test = get_next_line(fd);
		if (!test)
		{
			printf("test failed\n");
			close(fd);
			return 1;
		}
		printf("test = %s", test);
		free(test);
		i++;
	}
	printf("\n");
	close(fd);
	return (0);
}