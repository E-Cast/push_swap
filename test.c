#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc <= 1)
		return (1);
	printf("Hello %s, %i", argv[1], argc);
}
