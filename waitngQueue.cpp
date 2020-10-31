class WaitingQueue{
private:
  unordered_map<int,Job*> waitqueue;
public:
  void insert(Job *j){this->waitqueue[j->getJobNo()] = j;}
  Job* get_job(int k){return this->waitqueue[k];}
  void clear_wq(){this->waitqueue.erase(this->waitqueue.begin(),this->waitqueue.end());}
  int get_size(){return this->waitqueue->size();}
};
