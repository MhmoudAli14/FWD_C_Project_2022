/***********************************************************************
* Header file														   *
* @author Mahmoud Ali                                                  *
* @date August 6, 2022                                                 *
* Purpose:                  *
***********************************************************************/

#ifndef SERVER_
#define SERVER_


/***********************************************************************
*                             Include Files                            *
***********************************************************************/
#include <string.h>
#include <stdint.h>
#include"card.h"
#include"terminal.h"

/***********************************************************************
*                            Macros & Typedef                          *
***********************************************************************/

/* None */
#define ACCOUNTDATABASEELEMENTS 255 

/***********************************************************************
*                         Structures & Enums                           *
***********************************************************************/

typedef enum EN_transState_t
{
	APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef struct ST_transaction_t
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t terminalData;
	EN_transState_t transState;
	uint32_t transactionSequenceNumber;
}ST_transaction_t;

typedef enum EN_serverError_t
{
	SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE
}EN_serverError_t;

typedef struct ST_accountsDB_t
{
	float balance;
	uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;

/***********************************************************************
*                   Global Variables Declarations                      *
***********************************************************************/


/*
* ######## Implement server-side accounts' database ######
*	Create a global array of ST_accountsDB_t for the valid accounts database
*	Fill in the array initially with any valid data
*	This array has a maximum of 255 element/account data
*/

//extern ST_accountsDB_t AccDataBase[ACCOUNTDATABASEELEMENTS];

/***********************************************************************
*                        Function Prototypes                         *
***********************************************************************/

EN_transState_t recieveTransactionData(ST_transaction_t* transData);
EN_serverError_t isValidAccount(ST_cardData_t* cardData);
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData);
EN_serverError_t saveTransaction(ST_transaction_t* transData);
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData);

void fillDataBase();


#endif /* SERVER_ */
