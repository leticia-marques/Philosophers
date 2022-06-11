/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 00:47:29 by lemarque          #+#    #+#             */
/*   Updated: 2022/06/11 19:33:18 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

static void	*alone(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_actions(FORK, philo);
	pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static void	*call_actions(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	if (philo->id % 2 == 0)
		usleep(300);
	if (philo->data->philos_number == 1)
		return (alone(philo));
	while (check_dinner(philo) != 1)
	{
		eat(philo);
		if (get_meals(philo) == philo->data->times_must_eat)
			return (NULL);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

static void	*monitor_philos(void *philos_void)
{
	t_philo	*philos;
	int		i;
	long	now;

	philos = (t_philo *)philos_void;
	while (finished_dinner(philos) != 0)
	{
		i = -1;
		while (++i < philos[0].data->philos_number)
		{
			now = (get_time() - philos->data->timestamp);
			if ((now - get_last_meal(&philos[i])) > philos[i].data->time_to_die)
			{
				finished_dinner(&philos[i]);
				print_actions(DIED, &philos[i]);
				return (NULL);
			}
		}
		usleep(1000);
	}
	return (NULL);
}

void	init_threads(t_data *data, t_philo *philos)
{
	int			i;
	pthread_t	monitor;

	philos->data->timestamp = get_time();
	i = -1 ;
	while (++i < data->philos_number)
		pthread_create(&philos[i].philo, NULL, &call_actions, &philos[i]);
	pthread_create(&monitor, NULL, &monitor_philos, &(*philos));
	i = -1;
	while (++i < data->philos_number)
		pthread_join(philos[i].philo, NULL);
	pthread_join(monitor, NULL);
}
