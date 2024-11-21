/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 00:48:00 by akunegel          #+#    #+#             */
/*   Updated: 2024/04/12 00:48:00 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_init_mutex(t_general *g)
{
	pthread_mutex_init(&g->data.eat, NULL);
	pthread_mutex_init(&g->data.death, NULL);
	pthread_mutex_init(&g->data.end, NULL);
	pthread_mutex_init(&g->data.writing, NULL);
}

int	ft_init(t_general *g)
{
	int	i;

	i = 0;
	g->data.nb_p_end = 0;
	g->data.s_time = get_time();
	g->data.stop = 0;
	ft_init_mutex(g);
	while (i < g->data.nb_p)
	{
		g->p[i].p_id = i + 1;
		g->p[i].end = 0;
		g->p[i].p_nb_meals = 0;
		g->p[i].ms_eat = g->data.s_time;
		g->p[i].rf = NULL;
		pthread_mutex_init(&g->p[i].lf, NULL);
		if (g->data.nb_p == 1)
			return (1);
		if (i == g->data.nb_p - 1)
			g->p[i].rf = &g->p[0].lf;
		else
			g->p[i].rf = &g->p[i + 1].lf;
		i++;
	}
	return (1);
}
