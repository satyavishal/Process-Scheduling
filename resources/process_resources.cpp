Process :: Process(){this->n_jobs = 0;}

int Process :: create_job(External_Event *current_event ){

  Job *job = new Job( ++n_jobs, current_event->priority, system_time, current_event->time_estimate);
  ready.add_job(job);
  return 1;
  // cout<<ready.is_empty()<<"  "<<n_jobs<<endl;

}

int Process :: request_IO(){
  if(cpu.current_job()!=NULL){
    waiting.insert(cpu.current_job());
    cpu.clear_cpu();
    cout<<"inserted into the waitQueue"<<endl;
  }else{
    cout<<"entered w ka else\n";
  }
  return 1;
}

int Process :: complete_IO(int job_num){
  auto job = waiting.get_job(job_num);
  if(job != NULL){
    waiting.remove_job(job_num);
    ready.add_job(job);
  }else{
    cout<<"complete IO working"<<endl;
  }
  return 1;
}

int Process :: terminate_job(int job_num){
  Job *job;
  job = ready.remove_job(job_num);
  if(job == NULL){
    job = waiting.get_job(job_num);
    if(job == NULL){cout<<"Job does not exist for termination"<<endl; return 0;}
    waiting.remove_job(job_num);
  }
  // job->print_stats();
  delete(job);
  return 0;
}
