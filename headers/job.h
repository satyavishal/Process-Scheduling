#ifndef JOB_H
#define J0B_H

class Job{

private:
  int jobNo, priority, entryTime, timeRemaining;
  int runningTime;
  int idleTime;
  int cpuEntryCount;
  int timeEstimate;
  int cpuEntryTime;

public:
  Job(int j,int p, int e, int t); //constructor

  void setCpuEntryTime(int c);
  //Time Estimate
  int getTimeEstimate();
  void setTimeEstimate(int t);
  //Job number
  int getJobNo();
  void setJobNo(int j);
  //priority
  int getPriority();
  void setPriority(int p);

  int getEntryTime();

  int getTimeRemaining();

  int getRunningTime();

  int getIdleTime();

  int getCpuEntryCount();

  void incrementCpuEntryCount();

  void incrementIdleTime();

  void execute();

  int compare(Job *j);

};

#endif
