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


// The overall syntax of a conversion specification is:

//            %[$][flags][width][.precision]conversion

void	init_var(t_var_print *var)
{
	var->res = 0;
	var->flagzero = 0;
	var->precision = 0;
	var->flagdot = 0;
	var->width = 0;
	var->flagplus = 0;
	var->flagminus = 0;
	var->flaghash = 0;
	var->flagspace = 0;
	var->specifier = 0;
}

int	ft_print_conversion(va_list *arg, t_var_print *var)
{
	if (var->specifier == 'd' || var->specifier == 'i')

	else if (var->specifier == 'u')

	else if (var->specifier == 'c')

	else if (var->specifier == 's')

	else if (var->specifier == 'p')

	else if (var->specifier == 'x')

	else if (var->specifier == 'X')

	else if (var->specifier == '%')
}

int	read_format(char const **format, va_list *arg, t_var_print *var)
{
	int	count;
	while (!(ft_strchr(SPECIFIER, **format)) && !(**format >= '1' && **format <= '9') && **format != '.')
	{
		if(**format == '-')
			var->flagminus = 1;
		else if(**format == '+')
			var->flagplus = 1;
		else if(**format == ' ')
			var->flagspace = 1;
		else if(**format == '#')
			var->flaghash = 1;
		else if(**format == '0')
			var->flagzero = 1;
		(*format)++;
	}
	while (!(ft_strchr(SPECIFIER, **format)) && **format != '.')
	{
		if(**format >= '0' && **format <= '9')
			var->width = var->width * 10 + (**format - 48);
		(*format)++;
	}
	while (!(ft_strchr(SPECIFIER, **format)) && !(**format >= '0' && **format <= '9') )
	{
		if(**format == '.')
			var->flagdot = 1;
		(*format)++;
	}
	while (!(ft_strchr(SPECIFIER, **format)))
	{
		printf("ola");
		if(**format >= '0' && **format <= '9')
			var->precision = var->precision * 10 + (**format - 48);
		(*format)++;
	}
	var->specifier = **format;
	count = ft_print_conversion(arg, var);
	// (void)arg;
	count = 1;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	t_var_print	var;
	int			count;

	count = 0;
	init_var(&var);
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += read_format(&format, &arg, &var);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		format++;
	}
	printf("\n|dot = %d\n|hash = %d\n|minus = %d\n|plus = %d\n|space = %d\n|zero = %d\n|precision = %d\n|res = %d\n|specifier = %c\n|width = %d|\n",var.flagdot,var.flaghash,var.flagminus,var.flagplus,var.flagspace,var.flagzero,var.precision,var.res,var.specifier,var.width);
	va_end(arg);
	return (count);
}

int	main(void)
{
	int	a;
	a = ft_printf("12345%+-0 #101.101d12345");
	printf("\n%d\n",a);
	return(0);
}



// int main()
// {
// 	int	b = 12;
// 	int	c;
//     printf("|%d|\n",10);
//     //flag '+' - display + before positive number and - before negative number
//     printf("|%+d|\n",10);
//     printf("|%+d|\n",-10);
//     // printf("|%c|\n", 'a');
//     // printf("|%+s|\n", "fabio"); //error
//     // printf("|%0s|\n", "fabio"); //error
//     printf("|%0 10d|\n", b);
//     printf("|%0+10d|\n", b);
//     printf("|%- 10d|\n", b);
//     c = printf("|%-+10d|\n", b);
// 	printf("%d\n",c);
//     //flag ' ' - give space before number. If it is negative doenst give the space
//     printf("|% d|\n",11);
//     printf("|% d|\n",-11);
//     printf("flag '-' - left justify of the output\n");
//     printf("|%.d|\n",11);
//     printf("|%-6d|\n",11);
//     printf("|%-6d|\n",-11);
//     //flag '#' - prefix 0 to the octal value and 0x to the hexadecimal value
//     printf("|%d|\n",11);
//     // printf("|%#d|\n",11); //do nothing
//     printf("|%#o|\n",11); // convert to octonal and prefix with 0
//     printf("|%#x|\n",11); // convert to hex and prefix with 0x
//     printf("|%#X|\n",11); // convert to capital letter hex and prefix with 0X
//     //flag '0' - Pad a field with leading zeros.
//     printf("|%d|\n",11);// }
// // Variadic function to add numbers
// int AddNumbers(int n, ...)
// {
//     int Sum = 0;

//     // Declaring pointer to the
//     // argument list
//     va_list ptr;

//     // Initializing argument to the
//     // list pointer
//     va_start(ptr, n);

//     for (int i = 0; i < n; i++)
// 	{
//         // Accessing current variable
//         // and pointing to next one
//         // printf("%d\n",va_arg(ptr, int));
//         Sum += va_arg(ptr, int);
// 	}
//     // Ending argument list traversal
//     va_end(ptr);

