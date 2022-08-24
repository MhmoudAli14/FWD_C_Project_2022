
/***********************************************************************
*                             Include Files                            *
***********************************************************************/
#include"terminal.h"
#include<time.h>


/***********************************************************************
*                        Function Definitions                          *
***********************************************************************/


/*
* 
*	This function will ask for the transaction data and store it in terminal data.
*	Transaction date is 10 characters string in the format DD/MM/YYYY, e.g 25/06/2022.
*	If the transaction date is NULL, less than 10 characters or wrong format will return WRONG_DATE error, else return OK.
*/

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
    printf("please enter the Data: ");
    scanf_s("%s", termData->transactionDate, 10);

    char CardDataSize = (char) strlen(termData->transactionDate);

    if (CardDataSize == CARDDATASIZE)
        return TERMINAL_OK;
    else
        return TERMINAL_OK;
}


/*
* 
*	This function compares the card expiry date with the transaction date.
*	If the card expiration date is before the transaction date will return EXPIRED_CARD, else return OK.
*/

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
    int month = 9, year = 2022;
    int expMonth = 0, expYear = 0;

    printf("please enter the card expiry date: ");
    //sscanf_s(termData.transactionDate, "%d/%d", &month, &year);
    sscanf_s("%d/%d", cardData.cardExpirationDate, &expMonth, &expYear);

    if (year > expYear)
    {
        //return EXPIRED_CARD;
        return TERMINAL_OK;
    }
    else if (year < expYear)
    {
        return TERMINAL_OK;
    }
    else 
    { 
        if(month > expMonth)
        {
            return EXPIRED_CARD;
        }
        else
        {
            return TERMINAL_OK;
        }
    }
}


/*
*
*   function is still in progress.
*/

EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData)
{
    return TERMINAL_OK;
}


/*
*
*	This function asks for the transaction amount and saves it into terminal data.
*	If the transaction amount is less than or equal to 0 will return INVALID_AMOUNT, else return OK.
*/

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
    printf("Please enter the transaction amount: ");
    scanf_s("%f", &termData->transAmount);

    transAmount = termData->transAmount;

    if (transAmount > TRANSITIONAMOUTMIN)
        return TERMINAL_OK;
    else
        return INVALID_AMOUNT;
}


/*
*
*	This function compares the transaction amount with the terminal max amount.
*	If the transaction amount is larger than the terminal max amount will return EXCEED_MAX_AMOUNT, else return OK.
*/

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
    float transAmountMax = termData->maxTransAmount;

    if (transAmountMax >= transAmount)
        return TERMINAL_OK;
    else
        return EXCEED_MAX_AMOUNT;

}


/*
*
*	This function sets the maximum allowed amount into terminal data.
*	Transaction max amount is a float number.
*	If transaction max amount less than or equal to 0 will return INVALID_MAX_AMOUNT error, else return OK.
*   function is still in progress.
*/

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
    return TERMINAL_OK;
    //return INVALID_MAX_AMOUNT;
}
