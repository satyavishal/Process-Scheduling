#include <bits/stdc++.h>

using namespace std;

class Job{
private:
  int jobNo, priority, entryTime, timeRemaining;
  int runningTime;
  int idleTime;
  int cpuEntryCount;
  int timeEstimate;
  int cpuEntryTime;
public:
  // job number,priority,entrytime,timeRemaining
  Job(int j,int p, int e, int t){
    this->jobNo =j;
    this->priority =p;
    this->entryTime = e;
    this->timeRemaining = t;
    this->runningTime  = 0;
    this->idleTime = 0;
    this-> cpuEntryCount =0;
    this ->timeEstimate = 0;
    this-> cpuEntryTime =0;
  }
  void setCpuEntryTime(int c){this->cpuEntryTime  = c;}
  //Time Estimate
  int getTimeEstimate(){return this->timeEstimate;}
  void setTimeEstimate(int t){this->timeEstimate = t;}
  //Job number
  int getJobNo(){return this->jobNo;}
  void setJobNo(int j){this->jobNo = j;}
  //priority
  int getPriority(){return this->priority;}
  void setPriority(int p){this->priority = p;}

  int getEntryTime(){return this->entryTime;} // system entry time

  int getTimeRemaining(){return this->timeRemaining;}

  int getRunningTime(){return  this->runningTime;}

  int getIdleTime(){return   this->idleTime;}

  int getCpuEntryCount(){return  this->cpuEntryCount;}

  void incrementCpuEntryCount(){this->cpuEntryCount++;}

  void incrementIdleTime(){this->idleTime++;}

  void execute(){this->timeRemaining--; this->runningTime++;}

  int compare(Job *j){
    if(this->priority == j->priority){return 0;}
    else if(this->priority > j->priority){return 1;}
    else {return -1;}
  }

};


class CPU{
private:
  Job *current;
public:
  CPU(){
    this->current = NULL;
  }
  void set_job(Job *j){this->current =j;}
  Job *current_job(){return this->current;}
  void Execute(){this->current->execute();}
};

class ReadyQueue{
private:
  list<Job*> readyQueue[4];
public:
  void add_job(Job *j){
    int c = j->getPriority() - 1;
    readyQueue[c].push_back(j);
  }

  Job *extractJob(){
    Job *j;
    for(int i = 0;  i<4; i++){
      if(!readyQueue[i].empty()){
        j = readyQueue[i].front();
        readyQueue[i].pop_front();
        break;
      }
    }
    return j;
  }

  int is_empty(){
    for(int i=0;i<4;i++){
      if(!readyQueue[i].empty()){
        return 0;
      }
    }
    return 1;
  }

};


class WaitingQueue{
private:
  unordered_map<int,Job*> waitqueue;
public:
  void insert(Job *j){this->waitqueue[j->getJobNo()] = j;}
  Job* get_job(int k){return this->waitqueue[k];}
  void clear_wq(){this->waitqueue.erase(this->waitqueue.begin(),this->waitqueue.end());}
  int get_size(){return this->waitqueue.bucket_count();}
};



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
  }

  // loads the input file into a vector
  int load_file(string filename){
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
      return 0;
    }
    it=events.begin();
    return 1;
  }

  //checks if the events are completed
  bool events_completed(){
    if(it == events.end()){return true;}
    else{return false;}
  }

  // can find any event in the vector
  External_Event* find_event2(int tim){
    for(int i=0;i<events.size();i++){
      if(events[i].first == tim){return events[i].second;}
    }
    return NULL;
  }

  // returns the events in order after its time has reached
  External_Event* find_event(int tim){
    if(it->first == tim){return (it++)->second;}
    else{return NULL;}
  }
};



class Simulation{
private:
  int n_jobs=0;
  External_Events events;
  CPU cpu;
  ReadyQueue ready;
  WaitingQueue waiting;

  void process_external_events(External_Events &events, int tim){
    auto temp = events.find_event(tim);
    if(temp!= NULL){
      cout<< "Processing a '"<<temp->command<<"' at time "<<tim<<":"<<endl;
      switch(temp->command){
        case 'J':
        {
          Job *j = new Job( ++n_jobs, temp->priority, tim, temp->time_estimate);
          ready.add_job(j);
          cout<<ready.is_empty()<<"  "<<n_jobs<<endl;
          break;
        }
        case 'W':
        {
          break;
        }
        case 'R':
        {
          break;
        }
        case 'C':
        {
          break;
        }
        case 'T':
        {
          break;
        }
        default: cout<<"command Error in Process_external_events"<<endl;
      }
    }
  }

public:
  void start_simulation(string filename){
    // loading the events file
    if(!events.load_file(filename)){return;}

    //cout<<(events.find_event2(1))->command<<endl;

    int system_time = 1;
    do{
      this->process_external_events(events,system_time);
      system_time ++;
    }while(system_time <= 40);
    // print_stats();
  }


};


int main(){
  Simulation sim;
  sim.start_simulation("input.txt");

  // External_Event *a1 = new External_Event(1,'J',3,1,8);
  // External_Events b;
  // if(!b.load_file("input.txt")){return 0;}
  // // b.insert_event(a1);
  // if(!b.find_event(1)){
  //   cout<<"null";
  // }else{
  //     cout<<"not null"<<endl;
  // }
  // cout<<b.events_completed();

  // cout<< (b.find_event2(10))->command;


  return 0;
}
