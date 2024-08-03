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

The program reads binary data (0s and 1s) from a specified file. It stores this data in an array, up to the size specified by the user.

After running the program, follow the prompts to choose a significance level and print the data if desired. The program will output the results of the chi-square test, including the observed and expected frequencies, the chi-square value, and whether the null hypothesis can be rejected at the chosen significance level.


The chi-square test is used to determine if the observed frequency of 0s and 1s significantly deviates from the expected frequency. For binary data, the expected frequency for each value (0 and 1) is typically the total number of data points divided by 2.


Chi-square formula is a statistical formula to compare two or more statistical data sets. It is used for data that consist of variables distributed across various categories and is denoted by χ2.

The chi-square formula is: χ2 = ∑(Oi – Ei)2/Ei, where Oi = observed value (actual value) and Ei = expected value.


The user is prompted to choose a significance level (probability level), which determines the critical value for the chi-square test.

Based on the chosen significance level, the program compares the calculated chi-square statistic with the critical value to decide whether to reject the null hypothesis (that the observed frequencies match the expected frequencies).
