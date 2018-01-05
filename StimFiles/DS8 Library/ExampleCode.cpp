// TestingDS8ControlClass.cpp : Defines the entry point for the console application.
//

#include "DS8library.h"
#include <cassert>
#include <iostream>


void main() 
{
	//int e;
	//char str[20];
	DS8library::DS8Functions DS8Controller;

	if (DS8Controller.ErrorCode != -1)
	{
		//DS8Controller.SetVariables(NULL,NULL,10,NULL,NULL,NULL,TRUE); //Set to Defaults
		DS8Controller.ToggleOutput(TRUE);
		DS8Controller.SetVariables(NULL,NULL,20,NULL,NULL,NULL,TRUE); //Set to Defaults
		//sprintf_s(str,"%d",e);
		//printf ("Error: %s\n",str);
		printf("No Errors \n");
		//DS8Controller.SetVariables(NULL,NULL,10,NULL,NULL,NULL,TRUE); //Set to Defaults
	}

	printf("Press any key.");
	fgetc(stdin);

	DS8Controller.ToggleOutput(FALSE);
	DS8Controller.SetVariables(NULL,NULL,10,NULL,NULL,NULL,TRUE); //Set to Defaults
	DS8Controller.CloseDS8();



}

