/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 00:48:13 by akunegel          #+#    #+#             */
/*   Updated: 2024/04/12 00:48:13 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_limit(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi_long(argv[i]) > 2147483647
			|| ft_atoi_long(argv[i]) < -2147483648)
		{
			ft_exit("Invalid Arguments\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_parsing(int argc, char **argv, t_general *g)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (is_number(argv[i]) == 0)
			return (ft_exit("Parameters not numbers only\n"));
		i++;
	}
	if (check_limit(argv) == 0)
		return (ft_exit("Parameter out of int range\n"));
	if (argc != 5 && argc != 6)
		return (ft_exit("expected 4 or 5 parameters\n"));
	g->data.nb_p = ft_atoi(argv[1]);
	g->data.t_t_d = ft_atoi(argv[2]);
	g->data.t_t_e = ft_atoi(argv[3]);
	g->data.t_t_s = ft_atoi(argv[4]);
	g->data.nb_meals = -1;
	if (argc == 6)
		g->data.nb_meals = ft_atoi(argv[5]);
	if (g->data.nb_p < 1 || g->data.t_t_d <= 0
		|| g->data.t_t_e <= 0 || g->data.t_t_s <= 0)
		return (ft_exit("negative arguments\n"));
	return (1);
}
