/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:12:54 by izail             #+#    #+#             */
/*   Updated: 2022/05/25 21:51:07 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*action(void *arg)
{
	t_philo	*philo;
	int		l_fork;
	int		r_fork;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(700);
	while (!philo->should_die && !philo->info->flag)
	{
		r_fork = philo->id;
		if (philo->id == philo->info->number_of_philosophers)
			l_fork = 0;
		else
			l_fork = (philo->id + 1) % philo->info->number_of_philosophers;
		take_fork(philo, r_fork);
		if (philo->info->number_of_philosophers == 1)
			return (ft_usleep(philo->info->time_to_die), NULL);
		take_fork(philo, l_fork);
		eat(philo, r_fork, l_fork);
		sleep_then_think(philo);
		usleep(10);
	}
	return (NULL);
}

void	create_philo(t_info *info)
{
	int			i;
	pthread_t	thread;

	i = 0;
	info->start_time = ft_get_time();
	while (i < (info->number_of_philosophers))
	{
		init_philo(info);
		pthread_create(&info->philo[i].thread, NULL, &action, &info->philo[i]);
		pthread_create(&thread, NULL, &check_death, &info->philo[i]);
		pthread_detach(thread);
		i++;
		usleep(40);
	}
	if (info->number_of_meals >= 0)
	{
		pthread_create(&thread, NULL, &check_all_ate, info);
		pthread_detach(thread);
	}
}

void	init_philo(t_info *info)
{
	int	i;

	i = 0;
	info->start_time = ft_get_time();
	while (i < (info->number_of_philosophers))
	{
		info->philo[i].id = i;
		info->philo[i].info = info;
		info->philo[i].last_meal = info->start_time;
		info->philo->should_die = 0;
		info->philo[i].num_ate = 0;
		i++;
	}
}
