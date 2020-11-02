#ifndef CPU_H
#define CPU_H

class CPU{
private:
  Job *running_job;
public:
  CPU();
  void set_job(Job *job);
  void clear_cpu();
  Job *current_job();
  int Execute();
  void complete_currentJob();
};

#endif
