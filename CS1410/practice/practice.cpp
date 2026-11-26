#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
public:
   void SetName(string employeeName) {
      name = employeeName;
   }

   virtual void PrintInfo() {
      cout << name << endl;
   }

protected:
   string name;
};

class Author : public Employee {
public:
   void SetGenre(string setGenre) {
      genre = setGenre;
   }

   void PrintStatus() {
      cout << "WiFi: " << wifiQuality << endl;
      cout << "CPU: " << cpuUsage << endl;
   };

private:
   string sport;
};

int main() {
   Laptop myLaptop;
// 
   myLaptop.SetComputerStatus("30%", "connected");
   myLaptop.SetWiFiStatus("bad");

   myLaptop.PrintStatus();

   return 0;
}