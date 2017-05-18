#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){

int start{0};
int duration{0};
int hourDuration;
int end{0};
int temp{0};
int minStart{0};
int hourStart{0};
int minDuration{0};

 cout << "Enter in a start time: ";
 cin >> start;
 cout << "  Enter in a duration: ";
 cin >> duration;

 hourDuration = duration/100;
 minDuration = duration%100;
 minStart = start%100;
 hourStart = start/100;

 temp = minStart + minDuration;

 if(temp/60 == 1){
   hourDuration += 1;
   end = (hourStart + hourDuration)* 100 + temp%60;
 }
 if(temp/60 != 1){
   end = (hourStart + hourDuration) * 100 + temp%60;
 }
 if(end >= 2400){
   end = end - 2400;
 }

 if((end < 100) && (end > 9)){
     cout << "          End time is: 00" << end << endl;
   }

 else if((end < 100) && (end < 10)){
     cout << "          End time is: 000" << end << endl;
   }
 else if((end <1000)){
   cout << "          End time is: 0" << end << endl;
 }

 else{
   cout << "          End time is: " << end << endl;
 }


}
