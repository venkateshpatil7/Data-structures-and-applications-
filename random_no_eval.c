#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int a[], int n);
void read_array(int a[], int n);
void bubble_sort(int a[], int n);
void selection_sort(int a[], int n);
void rand_numbers(int n, int lower, int upper, FILE *fp);
void read_array_file(int a[], FILE *fp, int n);
void print_num_file(int n, int a[], FILE *fp);

int main()
{
    FILE *fp;
    FILE *fp1;
    FILE *fp2;
    int a[10];

    fp = fopen("input.txt", "w");
    rand_numbers(10, 40, 100, fp);
    fclose(fp);

    fp1 = fopen("input.txt", "r");
    read_array_file(a, fp1, 10);
    fclose(fp1);

    printf("Original array: ");
    print_array(a, 10);

    bubble_sort(a, 10);
    printf("Array after bubble sort: ");
    print_array(a, 10);

    selection_sort(a, 10);
    printf("Array after selection sort: ");
    print_array(a, 10);

    fp2 = fopen("output.txt", "w");
    print_num_file(10, a, fp2);
    fclose(fp2);

    return 0;
}

void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void read_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void selection_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}

void rand_numbers(int n, int lower, int upper, FILE *fp)
{
    int num;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        num = lower + rand() % (upper - lower + 1);
        fprintf(fp, "%d ", num);
    }
}

void read_array_file(int a[], FILE *fp, int n)
{
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &a[i]);
    }
}

void print_num_file(int n, int a[], FILE *fp)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", a[i]);
    }
}

