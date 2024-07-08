#include "philo.h"

void free_resources(t_pars *args)
{
	if (args->philos)
		free(args->philos);
}

void init_mutexes(t_pars *args)
{
	pthread_mutex_init(&args->print_mutex, NULL);
	pthread_mutex_init(&args->meal_mutex, NULL);
	pthread_mutex_init(&args->stop_meal, NULL);
	pthread_mutex_init(&args->dead, NULL);
}

void init_philosophers(t_pars *args)
{
	int i;

	i = -1;
	args->philos = malloc(args->n_philos * sizeof(t_philo));
	if (!(args->philos))
		return ;
	args->start_time = get_timestamp();
	while (++i < args->n_philos)
	{
		args->philos[i].id = i + 1;
		args->philos[i].args = args;
		args->philos[i].right_fork = NULL;
		args->philos[i].last_eat = 0;
		args->philos[i].eat_count = 0;
		pthread_mutex_init(&(args->philos[i].left_fork), NULL);
		if (i == args->n_philos - 1)
			args->philos[i].right_fork = &args->philos[0].left_fork;
		else
			args->philos[i].right_fork = &args->philos[i + 1].left_fork;
		if (pthread_create(&(args->philos[i].thread), NULL, philosopher_thread, &(args->philos[i])) != 0)
		{
			free_resources(args);
			return ;
		}
	}
	join_philosophers(args);
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
	pthread_mutex_destroy(&(args->print_mutex));
	pthread_mutex_destroy(&(args->meal_mutex));
	pthread_mutex_destroy(&(args->stop_meal));
	pthread_mutex_destroy(&(args->dead));
}

void	*philosopher_thread(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_sleep(philo->args->t_eat);
	while (1)
	{
		take_forks(philo);
		print_state(philo->args, philo->id, "is eating");
		pthread_mutex_lock(&(philo->args->meal_mutex));
		philo->last_eat = get_timestamp();
		philo->eat_count++;
		pthread_mutex_lock(&(philo->args->stop_meal));
		if (philo->eat_count == philo->args->n_eat)
		{
			pthread_mutex_unlock(&(philo->args->stop_meal));
			return (NULL);
		}
		pthread_mutex_unlock(&(philo->args->stop_meal));
		pthread_mutex_unlock(&(philo->args->meal_mutex));
		ft_sleep(philo->args->t_eat);
		put_forks(philo);
		print_state(philo->args, philo->id, "is sleeping");
		ft_sleep(philo->args->t_sleep);
		print_state(philo->args, philo->id, "is thinking");
	}
	return (NULL);
}
