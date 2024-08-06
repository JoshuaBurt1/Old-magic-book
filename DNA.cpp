//How to remember DNA values
//TODO: make a menu structure by topic

#include <stdio.h>

// Function prototypes
void question1a(int patternE[], size_t arraySize);
void question1b(int patternG[], size_t arraySize);
void question2(int* x, int* y);
int question3(int num1, int num2);
long integerPower(int base, int exponent);

int main(void) {
    printf("Question 1: \n");
    const int NES = 5;
    int G[NES];
    question1a(G, NES); // Builds coded structure G
    printf("\n");
    int E[NES];
    question1b(E, NES); // Builds coded structure E
    printf("\n");

    printf("Question 2: \n");
    int numberS = 23;
    int numberV = 27;
    question2(&numberS, &numberV); // Swaps numbers
    printf("\n");

    printf("Question 3: \n");
    int numBasePair = 615;
    int numMassAverage = 87;
    printf("The GCT of %d & %d numbers is: %d \n", numBasePair, numMassAverage, question3(numBasePair, numMassAverage)); // Calculates greatest common divisor
    printf("\n");

    printf("Question 4: \n");
    int base = 4;
    int exponent = 3;
    printf("%d ^ %d = %ld \n", base, exponent, integerPower(base, exponent)); // Calculates power product
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

void question2(int* x, int* y) {
    int temp; // intermediary to switch values
    printf("Original values: %2d %2d \n", *x, *y);
    temp = *x;
    *x = *y;
    *y = temp;
    printf("Swapped values:  %2d %2d \n", *x, *y);
}

int question3(int num1, int num2) {
    int gcd = 1; // Lowest possible gcd
    int i;

    for (i = 1; i <= num1 && i <= num2; ++i) {
        if (num1 % i == 0 && num2 % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

long integerPower(int base, int exponent) {
    long product = 1;
    int i;

    for (i = 0; i < exponent; i++) {
        product *= base;
    }
    return product;
}

// *** Scientific value of 615.87 references *** 
// 1. https://www.protocol-online.org/biology-forums-2/posts/27692.html
// "Based on that papers' calculations, the sizes of a base pair (accounting for loss of a water molecule on each strand in polymerization and a proton from each phosphate hydroxyl due to the pH) should be:
// GC: 347.2207+307.1966-(4x1.0079+2x15.9994)-(2x1.0079)= 616.3711
// AT: 331.2213+322.2079-(4x1.0079+2x15.9994)-(2x1.0079)= 615.383
// average: 615.8771" 
// 2. https://onlinelibrary.wiley.com/doi/10.1002/cyto.a.10013
//
// *** Contextual reference match ***
// 1. Various creation stories => "Build the Ark ... take on board a ""pair"" from every species"; 
//
// A. Old magic book (https://www.masjidtucson.org/quran/wordCount/QuranGVwords.php)
// 23:27                                             *pattern: 23/27=0.851...*
// "So We revealed"	      <= Word : 1                #pattern: 27/23= 1.17#   
//                             #7 : 1#       
//[80]+ 1 + 6 + 8 + [10] + 50 + 1 = 156 
//          6,1,50,8,1            : 156,08,01        *order to pattern "158"*
//          615.81                : 615.81           *replace 1 with 7; pattern 1.17*
//                         615.87 : 615.87           *average DNA base pair mass*
//
// "the ark"     <= Word : 5
//                    #5 : 1#                        *note: average = mesos (A.Greek => 40+5+200+70+200=515) & average = mutawassit (Arabic => 40+400+6+60+9=515); however it is broken 5:1:5*
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
// B. Other old magic book (https://mechon-mamre.org/p/pt/pt0106.htm) 
// Genesis 6: "Make ... an ark" - 10th Hebrew patriarch: Noah (Hebrew => 50 + 8 = 58)	   															  => 615.8
//
// Genesis 5:  First word "And" = 6+10 in Hebrew occurs 30/32 times _,_,[6,10] ... *30 times (position 3 -> 0) 										  => 61_.
// 			   Verse 29 of Chapter 5 - [1]st mention of Noah: 29/5=[5.8]                                                                              => 615.8_
// 			   "Noah" = 50+8 occurs 3 times in Chapter 5 - 5*3*58 = 870                                                                               => 615.87
// 			   * Note: "And" = Vav + yod (Hebrew => 6 + 10) : cell nuclear material conveniently called [DNA] 
//	
// First words up to "Noah" - Genesis 5														                                                                                        
// Genesis 5:29 ->        English => [And]    + [he called]     + [his name]               + [Noah]         															* 29+5=34; 1 sigma flag
//                        Hebrew =>  [6 + 10] + [100 + 200 + 1] + [1 + 400 + 300 + 40 + 6] + [50 + 8]   = 1122
//                                    _   __     2                                      9	  __   _																	* Step A: match verse value to position, starting from 0th value position	                                      
//                        6,10                                                                                                                  50,8  => 615.8			* First occurrence game1: use values: 1,2,11,12 => 1=6, 2=10, 11=50, 12=8 	
//                        6,10        * 100+200+1+1+400+300+40+6 = 1048; 7 of 8 unique [Hebrew word unique:"yachid" = 10+8+10+4=32]             50,8  => 615.8[7]       * First occurrence game2: between 3rd and 4th position OR 2nd and 3rd value, what is not a random occurrence? => note: value 32 = yachid : unique [1] -> 34.1 (1 sigma flag match)             
//                        6,10        * 10s in "yachid" not unique LIKE 1s at position 4 and 5 & SAME "yachid" # pos.: value = 10:50,8:40,4:1   50,8  => 615.8[7]
//						  6,10        * total/(letter per word) = 1122/(2*3*5*2) = 18.7															50,8  => 615.8[7]
//                        6,10        * all values/"yachid" = 1048/32 = 32.75 => "yachid".75 => 1, 7, 5		                	                50,8  => 615.87[71]
//						  6,10        * total/all values = 1122/1048 = 1.070610687 => all values except 5: 7 of 10 non-zero      				50,8  => 615.87[71]
//						  6,10        * 12 letters with value, 4 words, 1 sentence : 12+4+1 = 17 & 12*4*1=48 = 7*7-1                            50,8  => 615.8[771] 
//
// Genesis 5:30 ->       English => [And]    + [lived]  + [Lamech]       + [after]            + [he begot]                +  ~obj.    + [Noah]
//						 Hebrew =>  [6 + 10] + [8 + 10] + [30 + 40 + 20] + [1 + 8 + 200 + 10] + [5 + 6 + 30 + 10 + 4 + 6] + [1 + 400] + [50 + 8] = 863 
//                                   _   __         3							   (no position because word is object marker) =>  _     __   _
//                                                  3                                                        (actual position) => 18
//												2	3 			  (unique occurrence: all numbers @ word)  yachid[1] : 10+8+10+4 = 32 
//						  6,10																													50,8  => 615.8
//																
// Genesis 5:32 ->		 English => [And]    + [was]    + [Noah]           
//						 Hebrew =>  [6 + 10] + [5 + 10] + [50 + 8] = 89																	                
//                                   _   __     2    3     __   _
//						  6,10																													50,8  => 615.8
// DNA Base pair relation:			 T   A                 G    C   => A & G double ring, C & T single ring
//												2  & 3 			    => H-bonds: 2 between A & T, 3 between C & G)
// Reference: https://upload.wikimedia.org/wikipedia/commons/0/05/DNA_base-pair_diagram.jpg
//
// Chapter 5 totals up to the word Noah:
// 1122+863+89 = 2074  
// 1122*863*89 = 86,177,[4]5[4]                  ->  615.877,_,_ ;         			* first occurrence of yachid[1] = Genesis 22:2; 22*2= 44 & 22+2=24 (2 4's)    => 615.877[1]
// (1122*863*89)+(1122+863+89) = 86,17[9],5[28]  ->  615.87,_,_,_
// (1122*863*89)-(1122+863+89) = 86,175,[380]    ->  615.87,_,_,_ 
// Average molecular mass - water - 2 protons: 						
// 653.9233-18.01528*2-1.00784*2 = 615.87706     ->  615.877[06]                    * from 653.9233, subtract         2 H20 & 2 H;                               =>"615.877[1]"
//  Reference: https://www.protocol-online.org/biology-forums-2/posts/27692.html
// "Without accounting for the masses lost from the 2 waters or the 2 protons lost from the backbone phosphate, the masses end up being 654.4173 for GC and 653.4292, so an average of 653.9233."
//
// C. Translation and amended version of Other old magic book (https://www.blueletterbible.org/lxx/gen/6/1/s_6001)
// "Make ... an ark"; Chapter 6, 10th Hebrew patriarch: Noah (A.Greek=50+800+5) & 1st mention 5:29 (29/5=5.8) => 615.8_
// First words including "Noah" are [And he called his name Noah]                                                                                  
//                        (A.Greek => ((20 + 1 + 10) + (5 + 80 + 800 + 50 + 70 + 40 + 1 + 200 + 5 + 50) + (300 + 70) + ( 70 + 50 + 70 + 40 + 1) + (1 + 400 + 300 + 70 + 400) + (50 + 800 + 5) = 3959))        
//                        *This seems to have lost its link to the value 615.87 through direct translation. The Hebrew version is carefully crafted.*
//                        *Only through Hebrew and Ancient Greek's shared link to proto-indo-european: Noah N value of 50 is retained*
//             
//
// 2. A. Babylonian Ark Tablet - Learned culture and boat dimensions: https://www.youtube.com/watch?v=jqBQKHl5PeA&t=1635s
// *  Front side
// (2*pi-0.14430+0.03-(0.036*0.5*0.5)-0.001-0.0001-0.0000125+0.0000005-0.0000023)*10*10
// 1  "Wall, wall! Reed wall, reed wall!" :							 								6 words, 001010 binary=2+8=10 => 6,10 & 6,2,8 => 2*pi flag	=> 6.10																				 
// 2  "Atra-hasis, pay heed to my advice,"
// 3  "That you may live for ever!"																	*note: live for ever : biological 
// 4  "Destroy your house, build a boat;"
// 5  "Spurn property and save life!"
// 6  "Draw out the boat that you will make"                       									*note: common reed boat structure : circular 
// 7  "On a circular plan"                            												*Circumference = 2*pi*r				
// 8  "Let her length and breadth be equal,"                                						*2*pi*1 = 6.2831853071795864...								=> 6.______		 *line 8, 6+2=8 : 6.28 
// 9  "Let her floor area be one field, let her sides be one nindan high:"   						* "
// 10 "You saw kannu ropes and aalu ropes/rushes for [a corable before!]"
// 11 "Let someone (else) twist the fronds and palm-fibre for you!          				    	
// 12 "It will surely consume 14,430 sutu!"                                 						6.2831853071795864-0.14430 = 6.1388853071795864			 	=> 6.1_____       *line 12, 6.2 => 6.1
// 13 "I set in place thirty ribs"																	6.1388853							 			 			=> 6.1_____ 	  *line 13, 6.13
// 14 "Which were one parsiktu-vessel thick, ten nindan long"										6.1388853+(0.030) @ 0.01 length	or 01*03=003				=> 6.1688853      *line 14, 1,10:110 =6; 6.16
// 15 "I set up 3,600 stanchions within her"																						
// 16 "Which were half (a parsiktu-vessel) thick, half a nindan high"  								6.1688853-(0.009)											=> 6.1598853	  *(0.036*0.5*0.5) = 0.009
// 17 "I constructed her cabins above and below"          											6.1598853																	  														
// 18 "I apportioned one finger of bitumen for her outsides;"										6.1598853-0.001 = 6.1588853									=> 6.1588853	  *look at your finger, folds are place values; from the outside (whole #)												
// 19 "I apportioned one finger of bitumen for her interior;" 										6.1588853-0.0001 = 6.1587853								=> 6.1587853      *same, four place values from the interior (decimal point)
// 20 "I caused the kilns to be loaded with 28,800 sutu of kupru-bitumen"                           6.1587853
// 21 "And I poured 3,600 sutu of iooy-bitumen within."												6.1587853-0.0000125 = 6.1587728				    			=> 6.1587728	  *line 21, 3600/28800 = 1/8 = 0.[12]5; "within": past the last used place value => 0.0000125
// 22 "The bitumen did not come to the surface (lit. up to me]; (so) I added five fingers of lard," 6.1587728+0.0000005 = 6.1587733 						    => 6.1587733	  *line 22 "up to me":  0.0000 (2+2 & 2*2=4 place values), add 5*0.001 (finger) => 0.0000005
// 23 "I ordered the kilns to be loaded... in equal measure; 										6.1587733-0.0000023	= 6.1587710071							=> 6.1587710	  *line 23 = "in equal measure":verse:line 23 & last decimal places are "equal"
//																																												  *note: kiln : H-bonds broken with heat, 2H20 + 2H mass removed & line 23 => H-bonds between AT:2, CG:3 same #'s as Other old magic book		
// 24 "(With) tamarisk wood (?) (and) stalks (?)"													6.1587710071*100 = 615.87710071								=> 615.87710	  *line 24 = decimal past 2+4:1+5 & before 2*4=8  => 615.8771													
//																																												  *increase temp with wood, note: line 24, binary(2) of 4 = "100" 
//																																												  *all previous changes: -0.14430+0.030-(0.009)-0.001-0.0001-(0.0000125)+0.0000005-0.0000023 = -0.1244143; remove 24 => -0.[100]4143
// 25 "... (= I completed the mixture).																6.158771*100 = 615.8771 									=> 615.8771       *line 25 = all change numbers summed: 1+4+4+3+3+9+1+1+1+2+5+5+2+3+[1] = 45 : 0.25 of 180 degrees = 45
// 26
// 27 "Going between her ribs;"
// 28
// 29 "... the iooy-bitumen ..."																	*Front side formula: (2*pi-0.14430+0.03-(0.009)-0.001-0.0001-0.0000125+0.0000005-0.0000023)*10*10 = 615.8771....
//																									*Sum (1 to 29)*29 = 435*29 = 12,615
//
// *  Back side
// 1  "I applied (?) the outside kupru-bitumen from the kilns,"									
// 2  "Out of the 120 gur-measures, which the workmen had put to one side."							*put 120 (& on lines 1,2) to one side; 12 | 615         	=> 615.____       *place-value check 			
// 3  "I lay myself down (?) ... of rejoicing"	
// 4  "My kith and kin [went into] the boat...;"													*"the ark" has been completed
// ...
// ~ ends at line 29 																				*Front + Back lines = 29+29 = 58 = Noah [50 + 8]; divided
// ~ Quick calculation: First line & total tablet lines:				                            *6 words, 10 converted from binary, 58 total lines          => 615.8___ 
// ~ total lines factorial: 58! = 2.35,0561...*10^78   &    Sum of 1 to 25 "I completed the mixture" = 325
//   rearrange:    			      3 25, 615.87[7 digits]1 																										=> 615.8771  
// 
//  B. Babylonian Map Tablet - Noah's ark relation: https://www.youtube.com/watch?v=LUxFzh8r384  
//  ~map of Babylon with triangle pointing from Urartu / Mt. Ararat 
// 	"To the fourth, to which you must travel seven leagues" 					0.7*10^4 = 7000  -> 5,700 lightyears away: Eagle Nebula contains the "pillars of creation"
//  "as thick as a parsiktu-vessel... fingers" 									"parsiktu" : line 14 of Babylonian ark story; only known word match 
//																				"fingers" : decimal place value measurement [0.001]; 
//																							line 18,19,22: 18*1+19*1+22*5 = 147
//																								 18*19*22 = 7,524 => 0.0075[full Babylonian day]
//  															                Pillars of creation : look like broken DNA base pair structure
//
// 
// 	3. Voynich Manuscript:
//  Visually similar cellular material pages: 75-86; turn the [-] => 1																					         => 615.87
//  abbreviations: FR = face right, FL = face left, T = touching, IN = go in, OUT = go out
//
//  Page 75 (front): Simple: pool A: 8 nymphs, pool B: nymphs 6 divided by 1 channel																			 => 615.87
//                   pool A: 8 nymphs: (7FL, 1FR) & (5T, 1, [1IN-1OUT])																							 => _15.87
//					 pool B: 6 nymphs: (2T*3T), 1IN = 6 & 1OUT																												     *divided by 1 channel
//				     		 (3FR*2FL), 1IN = 6 & 1OUT => 61																									 => 61_.__
//                           3rowA + 3rowB = 6
//                           3rowA / 3rowB = 1                                                                                                                   => 61_.__   
//						
//  Page 75 (reverse): pool A: 6FL:4FR over pool B: 16FL:3FR
//  (6-4)/(16-3) = 0.153846...
//                   15 8 6    & 3+4=7 (total FL) 				  																								 => 615.87
// 
//
// 4. Dune (1[9]65): https://www.youtube.com/watch?v=124xCHfVUk4
//
