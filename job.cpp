class Job{
private:
  int jobNo, priority, entryTime, timeRemaining;
  int runningTime = 0;
  int idleTime = 0;
  int cpuEntryCount = 0;
  int timeEstimate = 0;
  int cpuEntryTime = 0;
public:
  Job(int j,int p, int e, int t){
    this->jobNo =j;
    this->priority =p;
    this->entryTime = e;
    this->timeRemaining = t;
  }
  void setCpuEntryTime(int c){this->cpuEntryTime  = c;}
  //Time Estimate
  int getTimeEstimate(){return this->timeEstimate;}
  void setTimeEstimate(int t){this->timeEstimate = t;}
  //Job number
  int getJobNo(){return this->jobNo;}
  void setJobNo(int j){this->jobNo = j;}
  //priority
  int getPriority(){return this->priority;}
  void setPriority(int p){this->priority = p;}

  int getEntryTime(){return this->entryTime;} // system entry time

  int getTimeRemaining(){return this->timeRemaining;}

  int getRunningTime(){return  this->runningTime;}

  int getIdleTime(){return   this->idleTime;}

  int getCpuEntryCount(){return  this->cpuEntryCount;}

  void incrementCpuEntryCount(){this->cpuEntryCount++;}

  void incrementIdleTime(){this->idleTime++;}

  void execute(){this->timeRemaining--; this->runningTime++;}

  int compare(Job *j){
    if(this->priority == j->priority){return 0;}
    else if(this->priority > j->priority){return 1;}
    else {return -1;}
  }

};
