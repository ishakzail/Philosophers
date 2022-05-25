/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:04:04 by izail             #+#    #+#             */
/*   Updated: 2022/05/18 15:04:06 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *check_death(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (!philo->info->flag)
    {
        if ((philo->last_meal + philo->info->time_to_die)  == ft_get_time())
        {
            ft_print_msg(philo, "died\n");
            philo->should_die = 1;
            philo->info->flag = 1;
        }
        usleep(10);
    }
    return (NULL);
}

void	*check_all_ate(void *arg)
{
	t_info	*info;

	info = (t_info *)arg;
	while (!info->flag)
	{
		if (info->all_ate == info->number_of_philosophers)
			info->flag = 1;
	}
	return (NULL);
}