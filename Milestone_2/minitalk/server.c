#include "minitalk.h"

void	take_signal(int sig)
{
	if (sig == SIGUSR2)
		printf("signal 0");
	else if (sig == SIGUSR1)
		printf("signal 1");
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