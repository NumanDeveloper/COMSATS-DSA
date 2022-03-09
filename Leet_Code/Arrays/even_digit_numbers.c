/*
Find Numbers with Even Number of Digits
Given an array nums of integers, return how many of them contain an even number of digits.

Example 1:
Input: nums = [12,345,2,6,7896]
Output: 2
Explanation:
12 contains 2 digits (even number of digits).
345 contains 3 digits (odd number of digits).
2 contains 1 digit (odd number of digits).
6 contains 1 digit (odd number of digits).
7896 contains 4 digits (even number of digits).
Therefore only 12 and 7896 contain an even number of digits.

Example 2:
Input: nums = [555,901,482,1771]
Output: 1
Explanation:
Only 1771 contains an even number of digits.
*/

#include <stdio.h>
int digits(int num);
int even_digit_number(int arr[], int size);
int main()
{
    int arr[] = {12, 345, 2, 6, 7896};
    int size = sizeof(arr) / sizeof(int);
    int even = even_digit_number(arr, size);
    printf("%d elements contain even number of digits.", even);
    return 0;
}
int digits(int num)
{
    int count = 0;
    while (num != 0)
    {
        count += 1;
        num /= 10;
    }
    return count;
}
int even_digit_number(int arr[], int size)
{
    int count, digit, even = 0;
    for (int i = 0; i < size; i++)
    {
        count = 0;
        count = digits(arr[i]);
        if (count % 2 == 0)
            even += 1;
    }
    return even;
}