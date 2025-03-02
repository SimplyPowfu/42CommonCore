/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:52:36 by ecarbona          #+#    #+#             */
/*   Updated: 2025/03/02 17:15:44 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int counter = 0; //variabile thread race
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//NO MUTEX
void *som_noM(void *arg)
{
	for(int i = 0; i < 10; ++i)
	{
		counter++;
		printf("Thread %ld, conteggio: %d\n",(long)arg, counter);
	}
	return NULL;
}

//MUTEX
void *som_M(void *arg)
{
	for(int i = 0; i < 10; ++i)
	{
		pthread_mutex_lock(&mutex);
		counter++;
		printf("Thread %ld, conteggio: %d\n",(long)arg, counter);
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main()
{
	pthread_t t1, t2, t3, t4;

	pthread_create(&t1, NULL, som_noM,(void*)1);
	pthread_create(&t2, NULL, som_noM,(void*)2);
	pthread_create(&t3, NULL, som_M,(void*)1);
	pthread_create(&t4, NULL, som_M,(void*)2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("valore totale del conteggio no mutex: %d\n", counter);
	counter = 0;
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);

	printf("valore totale del conteggio mutex: %d\n", counter);
	pthread_mutex_destroy(&mutex);
}
