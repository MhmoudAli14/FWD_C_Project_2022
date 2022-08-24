/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "card.h"


/***********************************************************************
*                        Function Definitions                          *
***********************************************************************/

/*
*
*	This function will ask for the cardholder's name and store it into card data.
*	Card holder name is 24 characters string max and 20 min.
*	If the cardholder name is NULL, less than 20 characters or more than 24 will return WRONG_NAME error, else return OK.
*
*/

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf("Please enter the card Holder name: ");
    scanf_s("%s", cardData->cardHolderName, 25);
	
    char CardHolderSize = (char) strlen(cardData->cardHolderName);

    if ((CardHolderSize <= CARDHOLDERMAX) && (CardHolderSize >= CARDHOLDERMIN))
        return CARD_OK;
    else
        return WRONG_NAME;
}


/*
* 
*	This function will ask for the card expiry date and store it in card data.
*	Card expiry date is 5 characters string in the format "MM/YY", e.g "05/25".
*	If the card expiry date is NULL, less or more than 5 characters, or has the wrong format will return WRONG_EXP_DATE error, else return OK.
*/


EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
    printf("Please enter the card expiry date in this format \"MM / YY\": ");
	scanf_s("%s", cardData->cardExpirationDate, 6);
	
    char CardexpirySize = (char) strlen(cardData->cardExpirationDate);

    if (CardexpirySize == CARDEXPIRATIONSIZE)
        return CARD_OK;
    else
        return WRONG_EXP_DATE;
}


/*
* 
*	This function will ask for the card's Primary Account Number and store it in card data.
*	PAN is 20 characters alphanumeric only string 19 character max, and 16 character min.
*	If the PAN is NULL, less than 16 or more than 19 characters, will return WRONG_PAN error, else return OK.
* 
*/

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
    printf("Please enter the card's Primary Account Number: ");
    scanf_s("%s", cardData->primaryAccountNumber, 20);

    char primaryAccountNumberSize = (char) strlen(cardData->primaryAccountNumber);

    if ((primaryAccountNumberSize <= PRIMARACCNOMAX) && (primaryAccountNumberSize >= PRIMARACCNOMIN))
        return CARD_OK;
    else
        return WRONG_PAN;
}

