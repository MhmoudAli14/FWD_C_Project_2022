/***********************************************************************
*                             Include Files                            *
***********************************************************************/

#include"app.h"

/***********************************************************************
*                        Function Definitions                          *
***********************************************************************/

void appStart(void)
{
	ST_cardData_t     cardData_1;
	ST_terminalData_t termData_1;
	ST_transaction_t  transData_1;

	char condition = TRUE;

	fillDataBase();								//Fill the dataBase with data to check the data stored from the user.

	while (TRUE)
	{
		if (condition)
		{
			//Card Functions Section.
			if (getCardHolderName(&cardData_1) == CARD_OK)           //Name -> 20:24 long (done)
			{
				if (getCardPAN(&cardData_1) == CARD_OK)				// PAN 20 long (done)
				{
					if (getCardExpiryDate(&cardData_1) == CARD_OK)  // 5 char (done)
					{
						//Terminal Function Section.
						if (getTransactionDate(&termData_1) == TERMINAL_OK)           //NOt complete yet
						{
							if (isCardExpired(cardData_1, termData_1) == TERMINAL_OK) // not complete				//yes->decline "Go to END", No->GetTransactionAmount()
							{
								if (getTransactionAmount(&termData_1) == TERMINAL_OK)
								{
									if (isBelowMaxAmount(&termData_1) == TERMINAL_OK)								//yes->decline "Go to END", No-> go to server Functions.
									{
										//Server Functions Section.
										if (isValidAccount(&cardData_1) == CARD_OK)									//Decline if notValid "Go to END", Valid-> check Amout.
										{
											if (isAmountAvailable(&termData_1) == SERVER_OK)						//Decline if insuffecient "Go to END", Suffecient-> update dataBase.
											{
												if (recieveTransactionData(&transData_1) == APPROVED)				//update DataBase
												{
													saveTransaction(&transData_1);									//Save Transcation even if its declined, "Go to END"
												}
												else
												{
													printf("Error in recieveTransactionData()\n");
													condition = FALSE;
												}
											}
											else
											{
												printf("Error in isAmountAvailable()\n");
												condition = FALSE;
											}
										}
										else
										{
											printf("Error in isValidAccount()\n");
											condition = FALSE;
										}
									}
									else
									{
										printf("Error in isBelowMaxAmount()\n");
										condition = FALSE;
									}
								}
								else
								{
									printf("Error in getTransactionAmount()\n");
									condition = FALSE;
								}
							}
							else
							{
								printf("Error in isCardExpired()\n");
								condition = FALSE;
							}
						}
						else
						{
							printf("Error in getTransactionDate()\n");
							condition = FALSE;
						}

					}
					else
					{
						printf("Error in getCardExpiryDate()\n");
						condition = FALSE;
					}
				}
				else
				{
					printf("Error in getCardPAN()\n");
					condition = FALSE;
				}
			}
			else
			{
				printf("Error in getCardHolderName()\n");
				condition = FALSE;
			}
		}
		printf("Please try again.\n");
		condition = TRUE;
	}

	//End Section
	printf("somthing went wrong Bud!\n");

}