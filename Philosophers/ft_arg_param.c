#include "philo.h"

int	ft_check_arg(int argc, char **argv, t_all_param *param)
{
	int	i;
	int	j;

	i = 1;
	param->stop_eat = 0;
	if (argc != 5 && argc != 6)
		return (1);
	while (i < argc)
	{
		j = 0;
		while (ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j] != 0)
			return (1);
		i++;
	}
	param->num_philo = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		param->stop_eat = ft_atoi(argv[5]);
	return (0);
}

int	ft_init_param(t_all_param *param, t_philo **philo)
{
	int	i;

	i = 0;
	if (param->num_philo < 1 || param->num_philo
		> 200 || param->time_to_die < 60 || param->time_to_eat < 60
		|| param->time_to_sleep < 60 || param->stop_eat < 0)
		return (1);
	*philo = (t_philo *)malloc(sizeof(t_philo) * param->num_philo);
	param->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* param->num_philo);
	if (!(*philo) || !param->fork)
		return (1);
	param->philo_die = 0;
	while (i < param->num_philo)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].left_fork = &param->fork[i];
		(*philo)[i].right_fork = &param->fork[i + 1 % param->num_philo];
		(*philo)[i].param = param;
		(*philo)[i].n_eat = 0;
		pthread_mutex_init(&param->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&param->st_out, NULL);
	return (0);
}
