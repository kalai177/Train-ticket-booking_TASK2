#include "System.h"
#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <ios>
DWORD System::totalseats = 50;
DWORD System::middleseat = 25;
DWORD System::leftmin = 0;
DWORD System::rightmax = 51;

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

void System::findmiddleticket() {
	Train* temp = head;
	DWORD count = 1;
	while (temp != NULL) {

		if (count == middleseat) {
			middlepointer = temp;
			leftpointer = temp->prev_seat;
			rightpointer = temp->next_seat;
			leftside = count;
			rightside = count;
			break;
		}

		temp = temp->next_seat;
		count++;
	}

}

void System::changeseatsettings() {
	totalseats += totalseats;
	middleseat = totalseats - 25;
	leftmin = middleseat - 25;
	rightmax = middleseat + 25 + 1;
}

void System::bookticket() {

	std::cout << "Enter your name:";
	char* temp_user_name = new char[256];
	std::cin >> std::ws;
	scanf_s("%[^\n]s", temp_user_name, 256);
	DWORD username_size = strlen(temp_user_name);
	char* user_name = new char[username_size + 1];
	strcpy_s(user_name, username_size + 1, temp_user_name);
	delete[] temp_user_name;


	
	if (cancelledseats.empty()) {
		if (leftside==middleseat && rightside == middleseat) {
			Ticket* create_ticket = new Ticket(middleseat, user_name);
			middlepointer->train_seat->ticket_holder = create_ticket;
			middlepointer->train_seat->is_booked = 1;
			isleft = 1;
			leftside = middleseat - 1;
			rightside = middleseat + 1;
			std::cout << "Seats is successfully booked!!" << std::endl;
			std::cout << "Ticket no" << std::setw(25) << "Seat number" << std::setw(25) << "passenger name" << std::endl;
			std::cout << create_ticket->ticket_id << std::setw(25) << create_ticket->seat_number << std::setw(25) << create_ticket->username << std::endl;
		   }
		else if (isleft == 1 && leftside > leftmin) {
			Ticket* create_ticket = new Ticket(leftside, user_name);
			leftpointer->train_seat->ticket_holder = create_ticket;
			leftpointer->train_seat->is_booked = 1;
			leftpointer = leftpointer->prev_seat;
			leftside--;
			isleft = 0;
			std::cout << "Seats is successfully booked!!" << std::endl;
			std::cout << "Ticket no" << std::setw(25) << "Seat number" << std::setw(25) << "passenger name" << std::endl;
			std::cout << create_ticket->ticket_id << std::setw(25) << create_ticket->seat_number << std::setw(25) << create_ticket->username << std::endl;
		}
		else if (rightside < rightmax || rightside < rightmax && leftside <= leftmin) {
			Ticket* create_ticket = new Ticket(rightside, user_name);
			rightpointer->train_seat->ticket_holder = create_ticket;
			rightpointer->train_seat->is_booked = 1;
			rightpointer = rightpointer->next_seat;
			rightside++;
			isleft = 1;
			std::cout << "Seats is successfully booked!!" << std::endl;
			std::cout << "Ticket no" << std::setw(25) << "Seat number" << std::setw(25) << "passenger name" << std::endl;
			std::cout << create_ticket->ticket_id << std::setw(25) << create_ticket->seat_number << std::setw(25) << create_ticket->username << std::endl;
		}
		else {
			std::cout << "Seats are not available to book!!" << std::endl;
		}
	}
	else {
		Train* trainobj = cancelledseats.front();
		cancelledseats.pop();
		Ticket* create_ticket = new Ticket(trainobj->train_seat->seat_number, user_name);
		trainobj->train_seat->ticket_holder = create_ticket;
		trainobj->train_seat->is_booked = 1;
		std::cout << "Seats is successfully booked!!" << std::endl;
		std::cout << "Ticket no" << std::setw(25) << "Seat number" << std::setw(25) << "passenger name" << std::endl;
		std::cout << create_ticket->ticket_id << std::setw(25) << create_ticket->seat_number << std::setw(25) << create_ticket->username << std::endl;
			
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
				temp->train_seat->is_booked = 0;
				Ticket* deletedticket = seat->ticket_holder;
				delete deletedticket;
				cancelledseats.push(temp);
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