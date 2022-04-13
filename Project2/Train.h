#include "Seat.h"
class Train {
public:
	Seat*  train_seat = NULL;
	Train* prev_seat = NULL;
	Train* next_seat = NULL;
};