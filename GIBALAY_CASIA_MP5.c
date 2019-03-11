#include <stdio.h>
#define INT_MAX 2147483648

int quotient(int, int);
int prime(int, int);
int search(int[], int, int, int);

int main()
{
    int tc;
    scanf("%d", &tc);            //asking for the number of testcases
    for (int i = 0; i < tc; i++) //this loop is for the running of the inputted number of testcases
    {
        int type;
        scanf("%i", &type);

        //CHOICES OF TESTCASES

        if (type == 1)
        {
            int a, b;
            scanf("%i %i", &a, &b);
            if ((a < 1 || a > INT_MAX) || (b < 1 || b > INT_MAX)) //INPUT CHECKING
            {
                printf("INVALID\n");
            }
            else
            {
                printf("%d\n", quotient(a, b));
            }
        }

        else if (type == 2)
        {
            int a, b;
            scanf("%i %i", &a, &b);
            if ((a < 1 || a > INT_MAX) || (b < 1 || b > INT_MAX)) //INPUT CHECKING
            {
                printf("INVALID\n");
            }
            else
            {
                if (a < b)
                {
                    a = a + b;
                    b = a - b;
                    a = a - b;
                }
                printf("%s",
                       (prime(a, b) == 1) ? "RELATIVELY PRIME" : "NOT RELATIVELY PRIME"); //this ternary operation is equivalent to an if-else statement of the resulting value in the function prime
                printf("\n");
            }
        }

        else if (type == 3)
        {
            int size, item;
            scanf("%d", &size);
            if (size < 2 || size > 20) //INPUT CHECKING
            {
                printf("INVALID\n");
            }
            else
            {
                int array[size];
                for (int i = 0; i < size; i++)
                    scanf("%d", &array[i]);

                scanf("%d", &item);
                printf("%d %s", item, (search(array, item, 0, size) == 1) ? "IS IN THE SET" : "IS NOT IN THE SET"); //this ternary operation is equivalent to an if-else statement of the resulting value in the function search
            }
        }

        else
        { //if the inputted choice does not have a corresponding option we will print invalid
            printf("INVALID\n");
        }
    }
    getchar();
    getchar();
}

int quotient(int a, int b)
{
    if (a - b >= 0)
    {
        return 1 + quotient(a - b, b); //this keeps tabs of 1 for every subtraction that happens in the calling of the function; this recursive call will ultimately make a go down to 0. Afterwards, all the 1's will be added
    }
    else
    {
        return 0; //hence, when a is already 0 or less than 0, we will add it to the tabs of 1
    }
}

int prime(int a, int b)
{
    if (a % b > 0)
        return prime(b, a % b); //this recursive call switches b to a and a%b to b, thus ultimately bringing down the result of a%b to 0
    else
        return (b != 1) ? 0 : 1; //hence, when a%b is already 0, we will check via ternary operation(equivalently, an if-else statement) whether b is a 1 or not
}

int search(int array[], int item, int lbd, int ubd)
{
    //SPECIAL CASES
    if (item < array[0] || item > array[ubd - 1])
    {
        return 0;
    }
    else if (item == array[lbd])
    {
        return 1;
    }
    else if (item == array[ubd])
    {
        return 1;
    }
    //END OF SPECIAL CASES

    else //BINARY SEARCHING VIA RECURSION
    {
        int mid = (ubd + lbd) / 2;
        if (item < array[mid])
        {
            return search(array, item, lbd, mid);
        }
        if (item >= array[mid])
        {
            return search(array, item, mid, ubd);
        }
    }
}