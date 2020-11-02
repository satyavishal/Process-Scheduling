#ifndef READYQUEUE_H
#define READYQUEUE_H

#include <list>

class ReadyQueue{
private:
  list<Job*> readyQueue[4];
public:
  void add_job(Job *j);

  Job *extractJob();

  Job *find_Job();

  int is_empty();

  Job *remove_job(int job_num);

  void incrementIdleTime();

};

#endif
