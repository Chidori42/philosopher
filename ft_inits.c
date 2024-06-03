#include "philo.h"

void init_mutexes(t_pars *args)
{
	int i;

	i = 0;
	args->forks = malloc(args->n_philos * sizeof(pthread_mutex_t));
	if (!(args->forks))
		return ;
	while (++i <= args->n_philos)
		pthread_mutex_init(&args->forks[i], NULL);
	pthread_mutex_init(&(args->mutex), NULL);
}

void init_philosophers(t_pars *args)
{
	int i;

	i = 0;
	args->philos = malloc(args->n_philos * sizeof(t_philo));
	if (!(args->philos))
		return ;
	while (++i <= args->n_philos)
	{
		args->philos[i].id = i;
		args->philos[i].last_eat = get_timestamp();
		args->philos[i].args = args;
		pthread_create(&(args->philos[i].thread), NULL, philosopher_thread, &args->philos[i]);
	}
}

void join_philosophers(t_pars *args)
{
	int i;

	i = 0;
	while (++i <= args->n_philos)
		pthread_join(args->philos[i].thread, NULL);
}

void destroy_mutexes(t_pars *args)
{
	int i;

	i = 0;
	while (++i <= args->n_philos)
		pthread_mutex_destroy(&args->forks[i]);
	pthread_mutex_destroy(&(args->mutex));
}
