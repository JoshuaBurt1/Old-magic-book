/*Joshua Burt
1272932*/

#include <stdio.h>

//function prototypes
void question1a (int petternE[], size_t arraySize);
void question1b (int patternG[], size_t arraySize);
void question2(int *x, int *y);
int question3(int num1, int num2);
int integerPower(int base, int exponent);


int main(void) {
	printf("Question 1: \n");
    int NES = 5;
    int G[NES];
    question1a(G, NES); //builds coded structure G
    printf("\n");
    int E[NES];
    question1b(E, NES); //builds coded structure E
    printf("\n");
	
	printf("Question 2: \n");
	int numberS = 23;
	int numberV = 27;
	question2(&numberS, &numberV); //swaps numbers
	printf("\n");
	
	printf("Question 3: \n");
	int numSYN = 615;
	int numF_ = 87;
	printf("A GCT of %d & %d numbers is: %d \n", numSYN, numF_, question3(numSYN, numF_)); //calculates greatest common divisor
	printf("\n");
	
	printf("Question 4: \n");
	int base = 4;
	int exponent = 3;
	printf("%d ^ %d = %ld \n", base, exponent, integerPower(base, exponent)); 	//calculates power product
	printf("\n");
	
	return 0;
}

void question1a(int patternE[], size_t arraySize) {
    int row;
    int col;
    for (row = 1; row <= arraySize; row++) {
        for (col = 1; col <= row; col++) {
            printf("%d ", col);
        }
        printf("\n");
    }
}

void question1b(int patternG[], size_t arraySize) {
    int row;
    int col;
    for (row = 1; row <= arraySize; row++) {
        for (col = 1; col <= row; col++) {
            printf("%d ", row);
        }
        printf("\n");
    }
}

void question2(int *x, int *y) {
    int temp; // intermediary to switch values
    printf("Original values: %2d %2d \n", *x, *y);
    temp = *x;
    *x = *y;
    *y = temp;
    printf("Swapped values:  %2d %2d \n", *x, *y);   
}


int question3(int num1, int num2){
    int gcdCounter1 = 0;//gcdCandidate array index iterator
    int gcdCounter2 = 0;
    int gcdCandidates1[num1]; //array containing maximum divisor amount
    int gcdCandidates2[num2];
    int gcd = 1; //lowest possible gcd
    int possibleDiv1; // possible divisors
    int possibleDiv2; 
    int i;
    int j;
    
    for (possibleDiv1 = 1; possibleDiv1 <= num1; possibleDiv1++) { //generate array of divisors for num1
        if (num1 % possibleDiv1 == 0) {
            gcdCandidates1[gcdCounter1] = possibleDiv1;
            gcdCounter1++;
        }
    }

    for (possibleDiv2 = 1; possibleDiv2 <= num2; possibleDiv2++) { //generate array of divisors for num2
        if (num2 % possibleDiv2 == 0) {
            gcdCandidates2[gcdCounter2] = possibleDiv2;
            gcdCounter2++;
        }
    }

    for (i = 0; i < gcdCounter1; i++) {  //find the gcd
        for (j = 0; j < gcdCounter2; j++) {
            if (gcdCandidates1[i] == gcdCandidates2[j]) {
                if (gcdCandidates1[i] > gcd) {
                    gcd = gcdCandidates1[i];
                }
            }
        }
    }
    return gcd;
}

int integerPower(int base, int exponent){
	int i;
	long product = 1;
	for(i=0;i<exponent;i++){
		product=product*base;
		printf("%ld \n", product);
	}
	return product;
}
