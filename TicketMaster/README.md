## 1. Program Specifications

Write a simple movie ticket master system for a theater near you. The movie ticket master system should have the following functionalities for die-hard movie fans to use:

- View all showing movies
- Search a movie
- Purchase a movie ticket

Note: This assignment is to demonstrate how to properly use pointers to process arrays of objects. Memory allocated in this program is mostly static memory. Some dynamic memory is involved to allocate the MovieTicketMaster object in the main program but that's about it. You will have plenty of chances to work with dynamic memory allocations later on throughout the course.

### Concepts Covered
- C++ classes
- Pointers to arrays of objects
- Dynamic memory allocation to an object

## 2. Class Design

You need at least two classes. You're free to come up with other classes of your own if needed.

### 2.1. Class Movie

#### Private Member Data:
- Movie name
- Seats available
- Ticket price

#### Public Static Data:
- Default movie name ("Mystery Movie")
- Default seats (100)
- Default price (14.99)

#### Public Constructors:
- Default constructor
- Non-default constructor (takes 3 parameters)

#### Public Destructor:
- Display message when Movie object is destroyed

#### Public Member Functions:
- Accessors and mutators for all member data
- PurchaseTicket
- Display

### 2.2. Class MovieTicketMaster

#### Private Member Data:
- Theater name
- Theater location
- Movie count
- An array of Movie objects

#### Public Static Data:
- Array size
- Default movie count (0)
- Default theater name ("AMC")
- Default theater location ("My City")

#### Public Constructors:
- Default constructor
- Non-default constructor

#### Public Destructor:
- Output message when MovieTicketMaster object is destroyed

#### Public Member Functions:
- Accessor/mutators
- Init
- Run

#### Private Member Functions:
- Menu
- ViewShowingMovies
- SearchMovie
- FindMovie
- PurchaseTicket
