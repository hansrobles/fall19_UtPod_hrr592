//Hans Matthew Robles
//EE312
//11/01/2019

#ifndef SONG_H
#define SONG_H

#include <string.h>
#include <string>
#include <iostream>

using namespace std;

class Song
{
  private:
    string title;
    string artist;
    int size;

  public:
    Song();
    //default constructor           
    //used as place holder in UtPod.cpp functions

    //Constructor with artist, title, and size parameters
    //User will pass these parameters
    Song(string artist, string title, int size);
    
    /* FUNCTION - string getTitle
     * returns the title of Song class
     precondition: title cannot be blank
    */
    string getTitle() const
    { return title; }
    

    /* FUNCTION - void setTitle
     * sets the title of Song class
     input parms - user must input a string to this function
    */
    void setTitle (string t)
    { title = t; }
    

    /* FUNCTION - string getArtist
     * returns the artist of Song class
     precondition: artist cannot be blank
    */
    string getArtist() const
    { return artist; }
    

    /* FUNCTION - void setArtist
     * sets the artist of Song class
     input parms - user must input a string to this function
    */
    void setArtist (string a)
    { artist = a; }
    

    /* FUNCTION - int getSize
     * returns the size of Song class
     precondition: size cannot be less than or equal to zero
    */
    int getSize() const
    { return size; }


    /* FUNCTION - void setSize
     * sets the size of Song class
     input parms - user must input a valid int that is not less than or equal to 0
    */
    void setSize (int s)
    { size = s; }

    bool operator <(Song const &rhs);            //declares less than comparisons for Song class
    bool operator ==(Song const &rhs);           //declares equal comparisons for Song class
    bool operator !=(Song const &rhs);           //declares not equal comparisons for Song class

    ~Song();

};

ostream& operator << (ostream& out, const Song &s);

#endif
