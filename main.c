#include<stdio.h>
#include "test.h"

// The overall syntax of a conversion specification is:

//            %[$][flags][width][.precision][length modifier]conversion

// int ft_printf(const char *, ...)
// {

// }
// Variadic function to add numbers
int AddNumbers(int n, ...)
{
    int Sum = 0;

    // Declaring pointer to the
    // argument list
    va_list ptr;

    // Initializing argument to the
    // list pointer
    va_start(ptr, n);

    for (int i = 0; i < n; i++)
{
        // Accessing current variable
        // and pointing to next one
        // printf("%d\n",va_arg(ptr, int));

        Sum += va_arg(ptr, int);
}
    // Ending argument list traversal
    va_end(ptr);

    return Sum;
}

// Driver Code
int main()
{
    printf("\n\n Variadic functions: \n");

    // Variable number of arguments
    printf("\n 1 + 2 = %d ",
           AddNumbers(2, 1, 2));

    printf("\n 3 + 4 + 5 = %d ",
           AddNumbers(3, 3, 4, 5));

    printf("\n 6 + 7 + 8 + 9 = %d ",
           AddNumbers(4, 6, 7, 8, 9));

    printf("\n");


    printf("|%d|\n",10);
    //flag '+' - display + before positive number and - before negative number
    printf("Flag '+':\n");
    printf("|%+d|\n",10);
    printf("|%+d|\n",-10);
    //flag ' ' - give space before number. If it is negative doenst give the space
    printf("Flag ' ':\n");
    printf("|% d|\n",11);
    printf("|% d|\n",-11);
    //flag '-' - left justify of the output
    printf("Flag '-':\n");
    printf("|%6d|\n",11);
    printf("|%-6d|\n",11);
    printf("|%-6d|\n",-11);
    //flag '#' - prefix 0 to the octal value and 0x to the hexadecimal value
    printf("Flag '#':\n");
    printf("|%d|\n",11);
    // printf("|%#d|\n",11); //do nothing - doesnt work
    printf("|%#o|\n",11); // convert to octonal and prefix with 0
    printf("|%#x|\n",11); // convert to hex and prefix with 0x
    printf("|%#X|\n",11); // convert to capital letter hex and prefix with 0X
    //flag '0' - Pad a field with leading zeros.
    printf("Flag '0':\n");
    printf("|%d|\n",11);
    printf("|%05d|\n",11);
    // printf("|%-05d|\n",11); // doesnt work
    //precision '.'
    printf("Precision '.':\n");
    printf("|%d|\n",11);
    printf("|%.2d|\n",11111); //it doesnt do anything.
    printf("|%.s|\n","11111"); // if doest give any number for precision, it considers 0
    printf("|%.3s|\n","123456");
    printf("|%2.5s|\n","123456");
    printf("|%-2.5s|\n","1");
    printf("|%2.5s|\n","1111111111");
    printf("|%-*.*s|\n",4,10,"1");


    //tests of all the combination with ’-0.’ and  and the field minimum width under all conversions
    int num = 111;
    // -0.
    // printf("-0. -> |%-0.d|\n",num); //no number after ., means precision 0
    // -.0
    printf("-.0 -> |%-.0d|\n",num); // precision 0
    // .-0
    // printf(".-0 -> |%.-0d|\n",num); // just print -0s
    // .0-
    // printf(".0- -> |%.0-d|\n",num); // just print -s
    // 0.-
    // printf("0.- -> |%0.-d|\n",num); // just print -s
    // 0-.
    // printf("0-. -> |%0-.d|\n",num); //no number after ., means precision 0

}

