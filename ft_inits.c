#include "philo.h"

void free_resources(t_pars *args)
{
	if (args->forks)
		free(args->forks);
	if (args->philos)
		free(args->philos);
}

void init_mutexes(t_pars *args)
{
	int i;

	i = -1;
	args->forks = malloc(args->n_philos * sizeof(pthread_mutex_t));
	if (!(args->forks))
		return ;
	while (++i < args->n_philos)
	{
		if (pthread_mutex_init(&(args->forks[i]), NULL) != 0)
			return ;
	}
	pthread_mutex_init(&(args->mutex), NULL);
}

void init_philosophers(t_pars *args)
{
	int i;

	i = -1;
	args->philos = malloc(args->n_philos * sizeof(t_philo));
	if (!(args->philos))
		return ;
	while (++i < args->n_philos)
	{
		args->philos[i].id = i + 1;
		args->philos[i].args = args;
		args->philos[i].last_eat = get_timestamp();
		args->philos[i].start_time = get_timestamp();
		args->philos[i].left_fork = &(args->forks[i]);
		if (i == args->n_philos - 1)
			args->philos[i].right_fork = &(args->forks[0]);
		else
			args->philos[i].right_fork = &(args->forks[(i + 1) % args->n_philos]);
		if (pthread_create(&(args->philos[i].thread), NULL, philosopher_thread, &(args->philos[i])) != 0)
		{
			free_resources(args);
			return ;
		}
	}
}

void join_philosophers(t_pars *args)
{
	int i;

	i = -1;
	while (++i < args->n_philos)
		pthread_join(args->philos[i].thread, NULL);
}

void destroy_mutexes(t_pars *args)
{
	int i;

	i = -1;
	while (++i < args->n_philos)
		pthread_mutex_destroy(&(args->forks[i]));
	pthread_mutex_destroy(&(args->mutex));
}

void	*philosopher_thread(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_sleep(philo->args->t_eat);
	while (1)
	{
		print_state(philo->args, philo->id, "is thinking");
		take_forks(philo);
		print_state(philo->args, philo->id, "is eating");
		philo->last_eat = get_timestamp();
		ft_sleep(philo->args->t_eat);
		put_forks(philo);
		print_state(philo->args, philo->id, "is sleeping");
		ft_sleep(philo->args->t_sleep);
	}
	return (NULL);
}
