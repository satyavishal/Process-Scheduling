#include "../headers/readyQueue.h"
using namespace std;

void ReadyQueue :: add_job(Job *job){
  int priority = job->getPriority() - 1;
  readyQueue[priority].push_back(job);
}

Job* ReadyQueue :: extractJob(){
  Job *job;
  for(int priority = 0;  priority < 4; priority++){
    if(!readyQueue[priority].empty()){
      job = readyQueue[priority].front();
      readyQueue[priority].pop_front();
      break;
    }
  }
  return job;
}

Job* ReadyQueue :: find_Job(){
  Job *job;
  for(int priority = 0;  priority<4; priority++){
    if(!readyQueue[priority].empty()){
      job = readyQueue[priority].front();
      // readyQueue[priority].pop_front();
      break;
    }
  }
  return job;
}

Job* ReadyQueue :: remove_job(int job_num){
  Job *job = NULL;
  Job *temp;
  for(int priority =0; priority<4; priority++){
    for(auto iterator = readyQueue[priority].begin(); iterator!= readyQueue[priority].end(); iterator ++){
      temp = *(iterator);
      if(temp->getJobNo() == job_num ){
        job =temp;
        readyQueue[priority].remove(temp);
        break;
      }
    }
  }
  return job;
}


int ReadyQueue :: is_empty(){
  for(int priority=0;priority<4;priority++){
    if(!readyQueue[priority].empty()){
      return 0;
    }
  }
  return 1;
}

void ReadyQueue :: incrementIdleTime(){
  Job *job = NULL;
  for(int priority =0; priority<4; priority++){
    for(auto iterator = readyQueue[priority].begin(); iterator!= readyQueue[priority].end(); iterator ++){
      job = *(iterator);
      job->incrementIdleTime();
    }
  }
}
