#include "Song.h"

using namespace std;

  
  Song::Song()
  {
    title = "Blank";
    artist = "Blank";
    size = 0;
  }

  Song::Song(string _artist, string _title, int _size)
  {
    artist = _artist;
    title = _title;
    size = _size;
  }

  ostream& operator << (ostream& out, const Song &s)
  {
    out << s.getTitle() << " by " << s.getArtist() << " - " << s.getSize();
    return out;
  }

  bool Song::operator <(Song const &rhs)
  {
    //compares artist, title, then size in that sequences

    if(artist.compare(rhs.artist) < 0){
      return true;
    }

    if(artist.compare(rhs.artist) == 0){
      if(title.compare(rhs.title) < 0){
        return true;
      }
    }

    if((title.compare(rhs.title) == 0)&&(artist.compare(rhs.artist) == 0)){
      if(size < rhs.size){
        return true;
      }
    }
    
    return false;
  }

  bool Song::operator ==(Song const &rhs)
  {
    if((title.compare(rhs.title) == 0)&&(artist.compare(rhs.artist) == 0)&&(size == rhs.size)){
      return true;
    }else{
      return false;
    }
  }

  bool Song::operator !=(Song const &rhs)
  {
    if((title.compare(rhs.title) != 0)||(artist.compare(rhs.artist) != 0)||(size != rhs.size)){
      return true;
    }else{
      return false;
    }
  }

  Song::~Song()
  {
    cout << "debug - in destructor for song" << endl;
  }
