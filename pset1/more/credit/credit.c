#include <stdio.h>
#include <cs50.h>
#include <math.h>

long getCardNo();
int getNoOfDigits(long);
int getSumOfSecondDigits(long);
int getSumOfFirstDigits(long);
bool isLunhsAlgoSatisfied(long);
string getCardType(long);

int main(void)
{
    long cardNo = getCardNo();
    bool isValidCardNo = isLunhsAlgoSatisfied(cardNo);
    string cardType = "INVALID";
    if (isValidCardNo)
    {
        cardType = getCardType(cardNo);
    }
    printf("%s\n", cardType);
}

long getCardNo()
{
    long cardNo;
    do
    {
        cardNo = get_long("Number: ");
    }
    while (cardNo < 0);

    return cardNo;
}

bool isLunhsAlgoSatisfied(long cardNo)
{
    int sumOfSecondDigits = getSumOfSecondDigits(cardNo);
    int sumOfFirstDigits = getSumOfFirstDigits(cardNo);

    if ((sumOfFirstDigits + sumOfSecondDigits) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getSumOfFirstDigits(long cardNo)
{
    int sumOfUnitDigits = 0;
    while (cardNo / 10 >= 0)
    {
        if (cardNo == 0)
        {
            break;
        }

        // getting last two digits and then discarding tens digit
        int firstDigit = (cardNo % 100) % 10;

        // add to sum
        sumOfUnitDigits += firstDigit;

        // remove last two digits from card no
        cardNo = cardNo / 100;
    }

    return sumOfUnitDigits;
}

int getSumOfSecondDigits(long cardNo)
{
    int sumMultipliedWith2 = 0;
    while (cardNo / 10 != 0)
    {
        // getting last two digits and then discarding last digit
        int secondDigit = (cardNo % 100) / 10;

        // multiply with 2 and if required add digits
        int product = secondDigit * 2;
        if (product / 10 == 0)
        {
            sumMultipliedWith2 += product;
        }
        else
        {
            int digitOnes = product % 10;
            int digitTens = product / 10;
            sumMultipliedWith2 += digitOnes + digitTens;
        }
        // remove last two digits from card no
        cardNo = cardNo / 100;
    }

    return sumMultipliedWith2;
}

int getNoOfDigits(long cardNo)
{
    int n = 1;

    while (cardNo / 10 != 0)
    {
        n++;
        cardNo = cardNo / 10;
    }

    return n;
}

string getCardType(long cardNo)
{
    string cardType = "INVALID";
    int noOfDigits = getNoOfDigits(cardNo);

    if (noOfDigits == 15) // check for AmericanExpress (AMEX)
    {
        int firstTwoDigits = cardNo / pow(10, noOfDigits - 2);
        if (firstTwoDigits == 34 || firstTwoDigits == 37)
        {
            cardType = "AMEX";
        }
    }
    else if (noOfDigits == 13) // check for VISA (VISA)
    {
        int firstDigit = cardNo / pow(10, noOfDigits - 1);
        if (firstDigit == 4)
        {
            cardType = "VISA";
        }
    }
    else if (noOfDigits == 16) // check for MasterCard (MASTERCARD) and VISA (VISA)
    {
        int firstTwoDigits = cardNo / pow(10, noOfDigits - 2);
        if (firstTwoDigits >= 51 && firstTwoDigits <= 55)
        {
            cardType = "MASTERCARD";
        }
        else if (firstTwoDigits / 10 == 4)
        {
            cardType = "VISA";
        }
    }

    return cardType;
}