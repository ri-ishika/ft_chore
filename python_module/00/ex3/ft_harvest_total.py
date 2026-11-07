def ft_harvest_total() -> None:
    total = 0
    for i in range(3):
        harvest = int(input(f'Day {i + 1} harvest: '))
        total += harvest
    print(f'Total harvest: {total}')
