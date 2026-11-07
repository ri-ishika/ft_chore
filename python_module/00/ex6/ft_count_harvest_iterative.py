def ft_count_harvest_iterative() -> None:
    days = input('Days until harvest: ')
    for i in range(int(days)):
        print(f'Day {i + 1}')
    print('Harvest time!')
