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

void	ft_join_free(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
		pthread_join(info->philo[i++].thread, NULL);
	free(info->philo);
	i = 0;
	while (i < info->number_of_philosophers)
		pthread_mutex_destroy(&info->forks[i++]);
	pthread_mutex_destroy(&info->msg_lock);
	free(info->forks);
	free(info);
}

int main(int ac, char **av)
{
    t_info *info;

    if (ac < 5 || ac > 6)
        return (printf("Error\n"), 0);
    info = ft_calloc(1, sizeof(*info));
    if (ft_init_all(info, ac, av) == 0)
        ft_join_free(info);
    return (0);
}