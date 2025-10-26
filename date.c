#include <stdio.h>
#include <stdlib.h>

struct date {
    int day;
    int month;
    int year;
};
typedef struct date date;

// Function to read date
void readdate(date* d) {
    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &d->day, &d->month, &d->year);
}

// Function to display date
void printdate(date d) {
    printf("%02d/%02d/%04d\n", d.day, d.month, d.year);
}

// Function to compare two dates
int comparedates(date d1, date d2) {
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
        return 1;
    else
        return 0;
}

// Main function
int main() {
    date date1, date2;

    printf("Enter first date:\n");
    readdate(&date1);

    printf("Enter second date:\n");
    readdate(&date2);

    printf("\nFirst date: ");
    printdate(date1);

    printf("Second date: ");
    printdate(date2);

    if (comparedates(date1, date2))
        printf("\n? Dates are equal.\n");
    else
        printf("\n? Dates are not equal.\n");

    return 0;
}

