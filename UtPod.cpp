#include "UtPod.h"
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

  UtPod::UtPod()
  {
    memSize = MAX_MEMORY;
    songs = NULL;
    unsigned int currentTime = (unsigned)time(0);                          //seeds random number generator during constructor to prevent repeated a sequences
    srand(currentTime);
  }

  UtPod::UtPod(int _size)
  {
    if((_size > MAX_MEMORY)||(_size <= 0)){
      memSize = MAX_MEMORY;
    }else{
      memSize = _size;
    }
     
    songs = NULL;
    unsigned int currentTime = (unsigned)time(0);                         //seeds random number generator during constructor to prevent repeated a sequences
    srand(currentTime);

  }

  int UtPod::addSong(Song const &song)                                    //inserts new valid songs to the head of linked list
  {
    if(song.getSize() > getRemainingMemory()){
      return NO_MEMORY;
    }else{
      SongNode *temp = new SongNode;
      temp->next = songs;
      temp->s = song;
      songs = temp;
      return SUCCESS;
    }  
  }

  int UtPod::removeSong(Song const &song)
  {
    SongNode *pointer = songs;
    SongNode *prev = NULL;
    if(pointer == NULL){
      return NO_MEMORY;
    }

    while((pointer != NULL)&&((pointer->s) != song)){
      prev = pointer;
      pointer = pointer->next;
    }
     
    if(pointer == NULL){return NOT_FOUND;}

    if(prev == NULL){                                                    //if matching song is first element of the linked list
      songs = pointer->next;
      delete pointer;
    }else if(pointer != NULL){
      prev->next = pointer->next;                                        //links previous node to next node of removed node
      delete pointer;
    }

    return SUCCESS;
  }
  
  void UtPod::shuffle()
  {
    if((songs == NULL)||(songs->next == NULL)){
      return;
    }

    int songCount = 0;
    SongNode *p1 = songs;

    while(p1 != NULL){
      songCount ++;
      p1 = p1->next;
    }
    
    for(int i = 0; i < (songCount * 3); i++){                            //to simulate closest to randomization, process happens three times
      SongNode *p2 = songs;
      SongNode *p3 = songs;
      int rCount1, rCount2;
     
      rCount1 = (rand() % songCount) ;                                   //randomizes to which nth element to swap with another
      rCount2 = (rand() % songCount) ;

      for(int j = 0; j < rCount1; j++){
        p2 = p2->next;
      }

      for(int j = 0; j < rCount2; j++){
        p3 = p3->next;
      }
      
      Song temp = p2->s;
      p2->s = p3->s;
      p3->s = temp;
    }

    return;
  }
 
  void UtPod::showSongList()
  {
    if(songs == NULL){return;}

    SongNode *pointer = songs;
    while(pointer != NULL){
      cout << (pointer->s) << endl;
      pointer = pointer->next;
    }
  }
  
  void UtPod::sortSongList()
  {
    if((songs == NULL)||(songs->next == NULL)){return;}

    SongNode *p1 = songs;                                                                                 //will swap song at head pointer if applicable
    Song best = p1->s;
    SongNode *prev = NULL;
    
    for(SongNode *p2 = p1->next; p2 != NULL ; p2 = p2->next){                                             //searches if another songs has a "lesser value"
      if(p2->s < best){
        best = p2->s;
      }
    }
    
    SongNode *p2 = p1;
    if(best != p1->s){                                                                                    //will only swap if head pointer is not "best"
      while((p2 != NULL)&&(p2->s != best)){
        prev = p2;
        p2 = p2->next;
      }
      
      prev->next = p1;
      SongNode *temp = p2->next;
      p2->next = p1->next;
      p1->next = temp;
      songs = p2;                                                                                        //head pointer is now pointed at newly swapped node
    }

    prev = songs;
    for(p1 = songs->next; p1 != NULL; p1 = p1->next){                                                    //performs the same swap and sort function on each
      best = p1->s;                                                                                      //increment of the linked list

      for(SongNode *p3 = p1->next; p3 != NULL; p3 = p3->next){
        if(p3->s < best){
          best = p3->s;
        }
      }

      p2 = p1;
      if(best != p1->s){
        SongNode *prev2 = NULL;

        while((p2 != NULL)&&(p2->s != best)){
          prev2 = p2;
          p2 = p2->next;
        }
        
        prev2->next = p1;
        SongNode *temp = p2->next;
        p2->next = p1->next;
        p1->next = temp;
        prev->next = p2;
        p1 = p2;
      }

      prev = p1;
    }

    return;
  }

  void UtPod::clearMemory()
  {
    if(songs == NULL){return;}

    SongNode *pointer = songs->next;
    while(pointer != NULL){
      delete songs;
      songs = pointer;
      pointer = pointer->next;
    }

    songs = pointer;
    return;
  }

  int UtPod::getRemainingMemory()
  {
    int counter = 0;
    SongNode *pointer = songs;

    while(pointer != NULL){
      counter = counter + (pointer->s).getSize();
      pointer = pointer->next;
    }

    return (memSize - counter);
  }

  UtPod::~UtPod()
  {
    cout << "debug - in destructor" << endl;
    clearMemory();
  }
