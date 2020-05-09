
#include <stdio.h>
#include <stdlib.h>

char* myStringCatenate(char c[] , const char* destinationString,const char* sourceString)
{
	int i = 0;
	
	while (*destinationString != '\0') {
		c[i] = *destinationString;
		destinationString++;
		i++;
	}
	c[i] = '\ ';
	i++;

	while ( *sourceString != '\0' ) {
		c[i] = *sourceString;
		sourceString++;
		i++;
	}

	//printf("function test %s\n",c);

	return c;
}

int main()
{
	char a[500] = { 0 };
	char* des = "hello";
	char* src = "world";
	char* result;

	result = myStringCatenate(a, des, src);

	printf("%s\n",result);
	
	return 0;
}