//     return Sum;
// }

// // Driver Code
// int main()
// {
// 	int	b = 12;
// 	int	c;
//     printf("\n\n Variadic functions: \n");

//     printf("|%d|\n",10);
//     //flag '+' - display + before positive number and - before negative number
//     printf("|%+d|\n",10);
//     printf("|%+d|\n",-10);
//     // printf("|%c|\n", 'a');
//     // printf("|%+s|\n", "fabio"); //error
//     // printf("|%0s|\n", "fabio"); //error
//     printf("|%0 10d|\n", b);
//     printf("|%0+10d|\n", b);
//     printf("|%- 10d|\n", b);
//     c = printf("|%-+10d|\n", b);
// 	printf("%d\n",c);
//     //flag ' ' - give space before number. If it is negative doenst give the space
//     printf("|% d|\n",11);
//     printf("|% d|\n",-11);
//     printf("flag '-' - left justify of the output\n");
//     printf("|%.d|\n",11);
//     printf("|%-6d|\n",11);
//     printf("|%-6d|\n",-11);
//     //flag '#' - prefix 0 to the octal value and 0x to the hexadecimal value
//     printf("|%d|\n",11);
//     // printf("|%#d|\n",11); //do nothing
//     printf("|%#o|\n",11); // convert to octonal and prefix with 0
//     printf("|%#x|\n",11); // convert to hex and prefix with 0x
//     printf("|%#X|\n",11); // convert to capital letter hex and prefix with 0X

//     //flag '0' - Pad a field with leading zeros.
//     printf("|%d|\n",11);
//     printf("|%05d|\n",11);
// 	printf("|%-10x|\n",11);
//     // printf("|%-05d|\n",11);

//     printf("precision '.'\n");
//     printf("|%d|\n",11);
//     //printf("|%.p|\n",&b); error
//     printf("|%+.10d|\n",11111);
// 	printf("|%0+10.d|\n",11111);
// 	printf("|%0+10d|\n",11111);
// 	printf("|%0+15.10d|\n",11111);
// 	printf("|%+15.10d|\n",11111);
//     printf("|%.s|\n","11111"); // if doest give any number for precision, it considers 0
//     printf("|%.s|\n","a");
//     printf("|%.3s|\n","11111");
//     printf("|%2.5s|\n","1");
//     printf("|%-2.5s|\n","1");
//     printf("|%2.5s|\n","1111111111");
//     printf("|%-*.*s|\n",4,10,"1");


//     //tests of all the combination with ’-0.’ and  and the field minimum width under all conversions

//     // -0.
//     // printf("-0. -> |%-0.s|\n","111"); //no number after ., means precision 0
//     // -.0
//     printf("-.0 -> |%-.0s|\n","111"); // precision 0
//     // .-0
//     // printf(".-0 -> |%.-0s|\n","111"); // just print -0s
//     // .0-
//     // printf(".0- -> |%.0-s|\n","111"); // just print -s
//     // 0.-
//     // printf("0.- -> |%0.-s|\n","111"); // just print -s
//     // 0-.
//     // printf("0-. -> |%0-.s|\n","111"); //no number after ., means precision 0

//     int a = printf("%d",-12345);
//     printf("\n%d\n",a);
//     printf("%%\n");

//     printf("|%05d|\n",11);
// 	printf("|%-10x|\n",11);
//     // printf("|%-05d|\n",11);
//     printf("precision '.'\n");
//     printf("|%d|\n",11);
//     //printf("|%.p|\n",&b); error
//     printf("|%.d|\n",11111); //it doesnt do anything.
//     printf("|%.s|\n","11111"); // if doest give any number for precision, it considers 0
//     printf("|%.s|\n","a");
//     printf("|%.3s|\n","11111");
//     printf("|%2.5s|\n","1");
//     printf("|%-2.5s|\n","1");
//     printf("|%2.5s|\n","1111111111");
//     printf("|%-*.*s|\n",4,10,"1");


//     //tests of all the combination with ’-0.’ and  and the field minimum width under all conversions

//     // -0.
//     // printf("-0. -> |%-0.s|\n","111"); //no number after ., means precision 0
//     // -.0
//     printf("-.0 -> |%-.0s|\n","111"); // precision 0
//     // .-0
//     // printf(".-0 -> |%.-0s|\n","111"); // just print -0s
//     // .0-
//     // printf(".0- -> |%.0-s|\n","111"); // just print -s
//     // 0.-
//     // printf("0.- -> |%0.-s|\n","111"); // just print -s
//     // 0-.
//     // printf("0-. -> |%0-.s|\n","111"); //no number after ., means precision 0


//     printf("%%\n");
// }

