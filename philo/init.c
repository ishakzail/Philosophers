/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:53:18 by izail             #+#    #+#             */
/*   Updated: 2022/05/10 14:53:19 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_get_args(t_info *info, int ac, char **av)
{
    info->number_of_philosophers = ft_atoi(av[1]);
    info->time_to_die = ft_atoi(av[2]);
    info->time_to_eat = ft_atoi(av[3]);
    info->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        info->number_of_meals = ft_atoi(av[5]);
    else
        info->number_of_meals = -1;
}

int ft_check_info(t_info info, int ac)
{
    if (ac == 6 && info.number_of_meals == 0)
        return (ft_puterr("ERROR : Wrong num of must_eat\n"));
    if (info.number_of_philosophers < 0)
        return (ft_puterr("ERROR : Wrong number of philosophers"));
    if (info.time_to_die < 60)
        return (ft_puterr("ERROR : Wrong number of time_to_die\n"));
    if (info.time_to_eat < 60)
        return (ft_puterr("ERROR : Wrong number of time_to_eat\n"));
    if (info.time_to_sleep < 60)
        return (ft_puterr("ERROR : Wrong number of time_to_sleep\n"));
    return (SUCCESS);
}

void ft_init_mutex(t_info *info)
{
    int i;

    i = 0;
    pthread_mutex_init(&info->msg_lock, NULL);
    while (i < info->number_of_philosophers)
    {
        pthread_mutex_init(&info->forks[i], NULL);
        i++;
    }
}

int	ft_init_all(t_info *info, int ac, char **av)
{
	if (!info)
		return (FAILURE);
	ft_get_args(info, ac, av);
	if (ft_check_info(*info, ac))
		return (FAILURE);
	info->philo = ft_calloc(info->number_of_philosophers, sizeof(t_philo));
    info->forks = ft_calloc(info->number_of_philosophers,
			sizeof(pthread_mutex_t));
    if (!info->philo || !info->forks)
        return (SUCCESS);
    info->flag = 0;
    info->all_ate = 0;
    ft_init_mutex(info);
    create_philo(info);
	return (SUCCESS);
}