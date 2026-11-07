def ft_harvest_total() -> None:
    harvest: list[int] = []
    harvest.append(int(input('Day 1 harvest: ')))
    harvest.append(int(input('Day 2 harvest: ')))
    harvest.append(int(input('Day 3 harvest: ')))
    total: int = harvest[0] + harvest[1] + harvest[2]
    print(f'Total harvest: {total}')
