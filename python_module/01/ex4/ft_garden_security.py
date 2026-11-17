class Plant:
    def __init__(self, name: str, height: float, days: int):
        self.name: str = name
        if (height >= 0.0):
            self.height: float = height
        else:
            self.error_height()
        if (days >= 0):
            self.days: int = days
        else:
            self.error_age()

    def show(self):
        print(f'{self.name}: {self.height}cm, {self.days} days old')

    def grow(self):
        self.height = round(self.height + 0.8, 1)

    def age(self):
        self.days += 1

    def set_height(self, height: float):
        if (height >= 0.0):
            self.height = height
        else:
            self.error_height()

    def set_age(self, days: int):
        if (days >= 0):
            self.days = days
        else:
            self.error_age()

    def get_height(self) -> float:
        return (self.height)

    def get_age(self) -> int:
        return (self.days)

    def error_height(self) -> None:
        print(f'{self.name}: Error, height can\'t be negative')
        print('Height update rejeted')

    def error_age(self) -> None:
        print(f'{self.name}: Error, age can\'t be negative')
        print('Age update rejeted')


def main() -> None:
    print('=== Garden Security System ===')
    rose = Plant('Rose', 15.0, 10)
    print('Plant created: ', end = '')
    rose.show()
    print()
    rose.set_height = round(25)
    rose.set_age


if __name__ == '__main__':
    main()
