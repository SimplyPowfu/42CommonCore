#include "minitalk.h"

void	take_signal(int sig)
{
	if (sig == SIGUSR2)
		write (1, "0", 1);
	else if (sig == SIGUSR1)
		write (1, "1", 1);
}

int main(void)
{
	printf("PID process: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, take_signal);
		signal(SIGUSR2, take_signal);
	}
	return (0);
}