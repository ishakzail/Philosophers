/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:12:54 by izail             #+#    #+#             */
/*   Updated: 2022/05/11 16:12:55 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    take_fork(t_philo *philo, int f)
{
    pthread_mutex_lock(&philo->info->forks[f]);
    printf("Philo %d has taken a fork\n", philo->id);
}

void    put_fork(t_philo *philo, int f1 , int f2)
{
    pthread_mutex_unlock(&philo->info->forks[f1]);
    pthread_mutex_unlock(&philo->info->forks[f2]);
    printf("Philo %d has put the fork\n", philo->id);
}

void    eat(t_philo *philo)
{
    printf("Philo %d is eating\n", philo->id);
}

void    *action(void *arg)
{
    t_philo *philo;
    int l_fork;
    int r_fork;

    philo = (t_philo *)arg;

    while (!philo->should_die)
    {
        r_fork = philo->id;
        l_fork = (philo->id + 1) % philo->info->number_of_philosophers;
        take_fork(philo, r_fork);
        if (philo->info->number_of_philosophers == 1)
        {
            usleep(100000);
            break;
        }
        take_fork(philo, l_fork);
        // eat(philo);
        put_fork(philo, r_fork, l_fork);
        // sleep()
        // think()
    }
    return (NULL);
}

void    create_philo(t_info *info)
{
    int i = 0;
    while (i < info->number_of_philosophers)
    {
        info->philo[i].id = i;
        info->philo[i].info = info;
        info->philo->should_die = 0;
        pthread_create(&info->philo[i].thread, NULL, &action, &info->philo[i]);
        i++;
        usleep(100);
    }
}