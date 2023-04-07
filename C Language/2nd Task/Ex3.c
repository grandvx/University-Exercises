//Without the if statement
#include <stdio.h>

int main() {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month, year;
    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);
    int days_in_month = days[month] + (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    printf("Number of days in month %d of year %d is: %d\n", month, year, days_in_month);
    return 0;
}
