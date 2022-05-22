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
    // pthread_mutex_lock(&philo->info->forks[f2]);
    // ft_print_msg(philo, "has taken a fork\n");
}

void    put_fork(t_philo *philo, int f1 , int f2)
{
    pthread_mutex_unlock(&philo->info->forks[f1]);
    pthread_mutex_unlock(&philo->info->forks[f2]);
}

void    eat(t_philo *philo)
{
    ft_print_msg(philo, "is eating\n");
	ft_usleep(philo->info->time_to_eat);
	philo->last_meal = ft_get_time();
	philo->num_ate++;
	if (philo->num_ate == philo->info->number_of_meals)
		philo->info->all_ate++;
}

void	sleep_then_think(t_philo *philo)
{
	ft_print_msg(philo, "is sleeping\n");
	ft_usleep(philo->info->time_to_sleep);
	ft_print_msg(philo, "is thinking\n");
}

void    *action(void *arg)
{
    t_philo *philo;
    pthread_t one_philo;
    int l_fork;
    int r_fork;

    philo = (t_philo *)arg;
    while (!philo->should_die && !philo->info->flag)
    {
        
        // printf("philo->id == %d\n", philo->id);
        r_fork = philo->id;
        // take_fork(philo, r_fork);
        if (philo->id == philo->info->number_of_philosophers)
            l_fork = 0;
        else
            l_fork = (philo->id + 1) % philo->info->number_of_philosophers;
        take_fork(philo, r_fork);
        if (philo->info->number_of_philosophers == 1)
        {
            // pthread_create(&one_philo, NULL, &check_death, philo);
            // pthread_detach(one_philo);
            // break;
            ft_usleep(philo->info->time_to_die);
            break;
        }
        take_fork(philo, l_fork);
        eat(philo);
        put_fork(philo, r_fork, l_fork);
        sleep_then_think(philo);
        usleep(10);
        // printf("all_ate == %d\n", philo->info->all_ate);
    }
    return (NULL);
}

void    create_philo(t_info *info)
{
    int i = 0;
    pthread_t thread;

    
    info->start_time = ft_get_time();
    while (i < (info->number_of_philosophers))
    {
        info->philo[i].id = i;
        info->philo[i].info = info;
        info->philo[i].last_meal = info->start_time; 
        info->philo->should_die = 0;
        info->philo[i].num_ate = 0;
        pthread_create(&info->philo[i].thread, NULL, &action, &info->philo[i]);
        pthread_create(&thread, NULL, &check_death, &info->philo[i]);
        
        pthread_detach(thread);
        
        i++;
        usleep(100);
    }
    if (info->number_of_meals >= 0)
    {
        pthread_create(&thread, NULL, &check_all_ate, info);
        // printf("flag 0 == %d\n", info->flag);
		pthread_detach(thread);
    }
    // printf("flag 1 == %d\n", info->flag);
}