#include<bits/stdc++.h>
using namespace std;

class External_Event
{
public:
  int entry_time;
  char command;
  int priority;
  int job_num;
  int time_estimate;

  External_Event(int en_time,char command,int priority,int job,int e_time){
    this->entry_time = en_time;
    this->priority = priority;
    this->command = command;
    this->job_num = job;
    this->time_estimate=e_time;
  }
};

// class External_Events
// {
// private:
//
// }

int main(){
  External_Event a1 (1,'J',3,1,8);
  cout<<a1.command;
  return 0;
}
