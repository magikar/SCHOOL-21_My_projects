#include "philo.h"

void	*ft_simul(void *philosof)
{
	t_philo		*philo;
	t_all_param	*param;

	philo = (t_philo *)philosof;
	param = philo->param;
	gettimeofday(&philo->last_time_eat, NULL);
	if (!(philo->id % 2))
		ft_wait(param->start_time, param->time_to_eat / 2);
	while (1)
	{
		ft_eating(philo, param);
		if (philo->n_eat == param->stop_eat)
			break ;
		ft_sleeping(philo, param);
		ft_thinking(philo, param);
	}
	return (NULL);
}

void	ft_start_thread(t_all_param *param, t_philo *philo)
{
	int		i;

	i = 0;
	gettimeofday(&param->start_time, NULL);
	while (i < param->num_philo)
	{
		pthread_create(&philo[i].thread, NULL, ft_simul, (void *)&philo[i]);
		i++;
	}
}

void	ft_all_detach(t_philo *philo, t_all_param *param)
{
	int		i;

	i = 0;
	while (i < param->num_philo)
	{
		pthread_detach(philo[i].thread);
		i++;
	}
}

void	ft_check_dead(t_philo *philo, t_all_param *param)
{
	int	i;
	int	j;
	int	time;

	i = 0;
	j = 0;
	while (i < param->num_philo)
	{
		time = (int)ft_diff_time(philo[i].last_time_eat);
		if (time > param->time_to_die || param->philo_die)
		{
			ft_dead(philo, param);
			break ;
		}
		if (param->stop_eat && param->stop_eat == philo[i].n_eat)
		{
			j++;
			pthread_detach(philo[i].thread);
			if (j == param->num_philo)
				break ;
		}
		if (++i == param->num_philo)
			i = 0;
	}
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_all_param	param;

	if (ft_check_arg(argc, argv, &param) || ft_init_param(&param, &philo))
	{
		printf("Error parametr\n");
		return (1);
	}
	ft_start_thread(&param, philo);
	usleep(60);
	ft_check_dead(philo, &param);
	ft_del_mut(&param);
	free(philo);
	free(param.fork);
	return (0);
}
