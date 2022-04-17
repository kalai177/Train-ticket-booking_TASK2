#include "Train.h"
#include<iostream>
#include<Windows.h>
#include<queue>
class System {
	public:
	Train* head;
	Train* tail;
	Train* middlepointer;
	Train* leftpointer;
	Train* rightpointer;
	DWORD leftside = 0;
	DWORD rightside = 0;
	 bool isleft = 0;
	 static DWORD leftmin;
	 static DWORD rightmax;
	 static DWORD totalseats;
	 static DWORD middleseat;
	 std::queue<Train*>cancelledseats;
	System() {
		head = NULL;
		tail = NULL;
		middlepointer = NULL;
		leftpointer = NULL;
		rightpointer = NULL;
	}
	void addseats();
	void changeseatsettings();
	void findmiddleticket();
	void bookticket();
	void cancelticket();
};
