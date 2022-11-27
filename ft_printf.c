/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvalli-v <fvalli-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:22:13 by fvalli-v          #+#    #+#             */
/*   Updated: 2022/11/27 18:05:48 by fvalli-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "ft_printf.h"
#include "libft.h"

// The overall syntax of a conversion specification is:

//            %[$][flags][width][.precision]conversion

/*void	init_var(t_var_print *var)
{
	var->res = 0;
	var->flagzero = 0;
	var->precision = 0;
	var->width = 0;
	var->flagplus = 0;
	var->flagminus = 0;
	var->flaghash = 0;
	var->flagspace = 0;
}*/

// int	ft_printf(const char *format, ...)
// {
// 	va_list	arg;
// 	t_var_print *var;
// 	int		i;

// 	i = 0;
// 	// init_var(var);
// 	va_start(arg, format);
// 	while (*(format + i))
// 	{
// 		if (*(format + i) == '%')
// 		{

// 		}
// 		else
// 		{
// 			ft_putchar_fd(*(format + i),1);
// 		}
// 	}


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

    int b = 12;
    printf("|%d|\n",10);
    //flag '+' - display + before positive number and - before negative number
    printf("|%+d|\n",10);
    printf("|%+d|\n",-10);
    // printf("|%c|\n", 'a');
    // printf("|%+s|\n", "fabio"); //error
    // printf("|%0s|\n", "fabio"); //error
    printf("|%0 10d|\n", b);
    printf("|%0+10d|\n", b);
    printf("|%- 10d|\n", b);
    printf("|%-+10d|\n", b);
    //flag ' ' - give space before number. If it is negative doenst give the space
    printf("|% d|\n",11);
    printf("|% d|\n",-11);
    //flag '-' - left justify of the output
    printf("|%6d|\n",11);
    printf("|%-6d|\n",11);
    printf("|%-6d|\n",-11);
    //flag '#' - prefix 0 to the octal value and 0x to the hexadecimal value
    printf("|%d|\n",11);
    // printf("|%#d|\n",11); //do nothing
    printf("|%#o|\n",11); // convert to octonal and prefix with 0
    printf("|%#x|\n",11); // convert to hex and prefix with 0x
    printf("|%#X|\n",11); // convert to capital letter hex and prefix with 0X
    //flag '0' - Pad a field with leading zeros.
    printf("|%d|\n",11);
    printf("|%05d|\n",11);
    // printf("|%-05d|\n",11);
    //precision '.'
    printf("|%d|\n",11);
    printf("|%.2d|\n",11111); //it doesnt do anything.
    printf("|%.s|\n","11111"); // if doest give any number for precision, it considers 0
    printf("|%.3s|\n","11111");
    printf("|%2.5s|\n","1");
    printf("|%-2.5s|\n","1");
    printf("|%2.5s|\n","1111111111");
    printf("|%-*.*s|\n",4,10,"1");


    //tests of all the combination with ’-0.’ and  and the field minimum width under all conversions

    // -0.
    // printf("-0. -> |%-0.s|\n","111"); //no number after ., means precision 0
    // -.0
    printf("-.0 -> |%-.0s|\n","111"); // precision 0
    // .-0
    // printf(".-0 -> |%.-0s|\n","111"); // just print -0s
    // .0-
    // printf(".0- -> |%.0-s|\n","111"); // just print -s
    // 0.-
    // printf("0.- -> |%0.-s|\n","111"); // just print -s
    // 0-.
    // printf("0-. -> |%0-.s|\n","111"); //no number after ., means precision 0

    int a = printf("%d",-12345);
    printf("\n%d\n",a);

}

