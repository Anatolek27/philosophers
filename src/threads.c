/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 00:48:16 by akunegel          #+#    #+#             */
/*   Updated: 2024/04/12 00:48:16 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*routine(void	*ph)
{
	t_philo	*p;

	p = (t_philo *)ph;
	if (p->p_id % 2 == 0)
		ft_sleep(p->p_data->t_t_e / 10);
	while (!check_alive(p, 0))
	{
		pthread_create (&p->d_id, NULL, p_is_dead, ph);
		monitoring(p);
		pthread_detach(p->d_id);
		if ((int)++p->p_nb_meals == p->p_data->nb_meals)
		{
			pthread_mutex_lock(&p->p_data->end);
			p->end = 1;
			p->p_data->nb_p_end++;
			if (p->p_data->nb_p_end == p->p_data->nb_p)
			{
				pthread_mutex_unlock(&p->p_data->end);
				check_alive(p, 2);
			}
			pthread_mutex_unlock(&p->p_data->end);
			return (NULL);
		}
	}
	return (NULL);
}

int	ft_threads(t_general *g)
{
	int	i;

	i = 0;
	while (i < g->data.nb_p)
	{
		g->p[i].p_data = &g->data;
		if (pthread_create(&g->p[i].t_id, NULL, routine, &g->p[i]) != 0)
			return (ft_exit("Pthread error\n"));
		i++;
	}
	return (1);
}
