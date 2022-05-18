#include <stdarg.h>
#include <stdlib.h>
#include "main.h"


/**
 * _printf - print a formatted output.
 *
 * @format: string pointer to print - may contain directives.
 *
 * Return: # of characters printed.
 */

int _printf(const char *format, ...)
{ 
	va_list varAargs;
	int counter;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
								
	va_start(varAargs, format);
	counter = printf_output(format, varAargs);
	
	va_end(varAargs);
							
return (counter); 
}


/**
 * print_output - print a formatted output.
 *
 * @format: string pointer to print - may contain directives.
 * @val: Variable number of arguments.
 *
 * Return: # of characters printed.
 */
 
int printf_output(const char *format, va_list val)
{
	int i = 0, j=0, k = 0;
	char *tmps, tmpd[20], c;
	
	while (format[i])
	{
		if(format[i] == '%')
	  	{
	  		if (format[i + 1] == '%')
			{
				_putchar(format[i]);
			    i++;
				j++;
			}
			else if (format[i + 1] == '\0')
			{
				_putchar(format[i]);
				j++;
				return (j);
			}
			else
			{
				i++;
		 		switch (format[i]) 
		 		{
			 	    case 'c': 
			 	        c = (char)va_arg(val, int);
			 	        _putchar(c);
			 	        j++; 
			 	        break;
	
				    case 's':
				      	tmps = va_arg(val, char*);
						if (tmps == NULL)
							return (NULL);
	
						while(tmps[k])
						{
							_putchar(tmps[k++]);
							j++;
						}
				        break;
	
			 	    case 'd':
			 	    case 'i':
			 	        j += printf_int(val);
				        break;
						
					default:
						_putchar(format[i]);
						++j;
		        }
		    }
	    }
	    else
	    {
		   	_putchar(format[i]);
		   	++j;
		}
		++i;
	}

return (j);
 }
 
 
 /**
 * print_i - prints int func
 * @arg: int to print
 * Return: number of ints printed
 */
int printf_int(va_list arg)
{
	int num = va_arg(arg, int);
	unsigned int count = 0, revNum, temp;
	int i = 0, j = 0;
	char table [41];

	if (num < 0)
	{
		_putchar('-');
		count++;
		revNum = -num;
	}
	else
		revNum = num;

	if (revNum > 0)
	{
		temp = revNum;
		while (temp)
		{
			temp /= 10;
			i++;
		}
		
		while (revNum != 0)
		{
			table[j++] = (revNum % 10) + '0';
			revNum /= 10;
		}
		i--;
		while (i >= 0)
		{
			_putchar(table[i--]);
			count++;
		}
	}
	else
	{
		_putchar('0');
		count++;
	}

	return (count);
}