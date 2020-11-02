#include "../headers/process.h"
#include "../resources/process_resources.cpp"
#include "../resources/process_events.cpp"
#include "../resources/printers.cpp"

using namespace std;


void Process :: start_simulation(string filename){
  system_time = 1; // process starts

  // loading the events file
  if(!events.load_file(filename)){return;}

  cout<<"[SIMULATION STARTED]\n\n";
  //cout<<(events.find_event2(1))->command<<endl;

  do{
    process_external_events();
    process_internal_events();
    if(cpu.current_job()){cpu.Execute();}
    system_time ++;
  }while(system_time <= 40);

  cout<<"[SIMULATION ENDED]"<<endl<<endl;
  // while(!ready.is_empty()){
  //   auto temp = ready.extractJob();
  //   cout<< temp->getJobNo() << " " << temp->getPriority() << endl;
  // }
  // print_stats();
}
