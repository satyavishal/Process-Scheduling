void Process :: process_external_events(){

  auto current_event = events.find_event(system_time);
  // cout<<"current event"<<current_event<<endl;
  if(current_event!= NULL){
    cout<< "Processing a '"<<current_event->command<<"' at time "<<system_time<<":"<<endl;

    switch(current_event->command){
      case 'J':
      {
        create_job(current_event);  // creates a job and adds it into the ready queue
        break;
      }
      case 'W':
      {
        request_IO();
        break;
      }
      case 'R':
      {
        complete_IO(current_event->job_num);
        break;
      }
      case 'C':
      {
        print_jobComplete_status();
        cpu.complete_currentJob();
        break;
      }
      case 'T':
      {
        terminate_job(current_event->job_num);
        break;
      }
      default: cout<<"command Error in Process_external_events"<<endl;
    }
  }
}


void Process :: process_internal_events(){
//assigning cpu a job if cpu has no running jobs
  Job *job;
  if(cpu.current_job() == NULL){

    if(!ready.is_empty()){
      job = ready.extractJob();  //extractiong a job from readyQueue
      job->setCpuEntryTime(system_time);
      job->incrementCpuEntryCount();

      cpu.set_job(job);          // placing the extracted job in cpu
      cout << "Job "<<job->getJobNo()<<" Entered CPU at time "<<system_time<<endl<<endl;
    }

    // assigning a higher priority job if it exists

  }else{

    if(!ready.is_empty()){
      job = ready.find_Job();

      if(cpu.current_job()->compare(job) == 1){

        job = ready.extractJob();
        ready.add_job(cpu.current_job());

        job->setCpuEntryTime(system_time);
        job->incrementCpuEntryCount();

        cpu.set_job(job);          // placing the extracted job in cpu
        cout << "Job "<<job->getJobNo()<<" Entered CPU at time "<<system_time<<endl<<endl;

      }
    }
  }

  increment_Idletime();

}
