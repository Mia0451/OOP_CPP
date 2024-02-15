/*
 * MovieTicketMaster.h
 *
 *  Created on: Oct 11, 2023
 *      Author: wenyishi
 */

#ifndef MOVIETICKETMASTER_H_
#define MOVIETICKETMASTER_H_

#include <string>
#include "Movie.h"
using namespace std;

// A class represent a movie theater
class MovieTicketMaster {

	// Public static data
	public:
		static const int DEFAULT_ARRAY_SIZE = 32;
		static const int DEFAULT_MOVIE_COUNT;
		static const string DEFAULT_THEATER_NAME;
		static const string DEFAULT_THEATER_LOCATION;

	// Private member data
	private:
		string theater_name;
		string theater_location;
		int movie_count;
		Movie* movie_list;

	// Public constructors
	public:
		MovieTicketMaster();
		MovieTicketMaster(string theater_name, string theater_location, int movie_count);
		~MovieTicketMaster();


		// Public member functions
		// Accessor
		string get_theater_name() const;
		string get_theater_location() const;
		int get_movie_count() const;

		// mutators
		void set_theater_name(const string& name);
		void set_theater_location(const string& location);
		void set_movie_count(int count);

		// Init the movie theater with data
		void Init();
		// Run
		void Run();

		//Private member functions
	private:
		void Menu() const;
		void ViewShowingMovies() const;
		void SearchMovie() const;
		Movie* FindMovie(const string& movie_name) const;
		void PurchaseTicket();

};

#endif /* MOVIETICKETMASTER_H_ */

