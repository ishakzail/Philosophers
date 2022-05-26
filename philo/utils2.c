/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:50:02 by izail             #+#    #+#             */
/*   Updated: 2022/05/25 21:55:12 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int time)
{
	long long	t;
	long long	time2;

	time2 = time;
	t = ft_get_time();
	while (ft_get_time() - t < time2)
		usleep(1);
}

long long	ft_get_time(void)
{
	t_time	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

long long	ft_current_time(t_philo *philo)
{
	long long	time;

	time = ft_get_time() - philo->info->start_time;
	return (time);
}

void	ft_print_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->info->msg_lock);
	if (!philo->info->flag)
		printf("%lli\t%i %s", ft_current_time(philo), philo->id + 1, msg);
	pthread_mutex_unlock(&philo->info->msg_lock);
}
