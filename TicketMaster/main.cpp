/*
 * Main.cpp
 *
 *  Created on: Oct 11, 2023
 *      Author: wenyishi
 */
#include <iostream>
#include <string>
#include "Movie.h"
#include "MovieTicketMaster.h"
using namespace std;


int main() {
	MovieTicketMaster* ticket_master_ptr = new MovieTicketMaster("San Jose Forever 1", "San Jose Downtown", 8);
	ticket_master_ptr->Init();
	ticket_master_ptr->Run();
	delete ticket_master_ptr;
}
