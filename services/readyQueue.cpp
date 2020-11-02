#include <list>

class ReadyQueue{
private:
  list<Job*> readyQueue[4];
public:
  void add_job(Job *job){
    int priority = job->getPriority() - 1;
    readyQueue[priority].push_back(job);
  }

  Job *extractJob(){
    Job *j;
    for(int i = 0;  i<4; i++){
      if(!readyQueue[i].empty()){
        j = readyQueue[i].front();
        readyQueue[i].pop_front();
        break;
      }
    }
    return j;
  }

  int is_empty(){
    for(int i=0;i<4;i++){
      if(!readyQueue[i].empty()){
        return 0;
      }
    }
    return 1;
  }

};
