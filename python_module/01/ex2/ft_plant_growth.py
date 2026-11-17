class Plant:
    def __init__(self, name: str, height: float, days: int):
        self.name: str = name
        self.height: float = height
        self.days: int = days

    def show(self):
        print(f'{self.name}: {self.height}cm, {self.days} days old')

    def grow(self):
        self.height = round(self.height + 0.8, 1)

    def age(self):
        self.days += 1


def main() -> None:
    rose = Plant('Rose', 25.0, 30)
    print('=== Garden Plant Growth ===')
    rose.show()
    for i in range(7):
        rose.grow()
        rose.age()
        print(f'=== Day {i + 1} ===')
        rose.show()
    print(f'Growth this week: {round(rose.height - 25, 1)}cm')


if __name__ == '__main__':
    main()
