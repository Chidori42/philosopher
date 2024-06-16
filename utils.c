#include "philo.h"

long get_timestamp(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void ft_sleep(size_t time)
{
	size_t start;

	start = get_timestamp();
	while ((get_timestamp() - start) < time)
		usleep(500); 
}

void print_state(t_pars *args, int id, const char *state)
{
	pthread_mutex_lock(&(args->mutex));
	printf("%ld %d %s\n", get_timestamp() - args->philos[id - 1].start_time, id, state);
	pthread_mutex_unlock(&(args->mutex));
}

void take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_state(philo->args, philo->id , "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_state(philo->args, philo->id , "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_state(philo->args, philo->id , "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_state(philo->args, philo->id , "has taken a fork");
	}
}

void put_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}