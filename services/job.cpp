#include "../headers/job.h"
using namespace std;

Job :: Job(int j,int p, int e, int t){
  this->jobNo =j;
  this->priority =p;
  this->entryTime = e;
  this->timeRemaining = t;
  this->runningTime  = 0;
  this->idleTime = 0;
  this-> cpuEntryCount =0;
  this ->timeEstimate = t;
  this-> cpuEntryTime =0;
}

void Job :: setCpuEntryTime(int c){this->cpuEntryTime  = c;}
//Time Estimate
int Job :: getTimeEstimate(){return this->timeEstimate;}
void Job :: setTimeEstimate(int t){this->timeEstimate = t;}
//Job number
int Job :: getJobNo(){return this->jobNo;}
void Job :: setJobNo(int j){this->jobNo = j;}
//priority
int Job :: getPriority(){return this->priority;}
void Job :: setPriority(int p){this->priority = p;}

int Job :: getEntryTime(){return this->entryTime;} // system entry time

int Job :: getTimeRemaining(){return this->timeRemaining;}

int Job :: getRunningTime(){return  this->runningTime;}

int Job :: getIdleTime(){return   this->idleTime;}

int Job :: getCpuEntryCount(){return  this->cpuEntryCount;}

void Job :: incrementCpuEntryCount(){this->cpuEntryCount++;}

void Job :: incrementIdleTime(){this->idleTime++;}

void Job :: execute(){this->timeRemaining--; this->runningTime++;}

int Job :: compare(Job *j){
  if(this->priority == j->priority){return 0;}
  else if(this->priority > j->priority){return 1;}
  else {return -1;}
}
