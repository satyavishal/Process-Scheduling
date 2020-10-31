#include<bits/stdc++.h>
using namespace std;

class External_Event
{
public:
  int entry_time;
  char command;
  int priority;
  int job_num;
  int time_estimate;

  External_Event(int en_time,char command,int priority,int job,int e_time){
    this->entry_time = en_time;
    this->priority = priority;
    this->command = command;
    this->job_num = job;
    this->time_estimate=e_time;
  }
};

class External_Events
{
private:
  vector<pair<int,External_Event*> > events;
  vector<pair<int,External_Event*> >::iterator it;
public:
  // inserts the obj of External_Event at the end of the vector
  void insert_event(External_Event *e){
    events.push_back(make_pair(e->entry_time,e));
    if(events.size()==1){it=events.begin();}
  }

  // loads the input file into a vector
  void load_file(string filename){
    string line,word;
    ifstream f (filename.c_str());
    if(f.is_open()){
      while(getline(f,line)){
        stringstream s(line);
        vector<string> words;
        while(s>>word){words.push_back(word);}
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
    }
  }

  //checks if the events are completed
  bool events_completed(){
    if(it == events.end()){return true;}
    else{return false;}
  }

  // can find any event in the vector
  External_Event* find_event2(int time){
    for(int i=0;i<events.size();i++){
      if(events[i].first == time){return events[i].second;}
    }
    return NULL;
  }

  // returns the events in order after its time has reached
  External_Event* find_event(int time){
    if(it->first == time){return (it++)->second;}
    else{return NULL;}
  }
};

int main(){
  //External_Event *a1 = new External_Event(1,'J',3,1,8);
  External_Events b;
  // b.insert_event(a1);
  // if(!b.find_event(1)){
  //   cout<<"null";
  // }else{
  //     cout<<"not null"<<endl;
  // }
  // cout<<b.events_completed();
  b.load_file("input.txt");
  cout<< (b.find_event2(10))->command;


  return 0;
}
