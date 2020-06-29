#include <stdio.h>
#include <string.h>

int main()
{
	char buff[4];
	char *p = "hello world!1111111111111111111111111111111111111111111111111111";
	// if string p is not log enough, it will not cover the return address of last func.so there is no coredump file.
	char *rec = strcpy(buff, p);
	return 0;
}
