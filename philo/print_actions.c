
#include"philo.h"

void	print_actions(int act, t_philo *philo)
{
	long	current_time;

	pthread_mutex_lock(philo->data->lock_print);
	current_time = (get_time() - philo->data->timestamp);
	if (act == EAT && check_dinner(philo) == 0)
		printf("%5ld %3d is eating\n", current_time, philo->id);
	if (act == SLEEP && check_dinner(philo) == 0)
		printf("%5ld %3d is sleeping\n", current_time, philo->id);
	if (act == THINK && check_dinner(philo) == 0)
		printf("%5ld %3d is thinking\n", current_time, philo->id);
	if (act == FORK && check_dinner(philo) == 0)
		printf("%5ld %3d has taken a fork\n", current_time, philo->id);
	if (act == DIED)
		printf("%5ld %3d died\n", current_time, philo->id);
	pthread_mutex_unlock(philo->data->lock_print);
}
