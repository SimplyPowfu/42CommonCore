#include <unistd.h>

void ft_putnbr_fd(int n, int fd)
{
	char c;
	if (n < 0)
	{
		write (fd, "-", 1);
		if (n == -2147483648)
		{
			write (fd, "2147483648", 10);
		}
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	c = (n % 10) + 48;
	write (fd, &c, 1);
}
