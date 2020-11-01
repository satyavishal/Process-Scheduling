class CPU{
private:
  Job *current;
  CPU(){
    this->current = NULL;
  }
public:
  void set_job(Job *j){this->current =j;}
  Job *current_job(){return this->current;}
  void Execute(){this->current->execute();}
};
