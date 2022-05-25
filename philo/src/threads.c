/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 00:47:29 by lemarque          #+#    #+#             */
/*   Updated: 2022/05/25 15:39:26 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

long get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static void	*call_actions(void *philo_void)
{
	t_philo *philo;

	philo = (t_philo *)philo_void;
	if (philo->id % 2 == 0)
		usleep(50);
	pthread_mutex_lock(philo->data->get_timestamp);
	philo->data->timestamp = get_time();
	pthread_mutex_unlock(philo->data->get_timestamp);
	while (philo->data->dinner_is_over == 0)
	{
		eat(philo);
		if(check_dinner(philo) == 1)
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
	pthread_mutex_t	finish_dinner;

	pthread_mutex_init(&finish_dinner, NULL);
	philos = (t_philo *)philos_void;
	while (finished_dinner(philos) == 1)
	{
		i = -1;
		while (++i < philos[0].data->philos_number)
		{
			if ( (get_time() - philos[i].last_meal)\
			 > philos[i].data->time_to_die)
			{
				pthread_mutex_lock(&finish_dinner);
				philos[i].data->dinner_is_over = 1;
				pthread_mutex_unlock(&finish_dinner);
				print_actions(DIED, &philos[i]);
				return (NULL);
			}
		}
		usleep(3000);
	}
	return (NULL);
}

void	init_threads(t_data *data, t_philo *philos)
{
	int			i;
	pthread_t	monitor;

	i = -1 ;
	while (++i < data->philos_number)
		pthread_create(&philos[i].philo, NULL, &call_actions, &philos[i]);
	pthread_create(&monitor, NULL, &monitor_philos, &(*philos));
	i = -1;
	while (++i <  data->philos_number)
		pthread_join(philos[i].philo, NULL);
	pthread_join(monitor, NULL);

}
