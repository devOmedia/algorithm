#include <iostream>
using namespace std;


int binarySrarch(int *ary, int key, int low, int high){
  ///terminate logic
  if(low > high){
    return -1;
  }
  else {
  ///used the lower value
    int mid = (low + high) / 2;

    if(key == ary[mid]) {  ///if key found return mid.
      return mid;
    } else if(key > ary[mid]){
      return binarySrarch(ary, key, mid + 1, high);
    } else {
      return binarySrarch(ary, key, low, mid - 1);
    }
  }

}

int main(){
 int ary[] = {10, 12, 16, 18, 20, 22, 24, 26, 28, 30};
 int key = 20;
 int low = 0;
 int heigh = sizeof(ary)/sizeof(ary[0]);

 ///print all the elements of the arry
 cout << "Given array: ";
 for(int n : ary){
 cout << n << " ";
 }
 cout << endl << endl;



 int index = binarySrarch(ary, key, low, heigh);

 ///function will return -1 if key not found. otherwise index.
 if(index == -1){
  cout << "The key: "<< key << " is not found is the array" << endl;
 } else{
  cout << "The key is fount at " << index << "th index." << endl;
 }

 return 0;

}
