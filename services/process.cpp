#include "../headers/process.h"
#include "../resources/process_resources.cpp"
#include "../resources/process_events.cpp"

using namespace std;


void Process :: start_simulation(string filename){
  system_time = 1; // process starts

  // loading the events file
  if(!events.load_file(filename)){return;}

  cout<<"[SIMULATION STARTED]\n\n";
  //cout<<(events.find_event2(1))->command<<endl;

  do{
    this->process_external_events();
    system_time ++;
  }while(system_time <= 40);

  while(!ready.is_empty()){
    auto temp = ready.extractJob();
    cout<< temp->getJobNo() << " " << temp->getPriority() << endl;
  }
  // print_stats();
}
