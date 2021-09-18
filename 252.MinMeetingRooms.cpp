using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Meeting {
 public:
  int start = 0;
  int end = 0;

  Meeting(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MinimumMeetingRooms {
 public:
  struct endCompare {
    bool operator()(const vector<int> &x, const vector<int> &y) { return x[1] > y[1]; }
  };

  static int findMinimumMeetingRooms(vector<Meeting> &meetings) {
    if (meetings.empty()) {
      return 0;
    }

    // sort the meetings by start time
    sort(meetings.begin(), meetings.end(),
         [](const vector<int>  &x, const vector<int> &y) { return x[0] < y[0]]; });

    int minRooms = 0;
    priority_queue<vector<int>, vector<vector<int> >, endCompare> minHeap;
    for (auto meeting : meetings) {
      // remove all meetings that have ended
      while (!minHeap.empty() && meeting[0] >= minHeap.top()[1]) {
        minHeap.pop();
      }
      // add the current meeting into the minHeap
      minHeap.push(meeting);
      // all active meeting are in the minHeap, so we need rooms for all of them.
      minRooms = max(minRooms, (int)minHeap.size());
    }

    return minRooms;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int> > input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  int result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 5}, {7, 9}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{6, 7}, {2, 4}, {8, 12}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 3}, {3, 6}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;
}
