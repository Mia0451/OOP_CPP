/*
 * Movie.cpp
 *
 *  Created on: Oct 11, 2023
 *      Author: wenyishi
 */

#include <iostream>
#include <string>
#include "Movie.h"
using namespace std;

const string Movie::DEFAULT_MOVIE_NAME = string("Mystery Movie");
const int Movie::DEFAULT_SEATS_AVAILABLE = 100;
const double Movie::DEFAULT_TICKET_PRICE = 14.99;

Movie::Movie():movie_name(DEFAULT_MOVIE_NAME), seats_available(DEFAULT_SEATS_AVAILABLE), ticket_price(DEFAULT_TICKET_PRICE) {}
Movie::Movie(string& movie_name, int seats_available, double ticket_price) {
	this->movie_name = movie_name;
	this->seats_available = seats_available;
	this->ticket_price = ticket_price;
}
Movie::~Movie() {
	cout << "Movie " << movie_name << " is no longer showing ..." << endl;
}

// getter
string Movie::get_movie_name() const {
	return movie_name;
}
int Movie::get_seats_available() const {
	return seats_available;
}
double Movie::get_ticket_price() const {
	return ticket_price;
}

// setter
void Movie::set_movie_name(const string& name) {
	movie_name = name;
}
void Movie::set_seats_available(int seats) {
	seats_available = seats;
}
void Movie::set_ticket_price(double price) {
	ticket_price = price;
}

// Purchase ticket; if failed will return -1; return the total cost if succeeded
double Movie::PurchaseTicket(int ticket_num) {
	if(ticket_num > seats_available) {
		return -1;
	} else {
		seats_available -= ticket_num;
		return ticket_num * ticket_price;
	}
}
void Movie::Display() const {
	cout << "Movie: " << movie_name << endl;
	cout << "Seat Available: " << seats_available << endl;
	cout << "Ticket Price: $" << ticket_price << endl;
}





