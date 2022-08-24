/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include"server.h"


/***********************************************************************
*                        Function Definitions                          *
***********************************************************************/

/*
* ######## Implement server-side accounts' database ######
*	Create a global array of ST_accountsDB_t for the valid accounts database
*	Fill in the array initially with any valid data
*	This array has a maximum of 255 element/account data
*/

ST_accountsDB_t  AccDataBase[ACCOUNTDATABASEELEMENTS];

void fillDataBase()
{
	AccDataBase[0].balance = 100.0;
	strcpy_s((char*)AccDataBase[0].primaryAccountNumber, 20, "1122334455667788900");

	AccDataBase[1].balance = 1000.0;
	strcpy_s((char*)AccDataBase[1].primaryAccountNumber, 20, "1122334455667788901");

	AccDataBase[1].balance = 10000.0;
	strcpy_s((char*)AccDataBase[1].primaryAccountNumber,20, "1122334455667788902");

	AccDataBase[1].balance = 100000.0;
	strcpy_s((char*)AccDataBase[1].primaryAccountNumber,20,  "1122334455667788903");

	AccDataBase[1].balance = 10500.0;
	strcpy_s((char*)AccDataBase[1].primaryAccountNumber,20, "1122334455667788904");

	AccDataBase[1].balance = 109000.0;
	strcpy_s((char*)AccDataBase[1].primaryAccountNumber,20, "1122334455667788905");

	AccDataBase[1].balance = 102000.0;
	strcpy_s((char*)AccDataBase[1].primaryAccountNumber,20, "1122334455667788906");

	AccDataBase[1].balance = 104500.0;
	strcpy_s((char*)AccDataBase[1].primaryAccountNumber,20, "1122334455667788907");

	AccDataBase[1].balance = 104570.0;
	strcpy_s((char*)AccDataBase[1].primaryAccountNumber,20, "1122334455667788908");

	AccDataBase[1].balance = 104570.0;
	strcpy_s((char*)AccDataBase[1].primaryAccountNumber,20, "1122334455667788909");
}


/*
* 
*	This function will take all transaction data and validate its data.
*	It checks the account details and amount availability.
*	If the account does not exist return DECLINED_STOLEN_CARD, if the amount is not available will return DECLINED_INSUFFECIENT_FUND, 
*	if a transaction can't be saved will return INTERNAL_SERVER_ERROR and will not save the transaction, else returns APPROVED.
*	It will update the database with the new balance.
* 	function is still in progress.
*/

EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	return SERVER_OK;
	//return INTERNAL_SERVER_ERROR;
}


/*
* 
*	This function will take card data and validate these data.
*	It checks if the PAN exists or not in the server's database.
*	If the PAN doesn't exist will return DECLINED_STOLEN_CARD, else will return OK
* 	function is still in progress.
*/

EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
	return SERVER_OK;
	//return DECLINED_STOLEN_CARD;
}


/*
*
*	This function will take terminal data and validate these data.
*	It checks if the transaction's amount is available or not.
*	If the transaction amount is greater than the balance in the database will return LOW_BALANCE, else will return OK
*	You should deliver a maximum 2min video to discuss your implementation and run different test cases on this function
*	function is still in progress.
*/

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{
	return SERVER_OK;
	//return LOW_BALANCE;
}



/*
*
* This function will take all transaction data into the transactions database.
*	It gives a sequence number to a transaction, this number is incremented once a transaction is processed into the server.
*	If saves any type of transaction, APPROVED or DECLINED, with the specific reason for declining/transaction state.
*	If transaction can't be saved will return SAVING_FAILED, else will return OK
*    function is still in progress.
*/

EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	return SERVER_OK;
	//return SAVING_FAILED;
}

/*
*
*	This function will take a transaction sequence number and search for this transaction in the database.
*	If the transaction can't be found will return TRANSACTION_NOT_FOUND, else will return OK and store the transaction in a structure.
*	function is still in progress.
*/

EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData)
{
	return SERVER_OK;
	//return TRANSACTION_NOT_FOUND;
}
