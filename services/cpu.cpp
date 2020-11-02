#include "../headers/cpu.h"

using namespace std;

CPU :: CPU(){this->running_job = NULL;}

void CPU :: set_job(Job *j){this->running_job =j;}

Job * CPU ::current_job(){return this->running_job;}

void CPU :: Execute(){this->running_job->execute();}

void CPU :: clear_cpu(){this->running_job = NULL;}

void CPU :: complete_currentJob(){
  this->current_job->print_stats();
  delete(this->current_job);
}
