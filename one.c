#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void printarray(char *arr,int length) {
		//printf("printing data");
		for(int i=0;i<length;i++) {
				printf("\n%c\t",arr[i]);
		}
}
void printarrayint(int *arr,int length) {
		//printf("printing data");
		for(int i=0;i<length;i++) {
				printf("\n%d\t",arr[i]);
		}
}
int checktransition(int tran[][2],int left,int right) {
		return tran[left][right];
}
int main() {
		int inputalphabets;
		printf("Enter no. of input alphabets \n");

		// kitne w=[0,1]
		//
		scanf(" %d",&inputalphabets); // 2
		printf("Enter the input alphabets \n");
		char ia[inputalphabets];
		int i;
		fflush(stdin);
		for(i=0;i<inputalphabets;i++) {
            char ci;
            scanf(" %c",&ci);
            ia[i]=ci;
		}
		// ia = [0,1]
		printarray(ia,inputalphabets);

		// how many states
		printf("Enter no. of states");
		int numstates;
		scanf("%d",&numstates); // 3
		int statesarray[numstates];
		printf("Enter states\n");
		for(int i=0;i<numstates;i++) {
				scanf(" %d",&statesarray[i]);
		}
		//printf("inputted array:-\n");
		//printarrayint(statesarray,numstates);
		
		int initalstate;

		printf("\n Enter inital state");
		scanf(" %d",&initalstate);
		printf("\nEnter no. of final states ");
		fflush(stdin);
		int numfinalstates;
		scanf(" %d",&numfinalstates);
		printf("\nNumfinalstate = %d",numfinalstates);
		printf("\nEnter final states:-");
		int finalstates[numfinalstates];
		for(int i=0;i<numfinalstates;i++) {
				scanf(" %d",&finalstates[i]);
		}

		// transition table
		int transitiontable[numstates][inputalphabets];
		printf("\nEnter tansition table\n");
		for(int i=0;i<numstates;i++) {
				for(int j=0;j<inputalphabets;j++) {
						scanf(" %d",&transitiontable[i][j]);
				}
		}
		// 1 2
		// 1 1
		// 2 2

		// input the test string
		char teststring[10];
		printf("\nEnter string:- ");
		scanf(" %s",teststring);

		// 01123422
		// s(s(0,0),"1123422")
		// 0,0 => 1
		// s(s(1,1),"123422")
		// s(s(1,1),"23422")
		// s(s(1,2),"3422") // error
		i=0;
		while(teststring[i]!='\0') {
				// 011   0 => 48-48 => 0 ASCII conversion
				int t = (int)teststring[i] - '0';
				initalstate=checktransition(transitiontable,initalstate,t);
				printf("\nitstate for $i:- %d,%d",initalstate,t);
				i++;
		}

		// check initalstate now in finalstates[]
		//
		bool flag=false;
		// [2,3,4]
		// 2
		for(int i=0;i<numfinalstates;i++) {
				if(initalstate == finalstates[i]) {
						flag = true;
						break;
				}
		}
		printf("\n Final initial state is :- %d",initalstate);
		//if(initalstate==1 && flag) {
		//		printf("\nstarted with 0 ");
		//} else if(initalstate==2 && flag) {
		//		printf("\nstarted with 1");
		//} else {
		//		printf("\nDead State");
		//}

		if(initalstate == 1) {
				printf("String is rejected");
		} else {
				printf("String is accepted");
		}

		return 0;
}


