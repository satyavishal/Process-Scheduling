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

  do{
    process_external_events();  //processes the external events from the events list and take action depending on the command given


    process_internal_events();  // 1. loads a job into the cpu if CPU is empty, 2. Swaps a Higher priority job from ready Queue with the current running job in the CPU


    if(cpu.current_job()){

      int job_completion_flag = cpu.Execute();    // increments the RunningTime of the Job, Decrements the Timeremaining and returns the Status of job completion

      // if the job is completed its stats are printed and it is cleared from the CPU, and the job is deleted
      if(job_completion_flag == 1){
        Job *job = cpu.current_job();
        cpu.clear_cpu();
        cout<<"JOB: "<<job->getJobNo()<<" timed out at* "<<system_time<<endl;
        print_job_termination_status(job);
        delete(job);
      }
    }

    increment_Idletime();   // increments the idle time of all the jobs in the system
    system_time ++;

  }while(!events.events_completed() || (!ready.is_empty() || cpu.current_job()) );

  cout<<"[SIMULATION ENDED]"<<endl<<endl;

  waiting.clear_waitqueue(); // clears the waiting queue of all the jobs

}
