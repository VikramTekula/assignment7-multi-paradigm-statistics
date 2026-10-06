#include <stdio.h>
#include <stdlib.h>

/*
 * Assignment 7: Multi-Paradigm Problem Solving
 * C Implementation - Procedural Paradigm
 *
 * Calculates:
 * 1. Mean
 * 2. Median
 * 3. Mode
 * 4. Minimum
 * 5. Maximum
 */

double calculate_mean(const int data[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += data[i];
    }

    return (double)sum / size;
}

int compare_integers(const void *a, const void *b) {
    int first = *(const int *)a;
    int second = *(const int *)b;

    return first - second;
}

double calculate_median(const int data[], int size) {
    int *sorted_data = malloc(size * sizeof(int));

    if (sorted_data == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        sorted_data[i] = data[i];
    }

    qsort(sorted_data, size, sizeof(int), compare_integers);

    double median;

    if (size % 2 == 1) {
        median = sorted_data[size / 2];
    } else {
        median = (sorted_data[(size / 2) - 1] +
                  sorted_data[size / 2]) / 2.0;
    }

    free(sorted_data);

    return median;
}

void calculate_mode(const int data[], int size) {
    int *sorted_data = malloc(size * sizeof(int));

    if (sorted_data == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        sorted_data[i] = data[i];
    }

    qsort(sorted_data, size, sizeof(int), compare_integers);

    int max_frequency = 1;
    int current_frequency = 1;

    for (int i = 1; i < size; i++) {
        if (sorted_data[i] == sorted_data[i - 1]) {
            current_frequency++;
        } else {
            if (current_frequency > max_frequency) {
                max_frequency = current_frequency;
            }

            current_frequency = 1;
        }
    }

    if (current_frequency > max_frequency) {
        max_frequency = current_frequency;
    }

    printf("Mode frequency : %d\n", max_frequency);
    printf("Mode(s)        : ");

    if (max_frequency == 1) {
        printf("No mode (all values occur once)\n");
    } else {
        int printed = 0;

        for (int i = 0; i < size; ) {
            int frequency = 1;
            int value = sorted_data[i];

            while (i + frequency < size &&
                   sorted_data[i + frequency] == value) {
                frequency++;
            }

            if (frequency == max_frequency) {
                if (printed > 0) {
                    printf(", ");
                }

                printf("%d", value);
                printed++;
            }

            i += frequency;
        }

        printf("\n");
    }

    free(sorted_data);
}

int find_minimum(const int data[], int size) {
    int minimum = data[0];

    for (int i = 1; i < size; i++) {
        if (data[i] < minimum) {
            minimum = data[i];
        }
    }

    return minimum;
}

int find_maximum(const int data[], int size) {
    int maximum = data[0];

    for (int i = 1; i < size; i++) {
        if (data[i] > maximum) {
            maximum = data[i];
        }
    }

    return maximum;
}

void print_array(const int data[], int size) {
    printf("Input data     : ");

    for (int i = 0; i < size; i++) {
        printf("%d", data[i]);

        if (i < size - 1) {
            printf(", ");
        }
    }

    printf("\n");
}

int main(void) {
    int data[] = {
        12, 7, 9, 12, 5,
        7, 12, 15, 9, 7,
        12, 5, 7, 18, 9
    };

    int size = sizeof(data) / sizeof(data[0]);

    printf("==================================================\n");
    printf("       MULTI-PARADIGM STATISTICS - C\n");
    printf("       Procedural Programming Approach\n");
    printf("==================================================\n");

    printf("Number of values: %d\n", size);

    print_array(data, size);

    printf("\nStatistics\n");
    printf("--------------------------------------------------\n");
    printf("Mean           : %.2f\n", calculate_mean(data, size));
    printf("Median         : %.2f\n", calculate_median(data, size));

    calculate_mode(data, size);

    printf("Minimum        : %d\n", find_minimum(data, size));
    printf("Maximum        : %d\n", find_maximum(data, size));

    printf("==================================================\n");

    return 0;
}
