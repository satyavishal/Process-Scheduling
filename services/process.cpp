#include "../headers/process.h"
using namespace std;

Process :: Process(){this->n_jobs = 0;}

int Process :: create_job(External_Event *current_event ){

  Job *job = new Job( ++n_jobs, current_event->priority, system_time, current_event->time_estimate);
  ready.add_job(job);
  return 1;
  // cout<<ready.is_empty()<<"  "<<n_jobs<<endl;

}

int Process :: request_IO(int job_no){
  if(cpu.current_job()!=NULL){
    waiting.insert(cpu.current_job());
    cpu.clear_cpu();
    cout<<"inserted into the waitQueue"<<endl;
  }else{
    cout<<"entered w ka else\n";
  }
  return 1;
}

int Process :: complete_IO(int job_num){
  auto job = waiting.get_job(job_num);
  waiting.remove_job(job_num);
  ready.add_job(job);
}

int Process :: terminate_job(int job_num){
  Job *job;
  job = ready.remove_job(job_num);
  if(job == NULL){
    job = waiting.get_job(job_num);
    if(job == NULL){cout<<"Job does not exist for termination"<<endl; return 0;}
    waiting.remove_job(job_num);
  }
  // job->print_stats();
  delete(job);
  return 0;
}

void Process :: process_external_events(){

  auto current_event = events.find_event(system_time);

  if(current_event!= NULL){
    cout<< "Processing a '"<<current_event->command<<"' at time "<<system_time<<":"<<endl;
    // switch(current_event->command){
    //   case 'J':
    //   {
    //     create_job(current_event);
    //     break;
    //   }
    //   case 'W':
    //   {
    //     request_IO();
    //     break;
    //   }
    //   case 'R':
    //   {
    //     complete_IO(current_event->job_num);
    //     break;
    //   }
    //   case 'C':
    //   {
    //     CPU.complete_currentJob();
    //     break;
    //   }
    //   case 'T':
    //   {
    //     terminate_job(current_event->job_num);
    //     break;
    //   }
    //   default: cout<<"command Error in Process_external_events"<<endl;
    // }
  }
}

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
