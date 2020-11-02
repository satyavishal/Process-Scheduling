void Process :: process_external_events(){

  auto current_event = events.find_event(system_time);

  if(current_event!= NULL){
    cout<< "Processing a '"<<current_event->command<<"' at time "<<system_time<<":"<<endl;
    switch(current_event->command){
      case 'J':
      {
        create_job(current_event);
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
