#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
  int len = 5;
  int *ptr = &len;

  	_printf("Let's try to printf a simple sentence.\n");
	printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len, len);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("pointer:[%p]\n", ptr);
	printf("pointer:[%p]\n", ptr);
	return (0);
}
