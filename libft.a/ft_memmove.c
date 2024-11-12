#include <unistd.h>
#include <stdio.h>

void *ft_memmove(void *dest, void *src, unsigned int len)
{
	unsigned char *dest1 = dest;
	unsigned char *src1 = src;
	unsigned int i = 0;

	while(i < len)
	{
		dest1[i] = src1[i];
		i++;
	}
}

int main()
{
	char str[] = "Hello, World!";
	ft_memmove(str + 7, str, 5);
	printf("%s\n", str);
}