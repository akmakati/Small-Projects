/*Akash Makati
  This code runs a slot machine where the user enters a balance and they will 
  be able to play the slot machine until they are out of money*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_SYMBOL 14

int main(void)
{
    srand(time(NULL));

    //Declare variables
    int choice, balance, ranNum, i;

    //Use scanf for initial balance
    printf("Enter initial balance (in cents): ");
    scanf("%d", &balance);

    //Prompt if user wants to play
    printf("Would you like to play (press 1 to play or 0 to quit)? ");
    scanf("%d", &choice);

    //This is what would run if someone inputs something other than 0
    while (!(choice == 0))
    {
        //If statement checks if user has sufficient funds
        if (balance < 5)
        {
            printf("Insufficient funds.");
            printf("\n");
            return 0;
        }
        //Runs slot machine
        else
        {   
            //Subtract 5 cents and declare empty array
            balance -= 5;
            int symbolCount[14] = {0};

            //For loop that's used to spin the slot machine
            for (i=0; i < 3; i++)
            {
                ranNum = (rand() % (14));
                //Switch statement used to print out statements from each run of for loop
                switch (ranNum)
                {
                    case 0: symbolCount[0]++;
                            printf("Pineapple ");
                            break;
                    case 1: symbolCount[1]++;
                            printf("Kiwi ");
                            break;
                    case 2: symbolCount[2]++;
                            printf("Apple ");
                            break;
                    case 3: symbolCount[3]++;
                            printf("Orange ");
                            break;
                    case 4: symbolCount[4]++;
                            printf("Lime ");
                            break;
                    case 5: symbolCount[5]++;
                            printf("Peach ");
                            break;
                    case 6: symbolCount[6]++;
                            printf("Lemon ");
                            break;
                    case 7: symbolCount[7]++;
                            printf("Pear ");
                            break;
                    case 8: symbolCount[8]++;
                            printf("Banana ");
                            break;
                    case 9: symbolCount[9]++;
                            printf("Cherry ");
                            break;
                    case 10: symbolCount[10]++;
                            printf("Grape ");
                            break;
                    case 11: symbolCount[11]++;
                            printf("Blueberry ");
                            break;
                    case 12: symbolCount[12]++;
                            printf("Blackberry ");
                            break;
                    case 13: symbolCount[13]++;
                            printf("Apricot ");
                            break;
                }
            }
            //If statement used to check user won
            if (symbolCount[0] == 3 || symbolCount[1] == 3 || symbolCount[2] == 3 || symbolCount[3] == 3 || symbolCount[4] == 3 || symbolCount[5] == 3 || symbolCount[6] == 3 || symbolCount[7] == 3 || symbolCount[8] == 3 || symbolCount[9] == 3 || symbolCount[10] == 3 || symbolCount[11] == 3 || symbolCount[12] == 3 || symbolCount[13] == 3)
            {
                balance += 100;
                printf("\n");
                printf("Congratulations! You have won $1!");
                printf("\n");
            }
            else
                printf("\n");
                printf("Remaining Balance: %d cents", balance);

        }
        printf("\n");
        printf("\n");
        printf("Would you like to play (press 1 to play or 0 to quit)? ");
        scanf("%d", &choice);
    }

    //This is what would run if someone inputs 0
    printf("\n");
    printf("Thank you for playing!");
    printf("\n");
    printf("Remaining Balance: %d cents", balance);

    

    return 0;
}