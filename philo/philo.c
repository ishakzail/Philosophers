/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 05:41:47 by izail             #+#    #+#             */
/*   Updated: 2022/05/05 05:41:50 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mutex; 

int t = 0;

void*  routine()
{
   pthread_mutex_lock(&mutex);
   for (int i = 0; i < 10000000; i++)
        t++;
   printf("value of t =%d\n", t);
   pthread_mutex_unlock(&mutex);
}

int main()
{
    pthread_t t1, t2 , t3 , t4;
    pthread_mutex_init(&mutex, NULL);
    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
        printf("Error in thread creation !");
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
        printf("Error in thread creation !");
    if (pthread_create(&t3, NULL, &routine, NULL) != 0)
        printf("Error in thread creation !");
    if (pthread_create(&t4, NULL, &routine, NULL) != 0)
        printf("Error in thread creation !");
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t2, NULL);

    return (0);
}