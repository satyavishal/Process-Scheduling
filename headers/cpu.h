#ifndef CPU_H
#define CPU_H

class CPU{
private:
  Job *current;
public:
  CPU();
  void set_job(Job *j);
  Job *current_job();
  void Execute();
};

#endif
