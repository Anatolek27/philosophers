/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 00:48:08 by akunegel          #+#    #+#             */
/*   Updated: 2024/04/12 03:11:53 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	monitoring(t_philo *p)
{
	pthread_mutex_lock(&p->lf);
	pthread_mutex_lock(&p->p_data->writing);
	philo_write("took a fork\n", p);
	pthread_mutex_unlock(&p->p_data->writing);
	if (!p->rf)
	{
		ft_sleep(p->p_data->t_t_d * 2);
		return ;
	}
	pthread_mutex_lock(p->rf);
	pthread_mutex_lock(&p->p_data->writing);
	philo_write("took a fork\n", p);
	pthread_mutex_unlock(&p->p_data->writing);
	pthread_mutex_lock(&p->p_data->writing);
	philo_write("is eating\n", p);
	pthread_mutex_lock(&p->p_data->eat);
	p->ms_eat = get_time();
	pthread_mutex_unlock(&p->p_data->eat);
	pthread_mutex_unlock(&p->p_data->writing);
	ft_sleep(p->p_data->t_t_e);
	pthread_mutex_unlock(p->rf);
	pthread_mutex_unlock(&p->lf);
	p_is_thinking(p);
}
