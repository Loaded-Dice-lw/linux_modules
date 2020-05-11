#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>

int main(int argc, char** argv)
{
	int ret;
	int fd;
	char save_buf[1024] = {0};
	if(argc != 2) {
		printf("Usage: %s /dev/xxx", argv[0]);//such as ./app /dev/mymisc
		return 0;
	}

	fd = open(argv[1], O_RDWR);
	if(fd < 0) {
		printf("open error!\n");
		return -1;
	}
	
	printf("fd = %d\n", fd);
	ret = read(fd, save_buf, 100);
	if(ret < 0) {
		printf("read error!\n");
		return ret;
	}

	ret = write(fd, "console out test \r\n", sizeof("console out test \r\n"));
	printf("ret = %d\n", ret);
	close(fd);
	return 0;
}
