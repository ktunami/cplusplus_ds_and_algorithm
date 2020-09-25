#include <iostream>
#include "data_structure/linear_structure/LinkedList.h"
#include <unordered_set>

int main() {
  std::unordered_set<int> st;
  int arr[] = {1,2,4,5,7,11,15};
  int k = 15;
  for (int i{0}; i<7; ++i){
    if (st.find(k - arr[i])!=st.end()) {
      std::cout << arr[i] <<" and " << k - arr[i] << std::endl;
      break;
    } else {
      st.insert(arr[i]);
    }
  }
  return 0;
}
