#include"Ticket.h";
class Seat {
	public:
		
		static DWORD seat_uid;
		DWORD seat_number;
		bool is_booked = 0;
		Ticket* ticket_holder = NULL;
		Seat() {
			this->seat_number = seat_uid;
			seat_uid++;
		}
};
