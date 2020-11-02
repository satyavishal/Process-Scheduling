#ifndef CPU_H
#define CPU_H

class CPU{
private:
  Job *running_job;
public:
  CPU();
  void set_job(Job *j);
  void clear_cpu();
  Job *current_job();
  void Execute();
  void complete_currentJob();
};

#endif
