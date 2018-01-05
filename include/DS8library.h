// DS8.h

#include "D128API.h"
#include "windows.h"
#include "winbase.h"

#pragma once

namespace DS8library
{
	class DS8Functions
	{
		private :
			HMODULE libD128API; //API Module
			//DS8 Functional Variables
			DGD128_Initialise procInitialise; 
			DGD128_Update procUpdate;
			DGD128_Close procClose;		
			bool ENABLE; 
			int WIDTH, MODE, RECOVERY, DWELL, POLARITY, CURRENT;
			int apiRef;
			int retAPIError;
			int retError;
			int cbState;
			PD128 CurrentState;
			int nDS8;
			bool OutputState;
		public :
			int ErrorCode; //Error codes (will have a seperate header)
			int CurrentMax;
			DS8Functions(); 
			~DS8Functions();
			//Load Library
			bool loadD128APILibrary();
			//Initialize Variables
			void SetVariables(int mode, int polarity, int current, int width, int recovery, int dwell, bool Update);
			//Initialize CurrentState of DS8
			int GetState();
			//Enable/Diable the Output
			int ToggleOutput(bool enable);
			int UpdateDS8();
			void UpdateState();
			void CloseDS8();
	};
}