#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int x, tries=1, i;
	
	//initialize random seed
	srand( (unsigned int)time(NULL) );
	
	//pick a random number from 0 to 100
	int rnd=rand()%100 + 1;
	printf("I have picked a random integer from 1 to 100. Can you guess which one it is? ");
	
	//user guesses
	while(1){
		scanf("%d", &x);
		if(x==rnd){
			printf("Congratulations, you found the number!\n");
			if(tries==1){
				printf("Wow, you got it on the first try! That's actually amazing!\n");
			}
			else{
				printf("It took you %d tries to find the number.\n", tries);
			}
			break;
		}
		else if(x<rnd){
			printf("Too low. Try again: ");
			tries++;
		}
		else if(x>rnd){
			printf("Too high. Try again: ");
			tries++;
		}
	}
	
	//switch roles
	printf("OK, my turn. You have 5 seconds to pick a number from 1 to 100 and I'll try to guess which one it is. \n");
	for(i=0; i<=4; i++){
		printf(".\n");
		Sleep(1000);
	}
	int range, floor=1, ceiling=100, ans;
	
	//computer guesses
	printf("OK, let's go.\n");
	
	while(1){
		//define range
		range=(ceiling-floor)+1;
		
		//initialize random seed (again)
	    srand( (unsigned int)time(NULL) );
	     
	    //pick a random number from 0 to 100 (again)
	    int rnd=rand()%range + 1 + floor;
	     
	    //guess
	    printf("Is it %d? Type 1 for YES and 0 for NO: \n", rnd);
	    scanf("%d", &ans);
	    
	    //tell the computer if it's right or wrong
	    while(ans!=1 && ans!=0){
	    	printf("I don't understand what you're saying. 1 for YES and 0 for NO: ");
	    	scanf("%d", &ans);
		}
	    if(ans==1){
	    	printf("HA! I win!");
	    	break;
		}
		else if(ans==0){
			printf("Was my guess too high or too low? 1 for TOO HIGH and 0 for TOO LOW: \n");
			scanf("%d", &x);
			
			//invalid answer?
			while(ans!=0 && ans!=1){
				printf("What? Speak computer please.. 1 for TOO HIGH and 0 for TOO LOW: ");
				scanf("%d", &x);
			}
			
			//too low?
			if(x==0){
				printf("OK, I see. \n");
				floor=rnd;
			}
			
			//too high?
			else if(x==1){
				printf("Right, okay. \n");
				ceiling=rnd;
			}
		}
	}
	return 0;
}
