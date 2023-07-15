#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
void endProgram ();

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);

    endProgram ();
}

int get_cents(void)
{
    //to neglect negative numbers by the user
    int cents;
    do
    {
        printf("Enter number of cents: ");
        scanf("%d", &cents);
    }
    while (cents < 0);

    return cents;
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    while ((cents - 25) >= 0)
    {
        cents -= 25;
        quarters++;
    }
    return quarters ;
}

int calculate_dimes(int cents)
{
    int dime = 0;
    while ((cents - 10) >= 0)
    {
        cents -= 10;
        dime++;
    }
    return dime;
}

int calculate_nickels(int cents)
{
    int nickle = 0;
    while ((cents - 5) >= 0)
    {
        cents -= 5;
        nickle++;
    }
    return nickle;
}

int calculate_pennies(int cents)
{
    int penny = 0;
    while ((cents - 1) >= 0)
    {
        cents -= 1;
        penny++;
    }
    return penny;
}

void endProgram (){

		printf("\nPress Enter To EXIT ");
		while(getchar()!='\n'){

		}
		getchar();

}
