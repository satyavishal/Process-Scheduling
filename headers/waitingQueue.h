#ifndef WAITQUEUE_H
#define WAITQUEUE_H

#include <unordered_map>

class WaitingQueue{
private:
  unordered_map<int,Job*> waitqueue;
public:
  void insert(Job *job);
  Job* get_job(int job_num);
  void clear_wq();
  int get_size();
  void remove_job(int job_num);
};


#endif
