#ifndef WAITQUEUE_H
#define WAITQUEUE_H

#include <unordered_map>

class WaitingQueue{
private:
  unordered_map<int,Job*> waitqueue;
public:
  void insert(Job *j);
  Job* get_job(int k);
  void clear_wq();
  int get_size();
};


#endif
