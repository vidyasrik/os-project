#include <stdio.h>
#include<unistd.h>
// creating a structure of a process 
struct process { 
	int processno; 
	int AT; 
	int BT; 
	// for backup purpose to print in last 
	int BTbackup; 
	int WT; 
	int TAT; 
	int CT; 
}; 
// creating a structe of 4 processes 
struct process p[3]; 
// variable to find the total time 
int totaltime = 0; 
int prefinaltotal = 0; 
// comparator function for sort() 
// finding the largest Arrival Time among all the available 
// process at that time 
int findlargest(int at) 
{ 
	int max = 0, i; 
	for (i = 0; i < 3; i++) { 
		if (p[i].AT <= at) { 
			if (p[i].BT > p[max].BT) 
				max = i; 
		} 
	} 
	// returning the index of the process having the largest BT 
	return max; 
} 
// function to find the completion time of each process 
int findCT() 
{ 
	int index; 
	int flag = 0; 
	int i = p[0].AT; 
	while (1) { 
		if (i <= 3) { 
			index = findlargest(i); 
		} 
		else
			index = findlargest(3); 
		p[index].BT -= 1; 
		totaltime += 1; 
		i++; 
		if (p[index].BT == 0) { 
			p[index].CT = totaltime;  
		}  
		// loop termination condition 
		if (totaltime == prefinaltotal) 
			break; 
	}
} 
int main() 
{ 
	int i; 
	// initializing the process number 
	for (i = 0; i < 3; i++) {
	if(i==0) {
		p[i].processno =2102;}
		else if(i==1) {
		p[i].processno =2132;}
		else if(i==2) {
		p[i].processno =2152;}
	} 
	// cout<<"arrival time of 4 processes : "; 
	for (i = 0; i < 3; i++) // taking AT 
	{ 
		p[i].AT =0; 
	} 
	// cout<<" Burst time of 4 processes : "; 
	for (i =0; i <3; i++) { 
		// assigning {2, 4, 6, 8} as Burst Time to the processes 
		// backup for displaying the output in last 
		// calculating total required time for terminating 
		// the function().
		if(i==0) {
		p[i].BT =4; 
		p[i].BTbackup = p[i].BT; 
		prefinaltotal += p[i].BT;
	}
	else if(i==1) {
		p[i].BT =2; 
		p[i].BTbackup = p[i].BT; 
		prefinaltotal += p[i].BT;
	}
	else if(i==2) {
		p[i].BT =8; 
		p[i].BTbackup = p[i].BT; 
		prefinaltotal += p[i].BT;
	}
	} 
	// displaying the process before executing 
	printf("PNo\tAT\tBT\n"); 
	for (i = 0; i < 3; i++) { 
		printf( "%d\t",p[i].processno); 
		printf("%d\t",p[i].AT); 
		printf("%d\t",p[i].BT); 
		printf("\n"); 
	} 
	printf("\n"); 
	// soritng process according to Arrival Time 
	// calculating initial time when execution starts 
	totaltime += p[0].AT; 
	// calculating to terminate loop 
	prefinaltotal += p[0].AT; 
	findCT(); 
	int totalWT = 0; 
	int totalTAT = 0; 
	for (i = 0; i < 3; i++) { 
		// since, TAT = CT - AT 
		p[i].TAT = p[i].CT - p[i].AT; 
		p[i].WT = p[i].TAT - p[i].BTbackup; 
		// finding total waiting time 
		totalWT += p[i].WT; 
		// finding total turn around time 
		totalTAT += p[i].TAT; 
	} 
	//cout << "After execution of all processes ... \n"; 
	// after all process executes 
	printf("PNo\tAT\tBT\tCT\tTAT\tWT\n"); 
	for (i = 0; i < 3; i++) { 
		printf("%d\t",p[i].processno);
		printf("%d\t",p[i].AT); 
		printf("%d\t",p[i].BTbackup); 
		printf("%d\t",p[i].CT ); 
		printf("%d\t",p[i].TAT ); 
		printf("%d\t",p[i].WT ); 
		printf("\n"); 
	} 
    printf("\n"); 
	printf("Total TAT = %d\n",totalTAT); 
	printf("Average TAT = %d\n",totalTAT / 3); 
	printf("Total WT = %d\n" ,totalWT); 
	printf("Average WT =  %d\n",totalWT / 3); 
	return 0; 
}

