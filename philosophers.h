/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 00:48:34 by akunegel          #+#    #+#             */
/*   Updated: 2024/04/12 00:48:34 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	pthread_mutex_t	eat;
	pthread_mutex_t	death;
	pthread_mutex_t	end;
	pthread_mutex_t	writing;
	int				nb_p;
	int				t_t_e;
	int				t_t_s;
	int				t_t_d;
	int				nb_meals;
	long			s_time;
	int				stop;
	int				nb_p_end;
}				t_data;

typedef struct s_philo
{
	pthread_t		t_id;
	pthread_t		d_id;
	t_data			*p_data;
	int				p_nb_meals;
	int				p_id;
	int				end;
	long			ms_eat;
	pthread_mutex_t	*rf;
	pthread_mutex_t	lf;
}				t_philo;

typedef struct s_general
{
	t_data	data;
	t_philo	*p;
}				t_general;

int		ft_strlen(char *str);
int		get_time(void);
int		ft_atoi(const char *str);
int		ft_threads(t_general *g);
int		check_limit(char **argv);
int		is_number(char *str);
int		ft_parsing(int argc, char **argv, t_general *g);
int		ft_exit(char	*str);
int		check_alive(t_philo *p, int id);
int		ft_init(t_general *g);
int		check_alive_general(t_general *g);
void	p_is_thinking(t_philo *p);
void	*p_is_dead(void *ph);
void	philo_write(char	*str, t_philo *p);
void	ft_sleep(long time);
long	ft_atoi_long(const char *str);
void	*routine(void	*ph);
void	monitoring(t_philo *p);
void	ft_end(t_general *g);
void	ft_init_mutex(t_general *g);

#endif
