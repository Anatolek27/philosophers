/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 00:48:21 by akunegel          #+#    #+#             */
/*   Updated: 2024/04/12 00:48:22 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_write(char	*str, t_philo *p)
{
	long int	t;

	t = get_time() - p->p_data->s_time;
	if (t >= 0 && t <= 2147483647 && !check_alive(p, 0))
		printf("%ld Philo %d %s", t, p->p_id, str);
}

int	get_time(void)
{
	static struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (ft_exit("Error getting time\n"));
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_sleep(long time)
{
	long	t;

	t = 0;
	t = get_time();
	while ((get_time() - t) < time)
		usleep(time / 10);
}

long	ft_atoi_long(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	sign = 1;
	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] == '-' || str[i] == '+' || str[i] == ' ')
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + (str[i] - '0');
			i++;
		}
		return (nb * sign);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	sign = 1;
	i = 0;
	nb = 0;
	while (str[i])
	{
		while (str[i] == '-' || str[i] == '+' || str[i] == ' ')
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + (str[i] - '0');
			i++;
		}
		return (nb * sign);
	}
	return (0);
}
