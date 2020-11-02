void Process :: print_new_job_info(Job *job){
  cout<<"\t\t[NEW JOB INFORMATION]"<<endl;
  cout<<"\t\t   Job Number: "<<job->getJobNo()<<endl;
  cout<<"\t\t   Priority Number: "<<job->getPriority()<<endl;
  cout<<"\t\t   Estimated Time: "<<job->getTimeEstimate()<<endl<<endl;
}

void Process :: print_jobComplete_status(){
  Job *job = cpu.current_job();
  cout<<"JOB: "<<job->getJobNo()<<" completed at time "<<system_time<<endl;
  cout<<"\t\t[JOB "<<job->getJobNo()<<" STATUS]"<<endl;
  cout<<"\t\t   Number of times entered CPU: "<<job->getCpuEntryCount()<<endl;
  cout<<"\t\t   Total Idle time: "<<job->getIdleTime()<<endl;
  cout<<"\t\t   Total Time Spent in the CPU "<<job->getRunningTime()<<endl;
  cout<<"\t\t   Total Time Spent in the System: "<<job->getIdleTime()+job->getRunningTime()<<endl<<endl;
}

void Process :: print_job_termination_status(Job *job){
  cout<<"JOB: "<<job->getJobNo()<<" Terminated at time "<<system_time<<endl;
  cout<<"\t\t[JOB "<<job->getJobNo()<<" STATUS]"<<endl;
  cout<<"\t\t   Number of times entered CPU: "<<job->getCpuEntryCount()<<endl;
  cout<<"\t\t   Total Idle time: "<<job->getIdleTime()<<endl;
  cout<<"\t\t   Total Time Spent in the CPU "<<job->getRunningTime()<<endl;
  cout<<"\t\t   Total Time Spent in the System: "<<job->getIdleTime()+job->getRunningTime()<<endl<<endl;
}
