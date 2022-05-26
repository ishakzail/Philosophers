/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izail <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:55:56 by izail             #+#    #+#             */
/*   Updated: 2022/05/25 21:54:28 by izail            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			signe;
	long		nbr;

	signe = 1;
	nbr = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		signe = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr * signe);
}

void	*ft_calloc(size_t count, size_t size)
{
	char			*p;
	unsigned int	total;
	unsigned int	i;

	total = count * size;
	p = (char *)malloc(total * sizeof(char));
	if (!p)
		return (0);
	i = 0;
	while (total--)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}

int	ft_puterr(char *err)
{
	write(STDERR_FILENO, err, ft_strlen(err));
	return (FAILURE);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
