#ifndef PHILO_H
#define PHILO_H

#include<unistd.h>//write
#include<pthread.h>//thread
#include<stdlib.h>//malloc
#include<stdio.h>//printf
#include<sys/time.h>


# define	EAT 1
# define	SLEEP 2
# define	THINK 3
# define	FORK 4
# define	DIED 5

typedef struct s_data
{
	int					philos_number;
	int					time_to_die;
	int					times_must_eat;
	int					time_to_sleep;
	int					time_to_eat;
	pthread_mutex_t		*stop_dinner;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*lock_print;
	long				timestamp;
	int					dinner_is_over;
	int					is_alone;
}				t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		philo;
	long			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*is_alive; //checks if philo has died
	pthread_mutex_t	*lock_meals; //checks if philo has eaten n times
	int				total_meals; //times philo has eaten
	t_data			*data;
}				t_philo;
//Libft
void	ft_putendl_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

void	check_args(int argc, char **argv);
void	init_data(t_data *data, int argc, char **argv);
void	init_philosophers(t_philo **philos, t_data *data);
void	print_actions(int act);
void	eat(t_philo *philo);


#endif
