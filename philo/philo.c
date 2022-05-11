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

// pthread_mutex_t mutex; 

// int t = 0;

// void*  routine()
// {
//    pthread_mutex_lock(&mutex);
//    for (int i = 0; i < 10000000; i++)
//         t++;
//    printf("value of t =%d\n", t);
//    pthread_mutex_unlock(&mutex);
// }

void    eat(t_philo *philo)
{
    printf("Philo %d is eating\n", philo->id);
}

void    ft_ssleep(t_philo *philo)
{
    printf("Philo %d is sleeping\n", philo->id);
}

void    think(t_philo *philo)
{
    printf("Philo %d is thinking\n", philo->id);
}

void    *routine(void *arg)
{
    t_philo *philo;
    arg = (void *)philo;
    eat(arg);
    ft_ssleep(arg);
    think(arg);
}

int main(int ac, char **av)
{
    // pthread_t t1, t2 , t3 , t4;
    // pthread_mutex_init(&mutex, NULL);
    // if (pthread_create(&t1, NULL, &routine, NULL) != 0)
    //     printf("Error in thread creation !");
    // if (pthread_create(&t2, NULL, &routine, NULL) != 0)
    //     printf("Error in thread creation !");
    // if (pthread_create(&t3, NULL, &routine, NULL) != 0)
    //     printf("Error in thread creation !");
    // if (pthread_create(&t4, NULL, &routine, NULL) != 0)
    //     printf("Error in thread creation !");
    // pthread_join(t1, NULL);
    // pthread_join(t2, NULL);
    // pthread_join(t3, NULL);
    // pthread_join(t2, NULL);

    t_info *info;
    info = ft_calloc(1, sizeof(*info));
    info->philo = ft_calloc(info->number_of_philosophers, sizeof(t_philo));
    ft_get_args(info, ac, av);
    ft_check_info(*info, ac);
    int i = 0;
    while (i < info->number_of_philosophers)
    {
        info->philo[i].id = i;
        info->philo[i].info = info;
        pthread_create(&info->philo[i].thread, NULL, routine, &info->philo[i]);
        i++;
        usleep(1000);
    }
    // printf("Number of philosopher : %d\n", info->number_of_philosophers);
    // printf("time to die: %d\n", info->time_to_die);
    // printf("time to eat: %d\n", info->time_to_eat);
    // printf("time to sleep: %d\n", info->time_to_sleep);

    
    // pthread_t	monitor;
	// int			i;

	// i = 0;
	// info->creation_time = ft_get_time();
	// while (i < info->number_of_philosophers)
	// {
	// 	info->philo[i].id = i;
	// 	info->philo[i].info = info;
	// 	info->philo[i].last_meal = info->creation_time;
	// 	info->philo[i].should_die = false;
	// 	info->philo[i].ate = 0;
	// 	pthread_create(&info->philo[i].thread, NULL, philosophers,
	// 		&info->philo[i]);
	// 	pthread_create(&monitor, NULL, ft_check_death, &info->philo[i]);
	// 	pthread_detach(monitor);
	// 	i++;
	// 	usleep(100);
	// }
	// if (info->number_of_times_each_philosopher_must_eat >= 0)
	// {
	// 	pthread_create(&monitor, NULL, ft_check_hunger, info);
	// 	pthread_detach(monitor);
	// }

    return (0);
}