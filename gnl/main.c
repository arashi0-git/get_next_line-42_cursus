

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// this is test branch

int	main(void)
{
	int		fd;
	char	*line;

	// fd = 0;
	fd = open("small.txt", O_RDONLY);
	// fd = open("big.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	printf("[BUFFER_SIZE = %d]\n", BUFFER_SIZE);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line: %s...\n", line); // 最初の100文字だけ表示
		free(line);
	}
	close(fd);
	return (0);
}

// fd = 0キーボードからの入力
// fd = 1出力
// fd = 2エラー出力