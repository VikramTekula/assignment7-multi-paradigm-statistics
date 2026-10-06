"""
Assignment 7: Multi-Paradigm Problem Solving
Python Implementation - Object-Oriented Paradigm

Calculates:
1. Mean
2. Median
3. Mode
4. Minimum
5. Maximum
"""


class StatisticsCalculator:
    """Calculate descriptive statistics for a list of integers."""

    def __init__(self, data):
        if not data:
            raise ValueError("The data list cannot be empty.")

        if not all(isinstance(value, int) for value in data):
            raise TypeError("All data values must be integers.")

        self.data = data.copy()

    def calculate_mean(self):
        """Calculate and return the arithmetic mean."""
        return sum(self.data) / len(self.data)

    def calculate_median(self):
        """Calculate and return the median."""
        sorted_data = sorted(self.data)
        length = len(sorted_data)

        middle = length // 2

        if length % 2 == 1:
            return float(sorted_data[middle])

        return (
            sorted_data[middle - 1] +
            sorted_data[middle]
        ) / 2

    def calculate_mode(self):
        """Calculate and return all modes and their frequency."""
        frequencies = {}

        for value in self.data:
            frequencies[value] = frequencies.get(value, 0) + 1

        maximum_frequency = max(frequencies.values())

        if maximum_frequency == 1:
            return [], maximum_frequency

        modes = [
            value
            for value, frequency in frequencies.items()
            if frequency == maximum_frequency
        ]

        return sorted(modes), maximum_frequency

    def calculate_minimum(self):
        """Return the minimum value."""
        return min(self.data)

    def calculate_maximum(self):
        """Return the maximum value."""
        return max(self.data)

    def display_statistics(self):
        """Display all calculated statistics."""
        modes, mode_frequency = self.calculate_mode()

        print("==================================================")
        print("       MULTI-PARADIGM STATISTICS - PYTHON")
        print("       Object-Oriented Programming Approach")
        print("==================================================")

        print(f"Number of values: {len(self.data)}")
        print(f"Input data     : {', '.join(map(str, self.data))}")

        print("\nStatistics")
        print("-" * 50)

        print(f"Mean           : {self.calculate_mean():.2f}")
        print(f"Median         : {self.calculate_median():.2f}")
        print(f"Mode frequency : {mode_frequency}")

        if modes:
            print(
                "Mode(s)        : " +
                ", ".join(map(str, modes))
            )
        else:
            print("Mode(s)        : No mode (all values occur once)")

        print(f"Minimum        : {self.calculate_minimum()}")
        print(f"Maximum        : {self.calculate_maximum()}")

        print("=" * 50)


def main():
    """Create the calculator and display the results."""

    data = [
        12, 7, 9, 12, 5,
        7, 12, 15, 9, 7,
        12, 5, 7, 18, 9
    ]

    calculator = StatisticsCalculator(data)
    calculator.display_statistics()


if __name__ == "__main__":
    main()
