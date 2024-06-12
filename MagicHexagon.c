/*Joshua Burt
1272932*/

#include <stdio.h>
#include <string.h>

//L: 8
int main(void) {
	
	char string1[38] = "Magic hexagon order n=3, M=38";	
	char string2[38] = "And others bound together in chains";
	char string3[38] = "be";
	char string4[38] = "There are 19!=1.216451e+17 arrangement";
	char string5[38] = "Hence, L22,V1615,W4: 121645_ & R:2!=1";
	char string6[38] = "-> magic hex chain pat.: 1,6 & 12 pat.";
	char *strings[] = {string1, string2, string3, string4, string5, string6};
	int arrayLength = sizeof(strings) / sizeof(strings[0]);
	
	int i;
	for(i = 0; i < arrayLength; i++){
		if (strings[i][0] == 'b' || strings[i][0] == 'B') {
			printf("%s \n", strings[i]);
		}
	}
	return 0;
}
