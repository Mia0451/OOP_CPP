/*
 * MovieTicketMaster.cpp
 *
 *  Created on: Oct 11, 2023
 *      Author: wenyishi
 */
#include <iostream>
#include <string>
#include "Movie.h"
#include "MovieTicketMaster.h"
using namespace std;

const int MovieTicketMaster::DEFAULT_MOVIE_COUNT = 0;
const string MovieTicketMaster::DEFAULT_THEATER_NAME = string("AMC");
const string MovieTicketMaster::DEFAULT_THEATER_LOCATION = string("My City");


MovieTicketMaster::MovieTicketMaster():
	theater_name(DEFAULT_THEATER_NAME),
	theater_location(DEFAULT_THEATER_LOCATION),
	movie_count(DEFAULT_MOVIE_COUNT) {

	movie_list = new Movie[DEFAULT_ARRAY_SIZE];
    Movie* p = movie_list;
    for (int i = 0; i < DEFAULT_ARRAY_SIZE; ++i) {
        p = new Movie();
        p++;
    }
}

MovieTicketMaster::MovieTicketMaster(string theater_name, string theater_location, int movie_count):
	theater_name(theater_name),
	theater_location(theater_location),
	movie_count(movie_count) {

    movie_list = new Movie[DEFAULT_ARRAY_SIZE];
    Movie* p = movie_list;
    for (int i = 0; i < DEFAULT_ARRAY_SIZE; ++i) {
        p = new Movie();
        p++;
    }
}

MovieTicketMaster::~MovieTicketMaster() {
    delete[] movie_list;
	cout << "Theater " << theater_name << " at " << theater_location << " is currently closed." << endl;
}


// Public member functions
// Accessor
string MovieTicketMaster::get_theater_name() const {
	return theater_name;
}
string MovieTicketMaster::get_theater_location() const {
	return theater_location;
}
int MovieTicketMaster::get_movie_count() const {
	return movie_count;
}

// mutators
void MovieTicketMaster::set_theater_name(const string& name) {
	theater_name = name;
}
void MovieTicketMaster::set_theater_location(const string& location) {
	theater_location = location;
}
void MovieTicketMaster::set_movie_count(int count) {
	movie_count = count;
}

// Init
void MovieTicketMaster::Init() {
    const int kSize = 8;
	string movie_name_list[kSize] = {
		"The Creator",
		"Dumb Money",
		"The Nun",
		"Hocus Pocus",
		"Blue Beetle",
		"Chang An",
		"Da Hong Deng Long",
		"Wind",
	};
	int seat_list[kSize] = {80, 70, 60, 50, 30, 20, 100, 7};
	double price_list[kSize] = {28.99, 25.99, 23.99, 21.99, 19.99, 17.99, 7.3, 12.3};

	Movie* p_movie = movie_list;
	string* movie_name_ptr = movie_name_list;
	int* seat_ptr = seat_list;
	double* price_ptr = price_list;

	for (int i = 0; i < kSize; i++) {
		p_movie->set_movie_name(*movie_name_ptr);
		p_movie->set_seats_available(*seat_ptr);
		p_movie->set_ticket_price(*price_ptr);

		p_movie++;
		movie_name_ptr++;
		seat_ptr++;
		price_ptr++;
    }
	movie_count = kSize;
}

// Run
void MovieTicketMaster::Run() {
	Menu();
	int choice;
	do {
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
			case 1:
				ViewShowingMovies();
				break;
			case 2:
				SearchMovie();
				break;
			case 3:
				PurchaseTicket();
				break;
			case 4:
				cout << "Thank you!" << endl;
				break;
			default:
				Menu();
		}
	} while (choice != 4);
}

// Private member functions

// Show the menu
void MovieTicketMaster::Menu() const {
	cout << "MOVIE TICKET MASTER" << endl;
	cout << "Theater: " << theater_name << " at " << theater_location << endl;
	cout << "==============================" << endl;
	cout << " 1. View all showing movies" << endl;
	cout << " 2. Search a movie" << endl;
	cout << " 3. Purchase a ticket" << endl;
	cout << " 4. Quit" << endl;
	cout << "==============================" << endl;

}
// Display all movies in this theater
void MovieTicketMaster::ViewShowingMovies() const {
	Movie* movie_ptr = movie_list;
	for (int i = 0; i < movie_count; i++){
		movie_ptr->Display();
        movie_ptr++;
		cout << endl;
	}
}
// Search a movie
void MovieTicketMaster::SearchMovie() const {
	string search_name;
	cout << "Enter the name of the movie you want to search: ";
    cin.ignore();
	getline(cin, search_name);

	Movie* target = FindMovie(search_name);

	if(target == nullptr) {
		cout << "Movie not found." << endl;
	} else {
		target->Display();
	}
}
// Find a movie in the theater, return a pointer to the movie if found
Movie* MovieTicketMaster::FindMovie(const string& movie_name) const {
	Movie* movie_ptr = movie_list;
	for(int i = 0; i < movie_count; i++) {
		if(movie_name == movie_ptr->get_movie_name()){
			return movie_ptr;
		}
        movie_ptr++;
	}

	return nullptr;
}
// Purchase tickets for a movie
void MovieTicketMaster::PurchaseTicket() {
	string movie_name;
	cout << "Enter the name of the movie you want to purchase a ticket for: ";
    cin.ignore();
	getline(cin, movie_name);
	Movie* target = FindMovie(movie_name);

	if(target == nullptr) {
		cout << "movie not found." << endl;
		return;
	}

	int ticket_num;
	cout << "Enter the number of tickets you want to purchase: ";
	cin >> ticket_num;

	if(ticket_num <= 0){
		cout << "Invalid number of tickets." << endl;
		return;
	}

	double total_cost = target->PurchaseTicket(ticket_num);
	if (total_cost < 0){
		cout << "The show has been sold out or not enough tickets available per your request!" << endl;
	} else {
		cout << "Total cost: $" << total_cost << endl;
	}
}




