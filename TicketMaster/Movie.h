/*
 * Movie.h
 *
 *  Created on: Oct 11, 2023
 *      Author: wenyishi
 */
#ifndef MOVIE_H_
#define MOVIE_H_

#include <string>
using namespace std;

// A movie class represent a Movie.
class Movie {

	//Public static data
	public:
		static const string DEFAULT_MOVIE_NAME;
		static const int DEFAULT_SEATS_AVAILABLE;
		static const double DEFAULT_TICKET_PRICE;

	//Private member data
	private:
		string movie_name;
		int seats_available;
		double ticket_price;


	public:
		// Public constructors
		// Constructor initialize with default value
		Movie();
		Movie(string& movie_name, int seats_available, double ticket_price);

		// Public destructor
		~Movie();

		// Public member functions
		// accessors functions
		string get_movie_name() const;
		int get_seats_available() const;
		double get_ticket_price() const;

		// mutator functions
		void set_movie_name(const string& name);
		void set_seats_available(int seats);
		void set_ticket_price(double price);

		// Purchase Ticket with the specified number of tickets, return -1 if failed.
		double PurchaseTicket(int ticket_num);

		// Display the detail of this movie
		void Display() const;

};

#endif /* MOVIE_H_ */
