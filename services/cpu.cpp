#include "../headers/cpu.h"

using namespace std;

CPU :: CPU(){this->current = NULL;}

void CPU :: set_job(Job *j){this->current =j;}

Job * CPU ::current_job(){return this->current;}

void CPU :: Execute(){this->current->execute();}
