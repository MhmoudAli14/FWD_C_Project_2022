/***********************************************************************
* Header file														   *
* @author Mahmoud Ali                                                  *
* @date August 6, 2022                                                 *
* Purpose:                  *
***********************************************************************/

#ifndef CARD_
#define CARD_


/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

//#include"terminal.h"
//#include"server.h"


/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

/* None */

#define CARDHOLDERMAX 24 
#define CARDHOLDERMIN 20
#define PRIMARACCNOMAX 19
#define PRIMARACCNOMIN 16
#define CARDEXPIRATIONSIZE 5

//testcases
/* 
#define CARDHOLDERMAX 5 
#define CARDHOLDERMIN 2
#define PRIMARACCNOMAX 5
#define PRIMARACCNOMIN 4
#define CARDEXPIRATIONSIZE 5
*/


/***********************************************************************
*                         Structures & Enums                           *
***********************************************************************/

typedef struct ST_cardData_t
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef enum EN_cardError_t
{
	CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/

/* None */


/***********************************************************************
*                        Function Prototypes                         *
***********************************************************************/

EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);

#endif /* CARD_ */