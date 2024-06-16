
#include "philo.h"

void *monitor_thread(void *arg)
{
	int i;
	t_pars *args;
	long current_time;

	args = (t_pars *)arg;
	while (1)
	{
		if (args->stop_simulation)
			break ;
		i = -1;
		current_time = get_timestamp();
		while (++i < args->n_philos)
		{
			pthread_mutex_lock(&(args->forks[i]));
			if ((current_time - (args->philos[i].last_eat)) > (args->t_die))
			{
				print_state(args, args->philos[i].id, "died");
				pthread_mutex_unlock(&(args->forks[i]));
				args->stop_simulation = 1;
				return (NULL);
			}
			pthread_mutex_unlock(&(args->forks[i]));
		}
		usleep(10000);
	}
	return (NULL);
}

int main(int ac, char **av)
{
	t_pars args;
	pthread_t monitor;

	if (ac == 5 || ac == 6)
	{
		ft_set_param(&args, av);
		if (ft_pars(av))
			return (1);
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
