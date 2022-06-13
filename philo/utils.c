/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:16:57 by lemarque          #+#    #+#             */
/*   Updated: 2022/06/12 19:34:00 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

long	get_last_meal(t_philo *philo)
{
	long	last_meal;

	pthread_mutex_lock(philo->lock_meals);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(philo->lock_meals);
	return (last_meal);
}

void	dinner_is_over(t_philo *philo)
{
	pthread_mutex_lock(philo->data->lock_dinner);
	philo->data->dinner_is_over = 1;
	pthread_mutex_unlock(philo->data->lock_dinner);
}

int	get_meals(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(philo->lock_meals);
	i = philo->total_meals;
	pthread_mutex_unlock(philo->lock_meals);
	return (i);
}

int	check_dinner(t_philo *philo)
{
	pthread_mutex_lock(philo->data->lock_dinner);
	if (philo->data->dinner_is_over == 1)
	{
		pthread_mutex_unlock(philo->data->lock_dinner);
		return (philo->data->dinner_is_over);
	}
	pthread_mutex_unlock(philo->data->lock_dinner);
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
		if (get_meals(&philos[i]) != philos[i].data->times_must_eat)
			return (1);
	}
	return (0);
}
