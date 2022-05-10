/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 05:41:54 by izail             #+#    #+#             */
/*   Updated: 2022/05/05 05:41:56 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
# include <sys/time.h>

# define SUCCESS 0
# define FAILURE 1

typedef struct timeval	t_time;
typedef struct s_info	t_info;

typedef struct s_philo
{
	int			id;
	int			ate;
	int			should_die;
	long long	last_meal;
	t_info		*info;
	pthread_t	thread;
}	t_philo;

typedef struct s_info
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_philosophers;
	int				number_of_times_each_philosopher_must_eat;
	int				finish;
	int				all_ate;
	long long		creation_time;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	finish_lock;
}	t_info;

/*************** || UTILS.C || ***************/
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);


#endif