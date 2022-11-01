/*
Design a movieBooking system.
Use case :
1. It should be able to list the cities where affiliate cinemas are located. - done
2. It should be able to search movies by their title, language, genre, (optional release date, and city name).
3. once you select a movie, it should display the cinemas running that movie (optional multi shows).
4. it should be able to select a show at a particular cinema and book their tickets. (optional seat allocation).

Entities:
Movie - id, title, language, genre, releaseDate,,
Cinema - , City - id, name, vector<Cinema> cinemas, isOperational
Methods: 
showOperationalCities

*/
#include <bits/stdc++.h>
using namespace std;

class Movie {
    long id,
    string title;
    string language;
    string genre;
    string releaseDate;
    vector<Cinema> cinemaList;
    bool isActive;
};
class Show {
    int id;
    string startTime;
    string endTime;
    vector<Seat> seats;
    Movie movie;
    Cinema cinema;
}
class Cinema {
    long id;
    string name;
    unordered_map<Movie, vector<Show>> movieMap;
    bool isOperational;
    vector<Seat> seats;
};
class Seat{
    int id;
    bool isbooked;
    
    Seat() {
        this.isbooked = false;
    }
}
class City {
    long id;
    string name; 
    vector<Cinema> cinemas;
    bool isOperational;
};

class Booking{
    int id;
    Show show;
    vector<Seat> seatsBooked;
};
class BookingSystemService{
    vector<City> cities;
    vector<Movie> movies;
    vector<Cinema> cinemas;
    int counter = 1;
    
    vector<City> showOperationalCities() {
        vector<City> operationalCities;
        for(City city: cities) {
            if(city.isOperational)
                operationalCities.push_back(city);
        }
        return operationalCities;
    }
    
    vector<Movie> searchMovies(string keyword, string value) {
        vector<Movie> filteredMovies;
        switch (keyword) {
            case "title":
               for(Movie movie: movies) {
                    if(movie.title == value)
                        filteredMovies.push_back(value);
                }
                break;
            case "language":
                for(Movie movie: movies) {
                    if(movie.language == value)
                        filteredMovies.push_back(value);
                }
                break;
            case "genre":
                for(Movie movie: movies) {
                    if(movie.genre == value)
                        filteredMovies.push_back(value);
                }
                break;
            case "releaseDate":
                for(Movie movie: movies) {
                    if(movie.language == value)
                        filteredMovies.push_back(value);
                }
                break;
            case "city":
                City city;
                for(City itr: cities) {
                    if(itr.name == value)
                        city = itr;
                }
                vector<Cinema> cinemas = city.cinemas;
                for(auto itr: cinemas) {
                    filteredMovies.push_back(itr.movieMap.first);
                }
                break;
        }
        return filteredMovies;
    }
    
    vector<Cinema> showMovieRunningCinemas(string movieName) {
        Movie movie;
        for(Movie mov: movies) {
            if(mov.name == movieName)
                movie = mov;
        }
        return movie.cinemas;
    }
    
    Booking bookMovieTickets(Show show, vector<int> seats) {
        Cinema cinema = show.cinema;
        Movie movie = show.movie;
        sort(seats.begin(), seats.end());
        int i=0;
        for(Seat seat: show.seats) {
            if(seat.id == seats[i]) {
                seat.isbooked = 1;
                i++;
            }
        }
        Booking booking = new Booking();
        booking.id = counter++;
        booking.show = show;
        booking.seats = seats;
        return booking;
    }
};
int main()
{
    
    
    return 0;
}
