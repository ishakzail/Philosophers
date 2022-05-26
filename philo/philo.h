/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 05:41:54 by izail             #+#    #+#             */
/*   Updated: 2022/05/25 21:53:48 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define SUCCESS 0
# define FAILURE 1

typedef struct timeval	t_time;
typedef struct s_info	t_info;

typedef struct s_philo
{
	int			id;
	int			num_ate;
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
	int				number_of_meals;
	int				flag;
	int				all_ate;
	long long		start_time;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg_lock;
}	t_info;

/*************** || UTILS.C || ***************/

int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_strlen(const char *str);
int			ft_puterr(char *err);
void		ft_print_msg(t_philo *philo, char *msg);
long long	ft_current_time(t_philo *philo);
long long	ft_get_time(void);
void		ft_usleep(int time);

/*************** || INIT.C || ***************/

void		ft_get_args(t_info *info, int ac, char **av);
int			ft_check_info(t_info info, int ac, char **av);
void		ft_init_mutex(t_info *info);
int			ft_init_all(t_info *info, int ac, char **av);

/*************** || ACTION.C || ***************/

void		take_fork(t_philo *philo, int f);
void		eat(t_philo *philo, int f1, int f2);
void		ft_sleep(t_philo *philo);
void		sleep_then_think(t_philo *philo);
void		*action(void *arg);
void		create_philo(t_info *info);

/*************** || CHECK.C || ***************/

void		*check_death(void *arg);
void		*check_all_ate(void *arg);
int			check_if_int(char *str);
void		init_philo(t_info *info);

#endif
