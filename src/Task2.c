#include <stdio.h>
//This Task finished By : ياسين طارق محمد 
//section : 9

void q1_largest_and_sum() {
    int arr[5], sum = 0, max;
    printf("Enter 5 integers:\n");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    max = arr[0];
    for(int i = 1; i < 5; i++)
        if(arr[i] > max)
            max = arr[i];
    printf("Largest: %d\nSum: %d\n", max, sum);
}

void q2_accept_and_print() {
    int arr[10];
    printf("Enter 10 integers:\n");
    for(int i = 0; i < 10; i++)
        scanf("%d", &arr[i]);
    printf("You entered:\n");
    for(int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void q3_reverse_array() {
    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Reversed array:\n");
    for(int i = n - 1; i >= 0; i--)
        printf("%d ", arr[i]);
    printf("\n");
}

void q4_sum_of_elements() {
    int arr[100], n, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum: %d\n", sum);
}

void q5_largest_smallest() {
    int arr[100], n, min, max;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    min = max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < min) min = arr[i];
        if(arr[i] > max) max = arr[i];
    }
    printf("Smallest: %d\nLargest: %d\n", min, max);
}

void q6_count_even_odd() {
    int arr[100], n, even = 0, odd = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] % 2 == 0) even++;
        else odd++;
    }
    printf("Even: %d\nOdd: %d\n", even, odd);
}

void q7_sort_ascending() {
    int arr[100], n, temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void q8_merge_arrays() {
    int arr1[50], arr2[50], merged[100], n1, n2;
    printf("Enter size of first array: ");
    scanf("%d", &n1);
    printf("Enter first array:\n");
    for(int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);
    printf("Enter size of second array: ");
    scanf("%d", &n2);
    printf("Enter second array:\n");
    for(int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);
    for(int i = 0; i < n1; i++)
        merged[i] = arr1[i];
    for(int i = 0; i < n2; i++)
        merged[n1 + i] = arr2[i];
    printf("Merged array:\n");
    for(int i = 0; i < n1 + n2; i++)
        printf("%d ", merged[i]);
    printf("\n");
}

void q9_remove_duplicates() {
    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n;) {
            if(arr[i] == arr[j]) {
                for(int k = j; k < n - 1; k++)
                    arr[k] = arr[k + 1];
                n--;
            } else j++;
        }
    }
    printf("Array without duplicates:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void q10_check_palindrome() {
    int arr[100], n, flag = 1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i < n / 2; i++) {
        if(arr[i] != arr[n - i - 1]) {
            flag = 0;
            break;
        }
    }
    if(flag)
        printf("The array is a palindrome.\n");
    else
        printf("The array is not a palindrome.\n");
}

int main() {
    int choice;
    do {
        printf("\nArray Task Menu:\n");
        printf("1. Q1 - Largest and Sum\n");
        printf("2. Q2 - Accept and Print\n");
        printf("3. Q3 - Reverse Array\n");
        printf("4. Q4 - Sum of Elements\n");
        printf("5. Q5 - Largest & Smallest\n");
        printf("6. Q6 - Count Even & Odd\n");
        printf("7. Q7 - Sort Ascending\n");
        printf("8. Q8 - Merge Arrays\n");
        printf("9. Q9 - Remove Duplicates\n");
        printf("10. Q10 - Check Palindrome\n");
        printf("0. Exit\n");
        printf("Choose a task (0-10): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: q1_largest_and_sum(); break;
            case 2: q2_accept_and_print(); break;
            case 3: q3_reverse_array(); break;
            case 4: q4_sum_of_elements(); break;
            case 5: q5_largest_smallest(); break;
            case 6: q6_count_even_odd(); break;
            case 7: q7_sort_ascending(); break;
            case 8: q8_merge_arrays(); break;
            case 9: q9_remove_duplicates(); break;
            case 10: q10_check_palindrome(); break;
            case 0: printf("Exiting.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while(choice != 0);
    
    return 0;
}