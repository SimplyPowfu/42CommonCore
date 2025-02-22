/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prova.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:04:21 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/22 18:25:10 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *ThreadFunction(void *arguments)
{
	long tid = (long)arguments;
	char *s = "ci";
  	printf("Thread Running, TID: %ld\n", tid);
  	return NULL;
}

int main() {
	pthread_t threads[3];

	for(long i = 0; i < 5; i++){
		printf("Creando il thread %ld\n", i);
		pthread_create(&threads[i], NULL, ThreadFunction, (void *)((long)i));
		usleep(100);
	}
	for(long i = 0; i < 5; i++)
		pthread_join(threads[i], NULL);

  return 0;
}