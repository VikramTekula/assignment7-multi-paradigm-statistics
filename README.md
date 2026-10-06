# Assignment 7: Multi-Paradigm Problem Solving

## Overview

This project demonstrates how the same statistical problem can be solved using three different programming paradigms. The program calculates the **mean, median, and mode** of a list of integers using C, OCaml, and Python.

Each language demonstrates a different programming approach:

- **C** — Procedural programming
- **OCaml** — Functional programming
- **Python** — Object-oriented programming

Additional functionality was included to calculate the minimum and maximum values.

## Project Structure

```text
assignment7-multi-paradigm-statistics/
│
├── c/
│   └── statistics.c
│
├── ocaml/
│   └── statistics.ml
│
├── python/
│   └── statistics.py
│
├── .gitignore
├── README.md
└── run_all.sh
```

## Dataset

All three implementations use the same dataset:

```text
12, 7, 9, 12, 5, 7, 12, 15, 9, 7, 12, 5, 7, 18, 9
```

The programs calculate the mean, median, and mode and additionally report the minimum and maximum values.

## Requirements

The following software should be installed before running the project:

```text
GCC
OCaml
Python 3
```

Check the installed versions with:

```bash
gcc --version
ocaml --version
python3 --version
```

No external Python packages are required.

## Running the C Program

Compile the C source code from the project root:

```bash
gcc -std=c17 -Wall -Wextra -pedantic c/statistics.c -o c/statistics
```

Run the program:

```bash
./c/statistics
```

The C implementation demonstrates procedural programming through functions, arrays, loops, sorting, and explicit memory management.

## Running the OCaml Program

Compile the OCaml source code:

```bash
ocamlc -o ocaml/statistics ocaml/statistics.ml
```

Run the compiled program:

```bash
./ocaml/statistics
```

The OCaml implementation demonstrates functional programming through immutable lists and higher-order functions including `List.fold_left`, `List.map`, `List.filter_map`, and `List.sort_uniq`.

## Running the Python Program

Run the Python implementation directly:

```bash
python3 python/statistics.py
```

The Python implementation uses the `StatisticsCalculator` class to encapsulate the dataset and statistical operations, demonstrating object-oriented programming.

## Running All Implementations

A shell script is included to compile and execute all three implementations:

```bash
chmod +x run_all.sh
./run_all.sh
```

This provides a convenient way to verify that the three implementations produce consistent results.

## Expected Results

All three programs should produce the following statistical results:

```text
Number of values: 15
Mean           : 9.73
Median         : 9.00
Mode frequency : 4
Mode(s)        : 7, 12
Minimum        : 5
Maximum        : 18
```

The identical results demonstrate that the statistical logic was implemented correctly across the three programming paradigms.

## Paradigm Comparison

The C implementation focuses on sequential procedures and explicit control over data and memory. The OCaml implementation emphasizes functional transformations and immutable data. The Python implementation organizes data and operations within the `StatisticsCalculator` class.

The project demonstrates that different programming paradigms can produce the same computational result while requiring different approaches to program design, data management, and problem solving.

## Documentation

The accompanying report compares the three implementations and discusses the challenges, differences, and lessons learned from using procedural, functional, and object-oriented programming.

Screenshots of the source code and program output are included in the submitted report as required by the assignment.
