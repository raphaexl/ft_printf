#include "includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	int		ret = 2;
	int  val = 42;
	ft_printf("Hello World  %*d\n", ret,  val);
	printf("Hello World  %*d\n", ret,  val);
 return 0;
}
