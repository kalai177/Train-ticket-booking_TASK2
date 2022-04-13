#include "System.h"
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <ios>

void System::addseats() {
	if (head == NULL) {
		head = new Train();
		Seat* seatobj = new Seat();
		head->train_seat = seatobj;
		tail = head;
		
	}
	else {
		Train* trainobj = new Train();
		Seat* seatobj = new Seat();
		trainobj->train_seat = seatobj;
		tail->next_seat = trainobj;
		trainobj->prev_seat = tail;
		
		tail = trainobj;
	}
}
bool System::show_unbooked_seats() {
	Train* temp = head;
	
	bool availseats = 0;
	if (head == NULL) {
		std::cout << "No seats available" << std::endl;
		return availseats;
	}
	std::cout << "Available seats:" << std::endl;
	while (temp != NULL) {
		if (temp->train_seat->is_booked == 0) {
			std::cout << temp->train_seat->seat_number << std::setw(10);
			availseats = 1;
		}
		temp = temp->next_seat;
	}
	std::cout << std::endl;
	return availseats;
}

void System::addticket(Ticket* ticket,DWORD seatnum) {
	Train* temp = head;
	DWORD size = 0;
	while (temp!= NULL) {
		if (temp->train_seat->seat_number == seatnum) {
			temp->train_seat->ticket_holder = ticket;
			temp->train_seat->is_booked = 1;
			std::cout << "Seats is successfully booked!!" << std::endl;
			std::cout << std::endl;
			std::cout << "Ticket no" << std::setw(25) << "Seat number" << std::setw(25) << "passenger name" << std::endl;
			std::cout << ticket->ticket_id << std::setw(25) << ticket->seat_number << std::setw(25) << ticket->username << std::endl;
			std::cout << std::endl;
			

		}
		temp = temp->next_seat;
		size++;
	}
	if (seatnum > size) {
		std::cout << "Seat Number " << seatnum << " is no available" << std::endl;
	}
}

void System::bookticket() {
	
	bool availableseats =show_unbooked_seats();
	if (availableseats) {
		DWORD booking_seat;
		if (cancelled_seat == 0) {
			std::cout << "Enter the seat number you want to book:";
			std::cin >> booking_seat;
		}
		std::cout << "Enter your name:";
		char* temp_user_name = new char[256];
		std::cin >> std::ws;
		scanf_s("%[^\n]s", temp_user_name, 256);
		DWORD username_size = strlen(temp_user_name);
		char* user_name = new char[username_size + 1];
		strcpy_s(user_name, username_size + 1, temp_user_name);
		delete[] temp_user_name;

		if (cancelled_seat == 0) {
			Ticket* create_ticket = new Ticket(booking_seat, user_name);
			addticket(create_ticket, booking_seat);

		}
		else {
			Ticket* create_ticket = new Ticket(cancelled_seat, user_name);
			addticket(create_ticket, cancelled_seat);
		}

	}
	
	
 }

void System:: cancelticket() {
	if (head == NULL) {
		std::cout << "No seats and booked tickets available" << std::endl;
		return;
	}
	std::cout << "Enter the seat number to cancel ticket:";
	DWORD cancelseat_num;
	std::cin >> cancelseat_num;
	char* passengername = new char[256];
	std::cout << "Enter your name: ";
	std::cin >> std::ws;
	scanf_s("%[^\n]s", passengername, 256);
	Train* temp = head;
	DWORD size = 0;
	while (temp != NULL) {
		if (temp->train_seat->seat_number == cancelseat_num) {
			Seat* seat = temp->train_seat;		
			if (strcmp(seat->ticket_holder->username,passengername) ==0){
				temp->train_seat->ticket_holder = NULL;
				Ticket* deletedticket = seat->ticket_holder;
				delete deletedticket;
				
				cancelled_seat = cancelseat_num;
				std::cout << "Ticket cancelled successfully" << std::endl;
			  }
			else {
				std::cout << "Credentials not matched! Username is wrong" << std::endl;
			}

			delete[] passengername;
		}
		temp = temp->next_seat;
		size++;
	}

	if (cancelseat_num > size) {
		std::cout << "Seat is not available for cancellation" << std::endl;
	}
}