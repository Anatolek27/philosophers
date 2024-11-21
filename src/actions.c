/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 00:47:53 by akunegel          #+#    #+#             */
/*   Updated: 2024/04/12 00:47:53 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_alive_general(t_general *g)
{
	pthread_mutex_lock(&g->data.death);
	if (g->data.stop)
	{
		pthread_mutex_unlock(&g->data.death);
		return (1);
	}
	pthread_mutex_unlock(&g->data.death);
	return (0);
}

void	p_is_thinking(t_philo	*p)
{
	pthread_mutex_lock(&p->p_data->writing);
	philo_write("is sleeping\n", p);
	pthread_mutex_unlock(&p->p_data->writing);
	ft_sleep(p->p_data->t_t_s);
	pthread_mutex_lock(&p->p_data->writing);
	philo_write("is thinking\n", p);
	pthread_mutex_unlock(&p->p_data->writing);
}

void	*p_is_dead(void *ph)
{
	t_philo	*p;

	p = (t_philo *)ph;
	ft_sleep(p->p_data->t_t_d + 1);
	pthread_mutex_lock(&p->p_data->eat);
	pthread_mutex_lock(&p->p_data->end);
	if (!check_alive(p, 0) && !p->end
		&& ((get_time() - p->ms_eat) >= (long)(p->p_data->t_t_d)))
	{
		pthread_mutex_unlock(&p->p_data->eat);
		pthread_mutex_unlock(&p->p_data->end);
		pthread_mutex_lock(&p->p_data->writing);
		philo_write("died\n", p);
		pthread_mutex_unlock(&p->p_data->writing);
		check_alive(p, 1);
	}
	pthread_mutex_unlock(&p->p_data->eat);
	pthread_mutex_unlock(&p->p_data->end);
	return (NULL);
}
