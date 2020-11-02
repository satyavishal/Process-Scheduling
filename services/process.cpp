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


    if(cpu.current_job()){

      int job_completion_flag = cpu.Execute();

      if(job_completion_flag == 1){
        Job *job = cpu.current_job();
        cpu.clear_cpu();
        cout<<"JOB: "<<job->getJobNo()<<" timed out at* "<<system_time<<endl;
        print_job_termination_status(job);
        delete(job);
      }
    }
    increment_Idletime();
    system_time ++;
  }while(!events.events_completed() || (!ready.is_empty() || cpu.current_job()) );

  cout<<"[SIMULATION ENDED]"<<endl<<endl;
  // while(!ready.is_empty()){
  //   auto temp = ready.extractJob();
  //   cout<< temp->getJobNo() << " " << temp->getPriority() << endl;
  // }
  // print_stats();
}
