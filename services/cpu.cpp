#include "../headers/cpu.h"

using namespace std;

CPU :: CPU(){running_job = NULL;}

void CPU :: set_job(Job *j){running_job =j;}

Job * CPU ::current_job(){return running_job;}

void CPU :: Execute(){running_job->execute();}

void CPU :: clear_cpu(){running_job = NULL;}

void CPU :: complete_currentJob(){
  // current_job->print_stats();
  delete(running_job);
}
