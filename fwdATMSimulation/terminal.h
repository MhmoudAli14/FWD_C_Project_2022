/***********************************************************************
* Header file														   *
* @author Mahmoud Ali                                                  *
* @date August 6, 2022                                                 *
* Purpose:															   *
***********************************************************************/

#ifndef TERMINAL_
#define TERMINAL_


/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include "stdint.h"
#include "card.h"
#include <stdio.h>
//#include"server.h"

/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

/* None */
#define TRANSITIONAMOUTMIN 0
#define CARDDATASIZE       10
/***********************************************************************
*                         Structures & Enums                           *
***********************************************************************/

typedef struct ST_terminalData_t
{
	float transAmount;
	float maxTransAmount;
	uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
	TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t;

/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/

/* None */
float transAmount;

/***********************************************************************
*                        Function Prototypes                         *
***********************************************************************/

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData);
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData);
EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData);
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData);

#endif /* TERMINAL_ */