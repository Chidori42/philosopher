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
	pthread_mutex_lock(&(args->print_mutex));
	printf("%ld %d %s\n", get_timestamp() - args->start_time, id, state);
	pthread_mutex_unlock(&(args->print_mutex));
}

void take_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork));
	print_state(philo->args, philo->id , "has taken a fork");
	if (philo->args->n_philos == 1)
	{
		ft_sleep(philo->args->t_die * 2);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	print_state(philo->args, philo->id , "has taken a fork");
}

void put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&(philo->left_fork));
}