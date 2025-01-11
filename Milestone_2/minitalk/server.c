#include "minitalk.h"

void	take_signal()
{

}

int main()
{
	printf("PID process: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, take_signal);
		signal(SIGUSR2, take_signal);
	}
	return (0);
}