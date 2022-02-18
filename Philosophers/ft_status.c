#include "philo.h"

void	ft_status_out(int status, t_philo *philo, t_all_param *param)
{
	pthread_mutex_lock(&param->st_out);
	if (status == FORK && !param->philo_die)
		printf("%lu %d\thas taken a fork\n", ft_diff_time(param->start_time),
			philo->id);
	else if (status == EAT && !param->philo_die)
		printf("%lu %d\tis eating\n", ft_diff_time(param->start_time),
			philo->id);
	else if (status == SLEEP && !param->philo_die)
		printf("%lu %d\tis sleeping\n", ft_diff_time(param->start_time),
			philo->id);
	else if (status == THINK && !param->philo_die)
		printf("%lu %d\tis thinking\n", ft_diff_time(param->start_time),
			philo->id);
	pthread_mutex_unlock(&param->st_out);
}

void	ft_eating(t_philo *philo, t_all_param *param)
{
	pthread_mutex_lock(philo->right_fork);
	ft_status_out(FORK, philo, param);
	if (param->num_philo == 1)
	{
		ft_wait(param->start_time, param->time_to_die);
		param->philo_die++;
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	ft_status_out(FORK, philo, param);
	gettimeofday(&philo->last_time_eat, NULL);
	ft_status_out(EAT, philo, param);
	ft_wait(param->start_time, param->time_to_eat);
	philo->n_eat++;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	ft_sleeping(t_philo *philo, t_all_param *param)
{
	ft_status_out(SLEEP, philo, param);
	ft_wait(param->start_time, param->time_to_sleep);
}

void	ft_thinking(t_philo *philo, t_all_param *param)
{
	ft_status_out(THINK, philo, param);
}

void	ft_dead(t_philo *philo, t_all_param *param)
{
	param->philo_die = 1;
	pthread_mutex_lock(&param->st_out);
	printf("%lu %d\t\e[31mdied\n", ft_diff_time(param->start_time), philo->id);
	ft_all_detach(philo, param);
}
