#ifndef EVENT_H
#define EVENT_H

class External_Event
{
public:
  int entry_time;
  char command;
  int priority;
  int job_num;
  int time_estimate;

  External_Event(int entry_time,char command,int priority,int job,int estimated_time);

};

#endif
