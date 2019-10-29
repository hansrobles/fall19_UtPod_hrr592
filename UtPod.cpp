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
      cout << "Song too big" << endl;
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
    if((songs == NULL)&&(songs->next == NULL)){
      return;
    }

    struct nodeArray                                                     //creates indicators or "ranks" for random sorting
    {
      Song _song;
      int rank;
    };
    
    nodeArray array[MAX_MEMORY];                                        //assuming Songs have at least 1MB of data, this is maximum array size
    
    SongNode *p = songs;
    int index = 0;
    
    while(p != NULL){
      array[index]._song = p->s;                                        //inserts all of the songs in current linked list into array
      array[index].rank = rand() % 512;                                 //random rank is attached to each song
      index ++;
      p = p->next;
    }
    
    clearMemory();                                                      //starting new linked list
    songs == NULL;
    
    for(int i = 0; i < index; i++){                                     //sorts array based on attached rank
      int best = i;

      for(int j = i + 1; j < index; j++){
         if(array[j].rank < array[best].rank){
           best = j;
         }
      }

      nodeArray temp = array[i];
      array[i] = array[best];
      array[best] = temp;
    }

    for(int i = 0; i < index; i++){                                    //inserts songs into new linked list based in rank order
      addSong(array[i]._song);
    }

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
    for(p1 = songs->next; p1 != NULL; p1 = p1->next){                                                    //performs the same swap and sort function on each increment from the head pointer to NULL
      best = p1->s;

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
