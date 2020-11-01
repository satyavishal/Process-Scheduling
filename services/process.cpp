#include "../headers/process.h"
using namespace std;

Process :: Process(){this->n_jobs = 0;}

void Process :: process_external_events(Event_list &events, int tim){
  auto temp = events.find_event(tim);
  if(temp!= NULL){
    cout<< "Processing a '"<<temp->command<<"' at time "<<tim<<":"<<endl;
    switch(temp->command){
      case 'J':
      {
        // Job *j = new Job( ++n_jobs, temp->priority, tim, temp->time_estimate);
        // ready.add_job(j);
        // cout<<ready.is_empty()<<"  "<<n_jobs<<endl;
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

void Process :: start_simulation(string filename){
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
