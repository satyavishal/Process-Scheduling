#include <iostream>
#include "services/process.cpp"
using namespace std;

int main(){
  // creating an object of Process which acts as the process process_manager and starting the simulation
  //to test different test cases, change the file name

  Process process_manager;
  process_manager.start_simulation("tests/input.txt");

  return 0;
}
