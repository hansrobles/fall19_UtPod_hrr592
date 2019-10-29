//Hans Matthew Robles
//EE312
//11/01/2019

/* Student information for project:
 *
 * On my honor, Hans Matthew Robles, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Hans Matthew Robles
 * email address: hans.robles@utexas.edu
 * UTEID: hrr592
 * Section 5 digit ID: 16040
 *
 */

#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main ()
{
  UtPod t;
  
  cout << t.getRemainingMemory() << endl;

  Song s4("Easy", "Commodores", 8);
  Song s3("I Wanna Be Yours <3", "Artic Monkeys", 13);
  Song s2("Big Green Tractor", "Jason Aldean", 4);
  Song s1("AllStar", "SmashMouth", 25);
  Song s5("RedBone", "Childish Gambino", 21);
  Song s6("It's Tricky", "RUN DMC", 31);

  int result = t.addSong(s1);
  cout << "result = " << result << endl;
  result = t.addSong(s2);
  cout << "result = " << result << endl;
  result = t.addSong(s3);
  cout << "result = " << result << endl;
  result = t.addSong(s4);
  cout << "result = " << result << endl;
  t.addSong(s5);
  t.addSong(s6);

  t.showSongList();
  cout << t.getRemainingMemory() << endl;

  t.shuffle();
  t.showSongList();
  
  cout << "break" << endl;

  t.sortSongList();
  t.showSongList();

  result = t.removeSong(s2);
  cout << "result = " << result << endl;

  t.showSongList();
  cout << t.getRemainingMemory() << endl;

  t.clearMemory();
  t.showSongList();
  cout << t.getRemainingMemory() << endl;

  return 0;
}
