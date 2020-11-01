#ifndef READYQUEUE_H
#define READYQUEUE_H

#include <list>

class ReadyQueue{
private:
  list<Job*> readyQueue[4];
public:
  void add_job(Job *j);

  Job *extractJob();

  int is_empty();

};

#endif
