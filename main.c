
#include "philo.h"

void *philosopher_thread(void *arg)
{
	t_philo *philo;
	t_pars *args;

	philo = (t_philo *)arg;
	args = philo->args;
	while (1)
	{
		print_state(args, philo->id, "is thinking");
		take_forks(philo);
		print_state(args, philo->id, "is eating");
		philo->last_eat = get_timestamp();
		usleep(args->t_eat * 1000);
		put_forks(philo);
		print_state(args, philo->id, "is sleeping");
		usleep(args->t_sleep * 1000);
	}
	return (NULL);
}

void *monitor_thread(void *arg)
{
	int i;
	t_pars *args;
	long current_time;

	args = (t_pars *)arg;
	while (1)
	{
		current_time = get_timestamp();
		i = 0;
		while (++i <= args->n_philos)
		{
			if ((current_time - (args->philos[i].last_eat)) > (args->t_die))
			{
				print_state(args, args->philos[i].id, "died");
				exit(1);
			}
		}
		usleep(10000);
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	t_pars args;
	pthread_t monitor;

	if (argc == 5 || argc == 6)
	{
		ft_set_param(&args, argv);
		init_mutexes(&args);
		init_philosophers(&args);
		pthread_create(&monitor, NULL, monitor_thread, &args);
		join_philosophers(&args);
		pthread_join(monitor, NULL);
		destroy_mutexes(&args);
		free(args.philos);
		free(args.forks);
	}
	else
		printf("Check number of argiments\n");
	return (0);
}
