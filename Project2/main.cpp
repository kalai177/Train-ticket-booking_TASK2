#include<iostream>
#include "System.h"
int main() {
   System *sys = new System();
   DWORD adminmode;
begin:
    std::cout << std::endl;
    std::cout << "0 - admin mode" << std::endl;
    std::cout << "1 - user mode"<<std::endl;
    std::cout << "2-exit" << std::endl;
    std::cin >> adminmode;
    switch (adminmode) {
    case 0:
        std::cout << "You privilages is creating sets" << std::endl;
        DWORD createseats;
        std::cout << "1-createseats:" << std::endl;
        std::cin >> createseats;
        if (createseats == 1) {
            DWORD num_of_seats;
            std::cout << "Enter number of seats to be created: ";
            std::cin >> num_of_seats;
            while (num_of_seats > 0) {
                sys->addseats();
                num_of_seats--;
            }
        }
        std::cout << "Seats created successfully" << std::endl;
        goto begin;

    case 1:
        std::cout << "Your privilages are ticket booking and cancelling" << std::endl;
        std::cout << "1 - Book ticket" << std::endl;
        std::cout << "2 - Cancel Ticket" << std::endl;
        DWORD userprivilege;
        std::cin >> userprivilege;
        switch (userprivilege) {
        case 1:
            sys->bookticket();
            goto begin;

        case 2:
            sys->cancelticket();
            goto begin;
        }

    case 2:
        exit(0);

    }

   

}