#pragma once

#pragma warning(disable : 4200) 

typedef struct _STATEFLAGS {
	union {
		struct {
			unsigned int OVERENERGY : 1;
			unsigned int HWERROR : 1;
			unsigned int reserved : 30;
		};
		int VALUE;
	};
} STATEFLAGS;

typedef struct _CONTROLFLAGS {
	union {
		struct {
			int ENABLE : 2;
			int MODE : 3;
			int POLARITY : 3;
			int SOURCE : 3;
			int ZERO : 2;
			int TRIGGER : 2;
			int NOBUZZER : 2;
			int RESERVED : 15;
		};
		int VALUE;
	};
} CONTROLFLAGS;

typedef struct _D128STATE {
	CONTROLFLAGS CONTROL;
	int DEMAND;
	int WIDTH;
	int RECOVERY;
	int DWELL;
	unsigned int CPULSE;
	unsigned int COOC;
	unsigned int CTOOFAST;
	STATEFLAGS FSTATE;

} D128STATE;

typedef struct _D128DEVICESTATE {
	int D128_DeviceID;
	int D128_VersionID;
	int D128_Error;
	D128STATE D128_State;
} D128DEVICESTATE;

typedef struct _DEVHDR {
	int DeviceCount;
} DEVHDR;

typedef struct _D128 {
	DEVHDR Header;
	D128DEVICESTATE State[];
} D128, *PD128;


typedef void(__stdcall *DGClientInitialiseProc)(
	int Result,
	void * CallbackParam
	);

typedef void(__stdcall *DGClientUpdateProc)(
	int Result,
	D128 * CurrentState,
	void * CallbackParam
	);

typedef void(__stdcall *DGClientCloseProc)(
	int Result,
	void * CallbackParam
	);

typedef int(__stdcall *DGD128_Initialise)(
	int * Reference,
	int * InitError,
	DGClientInitialiseProc CallbackProc,
	void * CallbaskParam
	);

typedef int(__stdcall *DGD128_Update)(
	int Reference,
	int * Error,
	PD128 NewState,
	int cbNewState,
	PD128 CurrentState,
	int * cbCurrentState,
	DGClientUpdateProc CallbacProc,
	void * CallbackParam
	);

typedef int(__stdcall *DGD128_Close)(
	int * Reference,
	int * Error,
	DGClientCloseProc CallbackProc,
	void * CallbackParam
	);

