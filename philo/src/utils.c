/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:16:57 by lemarque          #+#    #+#             */
/*   Updated: 2022/05/23 15:40:58 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	check_dinner(t_philo *philo)
{
	int	i;
	pthread_mutex_t	check_dinner;

	pthread_mutex_init(&check_dinner, NULL);
	pthread_mutex_lock(&check_dinner);
	i = philo->data->times_must_eat;
	if (philo->total_meals == i)
	{
		philo->data->dinner_is_over = 1;
		pthread_mutex_unlock(&check_dinner);
		return (1);
	}
	pthread_mutex_unlock(&check_dinner);
	return (0);
}

int	finished_dinner(t_philo *philos)
{
	int	i;
	int	philos_number;

	philos_number = philos->data->philos_number;
	i = -1;
	while (++i < philos_number)
	{
		if (check_dinner(&philos[i]) != 1)
			return (1);
	}
	return (0);
}

void	print_actions(int act, t_philo *philo)
{
	long	current_time;

	pthread_mutex_lock(philo->data->lock_print);
	current_time = (get_time() - philo->data->timestamp);
	if (act == EAT)
		printf("%5ld %d IS EATING\n", current_time, philo->id);
	if (act == SLEEP)
		printf("%5ld %d IS SLEEPING\n", current_time,  philo->id);
	if (act == THINK)
		printf("%5ld %d IS THINKING\n", current_time, philo->id);
	if (act == FORK)
		printf("%5ld %d TOOK A FORK\n", current_time, philo->id);
	if (act == DIED)
		printf("%5ld %d DIED\n", current_time, philo->id);
	pthread_mutex_unlock(philo->data->lock_print);
}
