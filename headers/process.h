#ifndef PROCESS_H
#define PROCESS_H

#include <bits/stdc++.h>
#include "../services/event.cpp"
#include "../services/event_list.cpp"
#include "../services/job.cpp"
#include "../services/cpu.cpp"
#include "../services/readyQueue.cpp"
#include "../services/waitingQueue.cpp"

class Process{
private:
  int system_time;
  int n_jobs;
  Event_list events;
  CPU cpu;
  ReadyQueue ready;
  WaitingQueue waiting;

  void process_external_events();
  int create_job(External_Event * current_event); // creates a job and adds it to readyQueue
  int request_IO();
  int complete_IO(int job_num);
  int terminate_job(int job_num);
  void process_internal_events();
  void increment_Idletime();

  void print_new_job_info(Job *job);
  void print_jobComplete_status();
  void print_job_termination_status(Job *job);


public:

  Process();
  void start_simulation(string filename);


};


#endif
