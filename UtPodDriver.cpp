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

int main (int argc, char *argv[])
{
  cout << "START OF PROGRAM" << '\n' << endl;

  UtPod t;                                                                                  //creating UtPod variable
  int result;
  string lineBreak = ">>>>>>>>>>LINE BREAK<<<<<<<<<<";
  
  cout << t.getRemainingMemory() << endl;

  Song s1("Beatles", "Hey Jude", 4);
  result = t.addSong(s1);
  cout << "add result = " << result << '\n' << endl;

  t.showSongList();
  cout << '\n' << lineBreak << '\n' << endl;

  Song s2("Beatles", "Yesterday", 5);
  result = t.addSong(s2);
  cout << "add result = " << result << '\n' << endl;

  t.showSongList();
  cout << "remaining memory = " << t.getRemainingMemory() << endl;
  cout << '\n' << lineBreak << '\n' << endl;

  Song s3("Beatles", "Eleanor Rigby", 6);
  result = t.addSong(s3);
  cout << "add result = " << result <<endl;

  Song s4("Queen", "Don't Stop Me Now", 7);
  result = t.addSong(s4);
  cout << "add result = " << result << endl;

  Song s5("Queen", "Fat Bottomed Girls", 8);
  result = t.addSong(s5);
  cout << "add result = " << result << '\n' << endl;

  t.showSongList();
  cout << "remaining memory = " << t.getRemainingMemory() << endl;
  cout << '\n' << lineBreak << '\n' << endl;

  cout << "CALLING SHUFFLE" << '\n' << endl;
  t.shuffle();
  t.showSongList();
  cout << '\n' << lineBreak << '\n' << endl;
  
  cout << "CALLING SHUFFLE" << '\n' << endl;
  t.shuffle ();
  t.showSongList();
  cout << '\n' << lineBreak << '\n' << endl;

  cout << "CALLING SORT SONGLIST" << '\n' << endl;
  t.sortSongList();
  t.showSongList();
  cout << '\n' << lineBreak << '\n' << endl;

  cout << "CALLING REMOVE SONG" << '\n' << endl;
  result = t.removeSong(s1);
  cout << "remove result = " << result << endl;
  cout << "remaining memory = " << t.getRemainingMemory() << '\n' << endl;
  t.showSongList();
  cout << '\n' << lineBreak << '\n' << endl;
  
  result = t.addSong(s3);
  cout << "add result = " << result << '\n' << endl;
  t.sortSongList();
  t.showSongList();
  cout << '\n' << "remaining memory = " << t.getRemainingMemory() << endl;
  cout << '\n' << lineBreak << '\n' << endl; 

  cout << "CLEARING MEMORY" << '\n' << endl;
  t.clearMemory();
  cout << '\n' << "remaining memory = " << t.getRemainingMemory() << endl;
  cout << '\n' << lineBreak << '\n' << endl;

  cout << "TEST FOR REMOVING SONGS WHEN LINKED LIST HAS ZERO" << '\n' << endl;
  cout << "removing " << s2 << endl;
  result = t.removeSong(s2);
  cout << "remove result = " << result << endl;
  cout << '\n' << lineBreak << '\n' << endl;

  Song s6("AC/DC", "Ride On", 36);
  cout << "add result = " << t.addSong(s6) << endl;

  Song s7 ("Queen", "Radio Gaga", 24);
  cout << "add result = " << t.addSong(s7) << endl;

  Song s8 ("Traveling Wilburys", "Cool Dry Place", 57);
  cout << "add result = " << t.addSong(s8) << endl;

  Song s9 ("BROCKHAMPTON", "Boogie", 21);
  cout << "add result = " << t.addSong(s9) << endl;

  Song s10 ("Queen", "Radio Gaga", 32);
  cout << "add result = " << t.addSong(s10) << endl;

  Song s11 ("Siames", "Summer Nights", 97);
  cout << "add result = " << t.addSong(s11) << endl;

  Song s12 ("Traveling Wilburys", "End Of The Line", 45);
  cout << "add result = " << t.addSong(s12) << endl;
  cout << '\n' << lineBreak << '\n' << endl;

  cout << "ADDING SONGS TO LINKED LIST WITH SONG DATA LARGER THAN AVAILABLE IN UTPOD" << '\n' << endl;
  cout << "remaining memory = " << t.getRemainingMemory() << endl;
  Song s13 ("Michael Jackson", "Bad", 500);
  cout << "adding " << s13 << endl;
  cout << "add result = " << t.addSong(s13) << endl;
  cout << '\n' << lineBreak << '\n' << endl;

  cout << "TESTING SORT BY DATA SIZE" << '\n' << endl;
  t.sortSongList();
  t.showSongList();
  cout << '\n' << "remaining memory = " << t.getRemainingMemory() << endl;
  cout << '\n' << lineBreak << '\n' << endl;

  cout << "TESTING FOR REMOVING A SONG THAT DOES NOT EXIST" << '\n' << endl;
  Song s14 ("John Denver", "Take Me Home", 28);
  t.sortSongList();
  t.showSongList();
  cout << '\n' << "removing " << s14 << endl;
  cout << "remove result = " << t.removeSong(s14) << endl;
  cout << '\n' << lineBreak << '\n' << endl;

  cout << "CREATING UTPODS THAT HAVE OUT OF RANGE DATA SIZE THAT MAX_MEMORY" << '\n' << endl;
  cout << "Creating testPod1 with 513MB of data" << endl;
  UtPod testPod1(513);
  cout << "testPod1 total memory = " << testPod1.getTotalMemory() << endl;
  cout << "Creating testPod2 with 0MB of data" << endl;
  UtPod testPod2(0);
  cout << "testPod2 total memory = " << testPod2.getTotalMemory() << endl;
  UtPod testPod3(-2);
  cout << "Creating testPod3 with -2MB of data" << endl;
  cout << "testPod3 total memory = " << testPod3.getTotalMemory() << endl;
  cout << '\n' << lineBreak << '\n' << endl;

  cout << "CREATING UTPODS THAT HAVE CUSTOM DATA WITHIN RANGE" << '\n' << endl;
  cout << "Creating testPod4 with 246MB of data" << endl;
  UtPod testPod4(246);
  cout << "testPod4 total memory = " << testPod4.getTotalMemory() << endl;
  cout << '\n' << lineBreak << '\n' << endl;

  cout << "ACCESSING SORT, SHUFFLE, AND SHOW WITH UTPOD THAT HAS ZERO SONGS" << '\n' << endl;
  cout << "Calling testPod4.showSongList()" << endl;
  testPod4.showSongList();
  cout << "Calling testPod4.shuffle()" << endl;
  testPod4.shuffle();
  testPod4.showSongList();
  cout << "Calling testPod4.sortSongList()" << endl;
  testPod4.sortSongList();
  testPod4.showSongList();
  cout << '\n' << lineBreak << '\n' << endl;

  cout << "CALLING SORT, SHUFFLE, AND SHOW WITH UTPOD THAT HAS ONE SONG" << '\n' << endl;
  result = testPod4.addSong(s14);
  cout << "add result = " << result << '\n' << endl;
  testPod4.showSongList();
  cout << "Calling testPod4.shuffle();" << endl;
  testPod4.shuffle();
  testPod4.showSongList();
  cout << "Calling testPod4.sortSongList()" << endl;
  testPod4.sortSongList();
  testPod4.showSongList();
  cout << '\n' << lineBreak << '\n' << endl;

  cout << "REMOVING FIRST INSTANCE OF SONG IN UTPOD CONTAINING MULTIPLE INSTANCES OF THE SONG" << '\n' << endl;
  result = testPod4.addSong(s12);
  cout << "add result = " << result << endl;
  result = testPod4.addSong(s11);
  cout << "add result = " << result << endl;
  result = testPod4.addSong(s14);
  cout << "add result = " << result << endl;
  result = testPod4.addSong(s10);
  cout << "add result = " << result << '\n' << endl;
  testPod4.showSongList();
  cout << '\n' << "removing " << s14 << endl;
  result = testPod4.removeSong(s14);
  cout << "remove result = " << result << endl;
  testPod4.showSongList();
  cout << '\n' << lineBreak << '\n' << endl; 
  
  cout << "SORTING WITH MULTIPLE IDENTICAL SONGS" << '\n' << endl;
  result = testPod4.removeSong(s11);
  cout << "remove result = " << result << endl;
  result = testPod4.addSong(s14);
  cout << "add result = " << result << endl;
  result = testPod4.addSong(s14);
  cout << "add result = " << result << endl;
  cout << "remaining memory = " << testPod4.getRemainingMemory() << '\n' << endl;
  cout << "calling testPod4.sortSongList()" << endl;
  testPod4.sortSongList();
  testPod4.showSongList();
  cout << '\n' << "calling testPod4.shuffle()" << endl;
  testPod4.shuffle();
  testPod4.showSongList();
  cout << '\n' << "calling testPod4.sortSongList()" << endl;
  testPod4.sortSongList();
  testPod4.showSongList();
  cout << '\n' << lineBreak << '\n' << endl;

  cout << "TESTING WHETHER OTHER FUNCTIONS WORK AFTER CLEAR MEMORY" << '\n' << endl;
  t.showSongList();
  cout << "remaining memory = " << t.getRemainingMemory() << '\n' << endl;
  cout << "calling t.clearMemory()" << endl;
  t.clearMemory();
  t.showSongList();
  cout << "t total memory = " << t.getTotalMemory() << endl;
  cout << "remaining memory = " << t.getRemainingMemory() << '\n' << endl;
  result = t.addSong(s11);
  cout << "add result = " << result << endl;
  result = t.addSong(s10);
  cout << "add result = " << result << endl;
  result = t.addSong(s9);
  cout << "add result = " << result << endl;
  result = t.addSong(s8);
  cout << "add result = " << result << endl;
  result = t.addSong (s7);
  cout << "add result = " << result << endl;
  result = t.addSong (s6);
  cout << "add result = " << result << endl;
  cout << "remaining memory = " << t.getRemainingMemory() << endl;

  t.showSongList();
  cout << '\n' << "calling t.shuffle()" << endl;
  t.shuffle();
  t.showSongList();
  cout << '\n' << "calling t.sortSongList()" << endl;
  t.sortSongList();
  t.showSongList();
  
  cout << '\n' << "removing " << s9 << endl;
  result = t.removeSong(s9);
  cout << "remove result = " << result << endl;
  cout << "remaining memory = " << t.getRemainingMemory() << endl;
  t.showSongList();
  cout << '\n' << lineBreak << '\n' << endl;

  return 0;
}
