#include "cpu.h"

class CPU{
private:
  Job *current;
public:
  CPU(){
    this->current = NULL;
  }
  void set_job(Job *j){this->current =j;}
  Job *current_job(){return this->current;}
  void Execute(){this->current->execute();}
};
