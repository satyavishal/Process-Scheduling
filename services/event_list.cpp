#include "../headers/event_list.h"
using namespace std;

  // inserts the obj of External_Event at the end of the vector
void Event_list :: insert_event(External_Event *e){
  events.push_back(make_pair(e->entry_time,e));
}

// loads the input file into a vector
int Event_list :: load_file(string filename){
  string line,word;
  ifstream file (filename.c_str());
  if(file.is_open()){
    while(getline(file,line)){
      stringstream line_stream(line);
      vector<string> words;
      while(line_stream>>word){words.push_back(word);}
      if(words.size() == 4){
        stringstream a(words[0]); // entry time x
        char b = words[1][0];     // command b
        stringstream c(words[2]); // priority y
        stringstream d(words[3]); // estimated time z
        int x,y,z;
        a>>x; c>>y; d>>z;
        External_Event *p = new External_Event(x,b,y,0,z);
        insert_event(p);

      }else if(words.size() == 2){
        stringstream a(words[0]); // entry time x
        char b = words[1][0];     // command b
        int x; a>>x;
        External_Event *p = new External_Event(x,b,0,0,0);
        insert_event(p);

      }else{
        stringstream a(words[0]); // entry time x
        char b = words[1][0];     // command b
        stringstream c(words[2]); // job number y
        int x,y; a>>x; c>>y;
        External_Event *p = new External_Event(x,b,0,y,0);
        insert_event(p);
      }
    }
  }else{
    cout<<"Error opening the file!"<<endl;
    return 0;
  }
  it=events.begin();
  return 1;
}

//checks if the events are completed
bool Event_list :: events_completed(){
  if(it == events.end()){return true;}
  else{return false;}
}

// can find any event in the vector
External_Event* Event_list :: find_event2(int tim){
  for(int i=0;i<events.size();i++){
    if(events[i].first == tim){return events[i].second;}
  }
  return NULL;
}

// returns the events in order after its time has reached
External_Event* Event_list :: find_event(int tim){
  if(it->first == tim){return (it++)->second;}
  else{return NULL;}
}
