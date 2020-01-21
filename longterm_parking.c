//Calculates the cost of parking at the Tampa International Airport - Akash Makati

#include <stdio.h>


int main(void)
{
	//Declare variables
	int minutes, hours, days, amount, total_minutes, cost;	

	//Prompt user for hours and minutes parked
	printf("Enter hours parked: ");
	scanf("%d", &hours);
	printf("\n");
	printf("Enter minutes parked: ");
	scanf("%d", &minutes);
	printf("\n");

	//Calculate total number of minutes parked
	total_minutes = minutes + (hours*60);	

	//Input validation
	if (hours < 0 || minutes < 0 || minutes > 60)
	{
		printf("Invalid input. Hours should be positive and minute should be in range 0-60.");
	}
	//Accounts for free 60 minutes of parking
	else if (total_minutes <= 60)
	{	
	printf("The total cost is $0. Thank you!");
	}
	//Accounts for and prints cost for 61-80 minutes
	else if (total_minutes >= 61 && total_minutes <= 80)
	{
		printf("The total cost is $4. Thank you!");
	}
	//Calculates and prints cost of each additional 20 minutes for first day
	else if (total_minutes > 80 && total_minutes < 220)
	{
		total_minutes -= 80;
		amount = total_minutes/20;
		cost = 4 + (amount*2);
		
		if ((total_minutes%20) > 0)
		{
			cost += 2;
		}
		
		printf("The total cost is $%d", cost);
	}
	//Prints maximum cost for first day
	else if (total_minutes >= 220 && total_minutes <= 1440)
	{
		printf("The total cost is $18.");
	}
	//Prints cost for parking over multiple days
	else
	{
		//Calculates cost for parking over 24 hours
		days = hours / 24;
		hours = hours % 24;
		total_minutes = minutes + (hours*60);
		amount = total_minutes/20;
		cost = (18*days) + (amount*2);
		
		//Accounts for 1-19 minutes instead of increment of 20
		if ((total_minutes%20) > 0)
		{
			cost += 2;
		}
		
		printf("The total cost is $%d", cost);
	}

	printf("\n");	
	return 0;
}
