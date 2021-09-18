using namespace std;

#include <iostream>
#include <vector>

class BinarySearch {
 public:
  static int search(const vector<int>& arr, int key) {
    int start = 0, end = arr.size() - 1;
    bool isAscending = arr[start] < arr[end];
    while (start <= end) {
      // calculate the middle of the current range
      int mid = start + (end - start) / 2;

      if (key == arr[mid]) {
        return mid;
      }

      if (isAscending) {  // ascending order
        if (key < arr[mid]) {
          end = mid - 1;    // the 'key' can be in the first half
        } else {            // key > arr[mid]
          start = mid + 1;  // the 'key' can be in the second half
        }
      } else {  // descending order
        if (key > arr[mid]) {
          end = mid - 1;    // the 'key' can be in the first half
        } else {            // key < arr[mid]
          start = mid + 1;  // the 'key' can be in the second half
        }
      }
    }
    return -1;  // element not found
  }
};

int main(int argc, char* argv[]) {
  cout << BinarySearch::search(vector<int>{4, 6, 10}, 10) << endl;
  cout << BinarySearch::search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 10) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 4) << endl;
}
