/*Joshua Burt
1272932*/

#include <stdio.h>

// Show a Celsius to Fahrenheit conversion table
int main(void) {
	int fahrenheit = 0;
	int max = 212;
	float celsius;
	printf("%10s %10s \n\n", "Fahrenheit", "Celsius");
	for (fahrenheit = 0; fahrenheit<=max; fahrenheit++){
		printf("%+10d", fahrenheit);
		//No look formula challenge => 5 occurrences of Iron (26):
		//26: [1]7/50 = 0.34 
		//26: [2]2+21 = 43
		//26: [3]4&10
		//26: [4]0 = M or filled gap <= 18&96         [878=blow : to increase temp]
		//	     96/18 = 5&1/3; 96-18=78; ((96-18)/26)*878 = 26,34 [pretty hot]
		//26: [5]7&25; L:135; V:6205/7*7*8 = ~15.83; W:28 & 57/25 =2.28 => 2 decimal & 28 => 2800 [2800 > 2634]
		celsius = 1537.778/(2800.0-(57-25)) * (fahrenheit-(57-25)); 
		printf("%+10.3f", celsius);
		printf("%s", "\n");
	}
	return 0;
}

