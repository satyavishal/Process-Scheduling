class CPU{
private:
  Job *current = nullptr;
public:
  void set_job(Job *j){this->current =j;}
  Job *current_job(){return this->current;}
  void Execute(){this->current->execute();}
};
