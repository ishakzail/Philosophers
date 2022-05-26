/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:24:51 by izail             #+#    #+#             */
/*   Updated: 2022/05/25 21:54:07 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, int f)
{
	pthread_mutex_lock(&philo->info->forks[f]);
	ft_print_msg(philo, "has taken a fork\n");
}

void	eat(t_philo *philo, int f1, int f2)
{
	long long	time;

	time = ft_get_time();
	ft_print_msg(philo, "is eating\n");
	while (ft_get_time() - time < philo->info->time_to_eat)
		usleep(1);
	philo->last_meal = ft_get_time();
	philo->num_ate++;
	if (philo->num_ate == philo->info->number_of_meals)
		philo->info->all_ate++;
	pthread_mutex_unlock(&philo->info->forks[f1]);
	pthread_mutex_unlock(&philo->info->forks[f2]);
}

void	sleep_then_think(t_philo *philo)
{
	long long	time;

	time = ft_get_time();
	ft_print_msg(philo, "is sleeping\n");
	while (ft_get_time() - time < philo->info->time_to_eat)
		usleep(1);
	ft_print_msg(philo, "is thinking\n");
}
