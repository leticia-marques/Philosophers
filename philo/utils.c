/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:16:57 by lemarque          #+#    #+#             */
/*   Updated: 2022/06/11 19:32:39 by lemarque         ###   ########.fr       */
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
	pthread_mutex_lock(philo->data->check_dinner);
	if (philo->data->dinner_is_over == 1)
	{
		pthread_mutex_unlock(philo->data->check_dinner);
		return(philo->data->dinner_is_over);
	}
	pthread_mutex_unlock(philo->data->check_dinner);
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

void	print_actions(int act, t_philo *philo)
{
	long	current_time;

	pthread_mutex_lock(philo->data->lock_print);
	current_time = (get_time() - philo->data->timestamp);
	if (act == EAT)
		printf("%5ld %3d is eating\n", current_time, philo->id);
	if (act == SLEEP)
		printf("%5ld %3d is sleeping\n", current_time, philo->id);
	if (act == THINK)
		printf("%5ld %3d is thinking\n", current_time, philo->id);
	if (act == FORK)
		printf("%5ld %3d has taken a fork\n", current_time, philo->id);
	if (act == DIED)
		printf("%5ld %3d die\n", current_time, philo->id);
	pthread_mutex_unlock(philo->data->lock_print);
}
