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

  void process_external_events();   //processes the external events from the events list and take action depending on the command given

  int create_job(External_Event * current_event); //COMMAND "J" creates a job and adds it to readyQueue

  int request_IO();                     //COMMAND "W" requests IO ie sends the current running job in CPU into the waitQueue

  int complete_IO(int job_num);         //COMMAND "R" sends the job with the given job number from the waitQueue into the ReadyQueue

  int terminate_job(int job_num);       //COMMAND "T" terminates the job with the given job no from either waitQueue or readyQueue

  void process_internal_events();

  void increment_Idletime();


  // All the printer functions avaliable
  void print_new_job_info(Job *job);
  void print_jobComplete_status();
  void print_job_termination_status(Job *job);


public:

  // only public process avaliable apart from the constructor, rest of them are private inorder to maintain abstraction
  Process();
  void start_simulation(string filename);


};


#endif
