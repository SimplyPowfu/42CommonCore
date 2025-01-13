#include "minitalk.h"

void	put_signal(int pid, char *str)
{
	int	i;
	int	c;

	i = 0;
	while (*str)
	{
		c = *(str);
		while (i < 8)
		{
			if (c << i & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(100);
		}
		str++;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		put_signal(ft_atoi(argv[1]), argv[2]);
	else
	{
		printf("Invalid arguments.\nPut PID and messange.\n");
		exit(1);
	}
	return (0);
}
