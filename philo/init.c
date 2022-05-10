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
        info->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    else
        info->number_of_times_each_philosopher_must_eat = -1;
}

int ft_check_info(t_info info, int ac)
{
    if (ac == 6 && info.number_of_times_each_philosopher_must_eat == 0)
        return (ft_puterr("ERROR : Wrong num of must_eat\n"));
    if (info.number_of_philosophers < 0)
        return (ft_puterr("ERROR : Wrong number of philosophers"));
    if (info.time_to_die < 60)
        return (ft_puterr("ERROR : Wrong number of time_to_die\n"));
    if (info.time_to_eat < 60)
        return (ft_puterr("ERROR : Wrong number of time_to_die\n"));
    if (info.time_to_sleep < 60)
        return (ft_puterr("ERROR : Wrong number of time_to_die\n"));
    return (SUCCESS);
}