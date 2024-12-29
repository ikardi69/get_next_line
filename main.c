#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	puts("zabi 9lawiiii\n");
	int fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("fd failed\n");
		return 1;
	}
	char *test = get_next_line(fd);
	if (!test)
	{
		printf("test failed\n");
		return 1;
	}
	printf("%s\n", test);
	//free(test);
	return (0);
}