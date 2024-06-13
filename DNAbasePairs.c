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
	     
	// 23:27                                             *pattern: 23/27=0.851...*
	// "So We revealed"	            W : 1                #pattern: 27/23= 1.17#   
	//                             #7 : 1#       
	//[80]+ 1 + 6 + 8 + [10] + 50 + 1 = 156 
	//          6,1,50,8,1            : 156,08,01        *order to pattern "158"*
	//          615.81                : 615.81           *replace 1 with 7; pattern 1.17*
	//                         615.87 : 615.87           *average DNA base pair mass*
	//
	// "the ark"           W : 5
    //                    #5 : 1#                        *note: average = mesos = 515 (A.Greek); however it is broken 5:1:5*
 	// 1 + 30 + 80 + 30 + 20 = 161  
	// 1,30,80,30,20         : 615  	 				 *replace 1 with 5*
	// 1,20                  : 615,03,08,03
	//                       : 615.383  				 *AT DNA base pair mass*
    //                                                                                              
	//        Left (decimal) : Right (whole)             *observe left and right leftover numbers*  
	//                    #1 : 1#       				 
	// 1                  20                             *keep AT value = 615.383*
	// 
	// 1,1,20                : 616.383  				 *add 1 (whole #)*   
	// 1,20                  : 616.373  				 *subtract 0.01*
	// 1                     : 616.3710                  *subtract 0.0020*
	//                       : 616.3711                  *add 0.0001; GC DNA base pair mass*  
	//                
	
	//Scientific value of 615.87 references: 
	// 1. https://www.protocol-online.org/biology-forums-2/posts/27692.html
	// "Based on that papers' calculations, the sizes of a base pair (accounting for loss of a water molecule on each strand in polymerization and a proton from each phosphate hydroxyl due to the pH) should be:
	// GC: 347.2207+307.1966-(4x1.0079+2x15.9994)-(2x1.0079)= 616.3711
	// AT: 331.2213+322.2079-(4x1.0079+2x15.9994)-(2x1.0079)= 615.383
    // average: 615.8771" 
	// 2. https://onlinelibrary.wiley.com/doi/10.1002/cyto.a.10013
	//
	//Contextual reference match:
	// 1. Various creation stories => "Build the Ark ... take on board a ""pair"" from every species"; 
	// A. Other old magic book
	// "Make ... an ark"; Chapter 6, 10th Hebrew patriarch: Noah (Hebrew=50+8) & 1st mention 5:29 (29/5=5.8) => 615.8_  Ref: https://mechon-mamre.org/p/pt/pt0106.htm
	// B. Translation and ammended version of Other old magic book
	// "Make ... an ark"; Chapter 6, 10th Hebrew patriarch: Noah (A.Greek=50+800+5) & 1st mention 5:29 (29/5=5.8) => 615.8_  Ref: https://www.blueletterbible.org/lxx/gen/6/1/s_6001
	// 2. Voynich Manuscript: page 75, 1st "DNA page", 6 & 8 nymphs in divided pools => 615.87
	// 3. Dune (1[9]65): https://www.youtube.com/watch?v=124xCHfVUk4
	                                                
	printf("Question 3: \n");
	int numBasePair = 615;
	int numMassAverage = 87;
	printf("A GCT of %d & %d numbers is: %d \n", numBasePair, numMass, question3(numBasePair, numMass)); //calculates greatest common divisor
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
    y = &temp;
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
