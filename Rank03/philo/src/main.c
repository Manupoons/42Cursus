#include "philo.h"

#define NUM_PHILOSOPHERS 4

pthread_mutex_t forks[NUM_PHILOSOPHERS];
t_philo philosophers[NUM_PHILOSOPHERS];

void *philosopher_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	while (1) // Infinite loop representing the philosopher's life cycle
	{
		printf("Philosopher %d is thinking...\n", philo->id);

		// Try to pick up forks (mutex lock)
		pthread_mutex_lock(philo->left_fork);
		printf("Philosopher %d picked up left fork\n", philo->id);

		pthread_mutex_lock(philo->right_fork);
		printf("Philosopher %d picked up right fork\n", philo->id);

		// Eating
		printf("Philosopher %d is eating...\n", philo->id);
		philo->meals_eaten++;
		philo->last_meal_time = get_current_time();

		// Put down forks (mutex unlock)
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);

		printf("Philosopher %d is sleeping...\n", philo->id);
		usleep(1000); // Simulate sleep
	}
	return NULL;
}

int main()
{
	int i;

	// Initialize mutexes (forks)
	for (i = 0; i < NUM_PHILOSOPHERS; i++)
		pthread_mutex_init(&forks[i], NULL);

	// Initialize philosophers
	for (i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		philosophers[i].id = i;
		philosophers[i].meals_eaten = 0;
		philosophers[i].last_meal_time = get_current_time();
		philosophers[i].left_fork = &forks[i];
		philosophers[i].right_fork = &forks[(i + 1) % NUM_PHILOSOPHERS];

		pthread_create(&philosophers[i].philo_thread, NULL, philosopher_routine, &philosophers[i]);
	}

	// Wait for threads to finish (they run infinitely, so this is for simulation purposes)
	for (i = 0; i < NUM_PHILOSOPHERS; i++)
		pthread_join(philosophers[i].philo_thread, NULL);

	// Destroy mutexes
	for (i = 0; i < NUM_PHILOSOPHERS; i++)
		pthread_mutex_destroy(&forks[i]);

	return 0;
}
