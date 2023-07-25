#include "main.h"

int _printf(const char *format, ...)
{
va_list args;
int i, len;
va_start(args, format);
for (i = 0, len = 0; format[i]; i++)
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
len += print_c(args);
break;
case 's':
len += print_s(args);
break;
case '%':
len += print_percent(args);
break;
default:
_putchar(format[i - 1]);
_putchar(format[i]);
len += 2;
}
}
else
{
_putchar(format[i]);
len++;
}
}
va_end(args);
return (len);
}

int print_c(va_list args)
{
char c = va_arg(args, int);
_putchar(c);
return (1);
}

int print_s(va_list args)
{
char *str;
str = va_arg(args, char *);
int len;
len = 0;
if (!str)
str = "(null)";
while (str[len])
{
_putchar(str[len]);
len++;
}
return (len);
}
int print_percent(va_list args)
{
(void)args;
_putchar('%');
return (1);
}
