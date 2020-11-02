#include "../headers/waitingQueue.h"
using namespace std;

void WaitingQueue :: insert(Job *job){this->waitqueue[job->getJobNo()] = job;}

Job* WaitingQueue :: get_job(int job_num){return this->waitqueue[job_num];}

void WaitingQueue :: clear_wq(){this->waitqueue.erase(this->waitqueue.begin(),this->waitqueue.end());}

int WaitingQueue :: get_size(){return this->waitqueue.bucket_count();}

void WaitingQueue :: remove_job(int job_num){this->waitqueue.erase(job_num);}
