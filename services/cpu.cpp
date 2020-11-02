#include "../headers/cpu.h"

using namespace std;

CPU :: CPU(){running_job = NULL;}

void CPU :: set_job(Job *job){running_job =job;}

Job * CPU ::current_job(){return running_job;}

void CPU :: Execute(){
  // cout<<"\t\t\tCurrent Job In cpu : "<<running_job->getJobNo()<<endl;
running_job->execute();}

void CPU :: clear_cpu(){running_job = NULL;}

void CPU :: complete_currentJob(){
  Job *job = running_job;
  clear_cpu();
  // delete(job);
  // running_job=NULL;
}
