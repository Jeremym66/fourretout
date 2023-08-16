- `./philo 1 800 200 200`	=> one death at 800 ms
- `./philo 3 500 200 400`	=> one death at 500 ms
- `./philo 5 800 200 200`	=> infinite
- `./philo 4 310 200 100`	=> one death at 310 ms
- `./philo 4 410 200 200`	=> infinite
- `./philo 4 200 210 200`	=> one death at 200 ms
- `./philo 4 311 150 150`	=> infinite
- `./philo 4 311 150 162`	=> one death at 462 ms or more

- `./philo x 100 50 50`
if x mod 2 == 0
	=> infinite
else
	=> one death at 100ms
