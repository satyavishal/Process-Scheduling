#include "../headers/cpu.h"

using namespace std;

CPU :: CPU(){running_job = NULL;}

void CPU :: set_job(Job *job){running_job =job;}

Job * CPU ::current_job(){return running_job;}

int CPU :: Execute(){

running_job->execute();
return running_job->check_job_completed();

}

void CPU :: clear_cpu(){running_job = NULL;}

void CPU :: complete_currentJob(){
  Job *job = running_job;
  clear_cpu();
  // delete(job);
  // running_job=NULL;
}
