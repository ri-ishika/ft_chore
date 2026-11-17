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
    oak = Plant('Oak', 200.0, 365)
    cactus = Plant('Cactus', 5.0, 90)
    sunflower = Plant('Sunflower', 80.0, 45)
    fern = Plant('Fern', 15.0, 120)
    print('=== Plant Factory Output ===')
    rose.show()
    oak.show()
    cactus.show()
    sunflower.show()
    fern.show()


if __name__ == '__main__':
    main()
