/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 00:48:04 by akunegel          #+#    #+#             */
/*   Updated: 2024/04/17 16:04:19 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_exit(char	*str)
{
	write(1, str, ft_strlen(str));
	return (0);
}

int	check_alive(t_philo *p, int id)
{
	pthread_mutex_lock(&p->p_data->death);
	if (id)
		p->p_data->stop = id;
	if (p->p_data->stop)
	{
		pthread_mutex_unlock(&p->p_data->death);
		return (1);
	}
	pthread_mutex_unlock(&p->p_data->death);
	return (0);
}

void	ft_end(t_general *g)
{
	int	i;

	i = 0;
	while (!check_alive_general(g))
		ft_sleep(1);
	while (i <= g->data.nb_p)
	{
		pthread_join(g->p[i].t_id, NULL);
		usleep(100);
		i++;
	}
	pthread_mutex_destroy(&g->data.writing);
	i = 0;
	while (i < g->data.nb_p)
	{
		pthread_mutex_destroy(&g->p[i].lf);
		usleep(100);
		i++;
	}
	if (g->data.stop == 2)
		printf("All philosophers ate %d times\n", g->data.nb_meals);
	free(g->p);
}

int	main(int argc, char **argv)
{
	t_general	g;

	if (!(ft_parsing(argc, argv, &g)))
		return (ft_exit("Wrong parameters\n"));
	g.p = malloc(sizeof(t_philo) * g.data.nb_p);
	if (!g.p)
		return (ft_exit("Malloc error\n"));
	if (!ft_init(&g) || !ft_threads(&g))
	{
		free(g.p);
		return (0);
	}
	ft_end(&g);
}
