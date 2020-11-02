#include <iostream>
#include "services/process.cpp"
using namespace std;

int main(){
  Process process_manager;
  process_manager.start_simulation("tests/input.txt");

  // External_Event *a1 = new External_Event(1,'J',3,1,8);
  // Event_list b;
  // if(!b.load_file("tests/input.txt")){return 0;}
  // // b.insert_event(a1);
  // if(!b.find_event(1)){
  //   cout<<"null";
  // }else{
  //     cout<<"not null"<<endl;
  // }
  // cout<<b.events_completed();

  // cout<< (b.find_event2(10))->command;


  return 0;
}
