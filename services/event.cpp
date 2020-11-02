#include "../headers/event.h"
using namespace std;

External_Event :: External_Event(int entry_time,char command,int priority,int job,int estimated_time){
  this->entry_time = en_time;
  this->priority = priority;
  this->command = command;
  this->job_num = job;
  this->time_estimate=e_time;
}
