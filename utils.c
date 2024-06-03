#include "philo.h"

long get_timestamp(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}


void print_state(t_pars *args, int id, const char *state)
{
	pthread_mutex_lock(&args->mutex);
	printf("%ld %d %s\n", get_timestamp(), id, state);
	pthread_mutex_unlock(&args->mutex);
}

void take_forks(t_philo *philo)
{
	t_pars *args;
	int left_fork;
	int right_fork;

	args = philo->args;
	left_fork = philo->id;
	right_fork = (philo->id + 1) % args->n_philos;
	pthread_mutex_lock(&args->forks[left_fork]);
	print_state(args, philo->id, "has taken a fork");
	pthread_mutex_lock(&args->forks[right_fork]);
	print_state(args, philo->id, "has taken a fork");
}

void put_forks(t_philo *philo)
{
	t_pars *args;
	int left_fork;
	int right_fork;

	args = philo->args;
	left_fork = philo->id;
	right_fork = (philo->id + 1) % args->n_philos;
	pthread_mutex_unlock(&(args->forks[right_fork]));
	pthread_mutex_unlock(&(args->forks[left_fork]));
}