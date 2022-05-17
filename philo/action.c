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
    ft_print_msg(philo, "has taken a fork\n");
}

void    put_fork(t_philo *philo, int f1 , int f2)
{
    pthread_mutex_unlock(&philo->info->forks[f1]);
    pthread_mutex_unlock(&philo->info->forks[f2]);
    ft_print_msg(philo, "put forks\n");
}

void    eat(t_philo *philo)
{
    ft_print_msg(philo, "is eating\n");
    philo->ate++;
    if (philo->ate == philo->info->number_of_meals)
		philo->info->all_ate++;
}

void    ft_sleep(t_philo *philo)
{
    ft_print_msg(philo, "is sleeping\n");
}

void    think(t_philo *philo)
{
    ft_print_msg(philo, "is thinking\n");
}

void    *ft_check_if_is_dead(void *arg)
{
    t_philo *philo;

    philo = (void *)arg;
    int i = 0;
	while (!philo->info->flag)
	{
		if ((philo->last_meal + philo->info->time_to_die) < ft_get_time())
		{
			ft_print_msg(philo, "died");
			philo->should_die = 1;
			philo->info->flag = 1;
		}
		usleep(100);
	}
	return (NULL);
}

void    *action(void *arg)
{
    t_philo *philo;
    int l_fork;
    int r_fork;

    philo = (t_philo *)arg;
    int i = 0;
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
        eat(philo);
        put_fork(philo, r_fork, l_fork);
        ft_sleep(philo);
        think(philo);
        // philo->info->number_of_meals--;
    }
    return (NULL);
}

void    create_philo(t_info *info)
{
    int i = 0;
    info->creation_time = ft_get_time();
    while (i < info->number_of_philosophers)
    {
        info->philo[i].id = i;
        info->philo[i].info = info;
        info->philo[i].last_meal = info->creation_time; 
        info->philo->should_die = 0;
        pthread_create(&info->philo[i].thread, NULL, &action, &info->philo[i]);
        i++;
        usleep(100);
    }
}