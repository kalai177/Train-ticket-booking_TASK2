#include<Windows.h>
#include<string>
class Ticket {
public:
	static DWORD ticket_uid;
	DWORD ticket_id;
	DWORD seat_number;
	LPCSTR username;

	Ticket(DWORD seat_number, char* username) {
		this->ticket_id = ticket_uid;
		this->seat_number = seat_number;
		this->username = username;
	}
	~Ticket() {
		delete[] username;
	}

};

