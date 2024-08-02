# ChiSquareFrequencyTest
A C program that performs a chi-square test on binary data to evaluate the frequency of 0s and 1s, providing detailed statistical analysis and hypothesis testing.


This repository contains a C program that performs a chi-square test on a binary dataset to evaluate the frequency of 0s and 1s. The program reads data from a file, allows the user to choose a significance level, and prints the results of the chi-square test, including whether the null hypothesis can be rejected based on the observed frequencies. The tool is useful for statistical analysis and hypothesis testing in various applications.


- Reads binary data from a file
- Allows user to choose from multiple significance levels
- Performs chi-square test to determine if observed frequencies differ significantly from expected frequencies
- Provides detailed output on the test results and hypothesis evaluation

gcc -o chi_square_test randomness_test.c -lm

./chi_square 1000 random_binary_file.txt


./chi_square_test <size_of_probe> <probe_filename>

<size_of_probe>: The number of data points to read from the file.

<probe_filename>: The name of the file containing the binary data (0s and 1s).
