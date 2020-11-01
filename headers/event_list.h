#ifndef EVENT_LIST_H
#define EVENT_LIST_H

#include <vector>
#include <utility>
#include "event.h"

class Event_list
{
private:
  vector<pair<int,External_Event*> > events;
  vector<pair<int,External_Event*> >::iterator it;
public:
  // inserts the obj of External_Event at the end of the vector
  void insert_event(External_Event *e);

  // loads the input file into a vector
  int load_file(string filename);

  //checks if the events are completed
  bool events_completed();

  // can find any event in the vector
  External_Event* find_event2(int tim);

  // returns the events in order after its time has reached
  External_Event* find_event(int tim);

};

#endif
