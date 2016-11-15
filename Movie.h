//
// Created by Daniel Akimchuk on 11/4/16.
//

#ifndef INC_220TERMPROJECT_MOVIE_H
#define INC_220TERMPROJECT_MOVIE_H

class Movie {

private:
    String title;
    double price;
    int year;
    int inStock;
    int wantInStock;
    Queue* waitList;

public:
    Movie(String title, double price, int year, int inStock, int wantInStock);
    Movie(Movie movie);
    ~Movie();

    void setTitle(String title);
    void setPrice(double price);
    void discountAmount(double amt);
    void discountPercent(double percent);
    void setYear;
    void setInStock;
    void setWantInStock;

    String getTitle();
    double getPrice();
    int getYear();
    int getInStock();
    int getWantInStock;

    int getNeeded();

    void addToWaitList(String customer);
    void removeFromWaitList();


};

#endif //INC_220TERMPROJECT_MOVIE_H
