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

int main(int ac, char **av)
{
    t_info *info;
    info = ft_calloc(1, sizeof(*info));
    ft_init_all(info, ac, av);
    // create_philo(info);
    // int i = 0;
    // while (i < info->number_of_philosophers)
    // {
    //     info->philo[i].id = i;
    //     info->philo[i].info = info;
    //     pthread_create(&info->philo[i].thread, NULL, routine, (void *)&info->philo[i]);
    //     i++;
    //     usleep(100);
    // }

    return (0);
}