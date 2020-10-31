class ReadyQueue{
private:
  list<Job*> readyQueue[4];
public:
  void add_job(Job *j){
    int c = j->getPriority() - 1;
    readyQueue[c].push_back(j);
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
