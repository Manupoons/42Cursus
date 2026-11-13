# philo

The classic Dining Philosophers problem, solved with threads and mutexes. Each philosopher is a thread that alternates between eating, sleeping and thinking, and needs two forks (mutexes) to eat.

```
make
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

Times are in milliseconds. The simulation stops when a philosopher dies, or when everyone has eaten the required number of times (if given). A separate monitor thread checks for deaths.
