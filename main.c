#include "get_next_line_bonus.h"
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
	int fd1 = open("text.txt", O_RDONLY);
	int fd2 = open("test.txt", O_RDONLY);
	int fd3 = open("testt.txt", O_RDONLY);
	char *test1;
	char *test2;
	char *test3;
	
	int i = 0;
	while (i < 3)
	{
		if (i == 2)
		{
			test1 = get_next_line(fd1);
			if (!test1)
			{
				printf("test failed\n");
				close(fd1);
				return 1;
			}
			printf("test = %s\n", test1);
			free(test1);
			test2 = get_next_line(fd2);
			if (!test2)
			{
				printf("test failed\n");
				close(fd2);
				return 1;
			}
			printf("test = %s\n", test2);
			free(test2);
			test3 = get_next_line(fd3);
			if (!test3)
			{
				printf("test failed\n");
				close(fd3);
				return 1;
			}
			printf("test = %s\n", test3);
			free(test3);
			break;
		}
		test1 = get_next_line(fd1);
		if (!test1)
		{
			printf("test failed\n");
			close(fd1);
			return 1;
		}
		printf("test = %s", test1);
		free(test1);
		test2 = get_next_line(fd2);
		if (!test2)
		{
			printf("test failed\n");
			close(fd2);
			return 1;
		}
		printf("test = %s", test2);
		free(test2);
		test3 = get_next_line(fd3);
		if (!test3)
		{
			printf("test failed\n");
			close(fd3);
			return 1;
		}
		printf("test = %s", test3);
		free(test3);
		i++;
	}
	printf("\n");
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}