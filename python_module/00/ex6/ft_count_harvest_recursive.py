def recursive_main(i: int, days: int):
    if (i <= days):
        print(f'Day {i}')
        recursive_main(i + 1, days)

def ft_count_harvest_recursive():
    days = int(input('Days until harvest: '))
    recursive_main(1, days)
    print('Harvest time!')
