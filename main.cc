#include <iostream>

#define hourPerDay 8
#define dayPerWeek 5

double calcHourlyRate(double salary){
  return salary / (hourPerDay*dayPerWeek*4);
}
bool checkOvertime(int hour){
  if(hour >= (hourPerDay*dayPerWeek*4)){
    return true;
  }
  return false;
}
double basePay(int totalHourWork, double hourlyRate){
  return totalHourWork * hourlyRate;
}
double overtimePay(int totalHourWork, double hourlyRate) {
    return (totalHourWork - (hourPerDay*dayPerWeek*4)) * (hourlyRate * 2) + basePay(totalHourWork, hourlyRate) - (totalHourWork - (hourPerDay*dayPerWeek*4)) * (hourlyRate) ;
}
template<class T>
void read(std::string description , T &input){
  std::cout<< description;
  std::cin>>input;
}
template<class T>
void print(std::string description, T &output){
  std::cout<<description<< output<< "\n";
}

int main(){
  double baseSalary{0.0}, totalHourWork{0.0}, salary{0.0};
  read("Input Base Salary: ",baseSalary);
  read("Input Total Hour Work: ",totalHourWork);
  double hourlyRate = calcHourlyRate(baseSalary);
  if(!checkOvertime(totalHourWork)){
    salary = basePay(totalHourWork, hourlyRate);
  }  
  salary = overtimePay(totalHourWork, hourlyRate);
  print("Hour Rate: ", hourlyRate);
  print("Total Salary: ", salary);
}
