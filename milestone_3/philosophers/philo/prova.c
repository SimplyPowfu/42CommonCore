/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prova.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <ecarbona@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:04:21 by ecarbona          #+#    #+#             */
/*   Updated: 2025/02/24 20:00:55 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *thread(void *arg) {
	char *ret;
	printf("thread() entered with argument '%s'\n", arg);
	if ((ret = (char*) malloc(20)) == NULL) {
		perror("malloc() error");
		exit(2);
	}
	strcpy(ret, "This is a test");
	pthread_exit(ret);
}

//ESEMPIO THREAD_CREATE AND JOIN
int main() 
{
  pthread_t thid;
  void *ret;

  if (pthread_create(&thid, NULL, thread, "thread 1") != 0)
  {
    perror("pthread_create() error");
    exit(1);
  }
  if (pthread_join(thid, &ret) != 0)
  {
    perror("pthread_create() error");
    exit(3);
  }
  printf("thread exited with '%s'\n", ret);
}

//ESEMPIO MUTEX
int main(void)
{
	pthread_mutex_t fork_mutex;
	
	pthread_mutex_init(&fork_mutex, NULL);

	pthread_mutex_lock(&fork_mutex);
	pthread_mutex_unlock(&fork_mutex);

	pthread_mutex_destroy(&fork_mutex);
	
	return (0);
}