#include <bits/stdc++.h>
#include "services/job.cpp"
#include "services/event.cpp"
#include "services/event_list.cpp"
using namespace std;

// class Simulation{
// private:
//   int n_jobs=0;
//   External_Events events;
//   CPU cpu;
//   ReadyQueue ready;
//   WaitingQueue waiting;
//
//   void process_external_events(External_Events &events, int tim){
//     auto temp = events.find_event(tim);
//     if(temp!= NULL){
//       cout<< "Processing a '"<<temp->command<<"' at time "<<tim<<":"<<endl;
//       switch(temp->command){
//         case 'J':
//         {
//           Job *j = new Job( ++n_jobs, temp->priority, tim, temp->time_estimate);
//           ready.add_job(j);
//           cout<<ready.is_empty()<<"  "<<n_jobs<<endl;
//           break;
//         }
//         case 'W':
//         {
//           break;
//         }
//         case 'R':
//         {
//           break;
//         }
//         case 'C':
//         {
//           break;
//         }
//         case 'T':
//         {
//           break;
//         }
//         default: cout<<"command Error in Process_external_events"<<endl;
//       }
//     }
//   }
//
// public:
//   void start_simulation(string filename){
//     // loading the events file
//     if(!events.load_file(filename)){return;}
//
//     //cout<<(events.find_event2(1))->command<<endl;
//
//     int system_time = 1;
//     do{
//       this->process_external_events(events,system_time);
//       system_time ++;
//     }while(system_time <= 40);
//     // print_stats();
//   }
//
//
// };


int main(){
  // Simulation sim;
  // sim.start_simulation("input.txt");

  // External_Event *a1 = new External_Event(1,'J',3,1,8);
  Event_list b;
  if(!b.load_file("tests/input.txt")){return 0;}
  // // b.insert_event(a1);
  // if(!b.find_event(1)){
  //   cout<<"null";
  // }else{
  //     cout<<"not null"<<endl;
  // }
  // cout<<b.events_completed();

  cout<< (b.find_event2(10))->command;


  return 0;
}
