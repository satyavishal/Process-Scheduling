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
  int n_jobs;
  Event_list events;
  CPU cpu;
  ReadyQueue ready;
  WaitingQueue waiting;

  void process_external_events(Event_list &events, int tim);

public:

  Process();
  void start_simulation(string filename);


};


#endif
