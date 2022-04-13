#include "Train.h"
#include<iostream>
#include<Windows.h>
class System {
	public:
	Train* head;
	Train* tail;
	DWORD cancelled_seat = 0;
	System() {
		head = NULL;
		tail = NULL;
	}
	void addseats();
	bool show_unbooked_seats();
	void addticket(Ticket *ticket,DWORD seat_num);
	void bookticket();
	void cancelticket();
};
