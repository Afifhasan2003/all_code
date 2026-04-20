#include <iostream>
#include <vector>
#include <map>

using namespace std;

// map<finish_time, pair<start_time, original_index>>
map<int, pair<int, int>> activitySelection(vector<int>& start, vector<int>& finish) {
    int n = start.size();

    map<int, pair<int, int>> activities;
    for (int i = 0; i < n; i++) {
        activities[finish[i]] = {start[i], i};
    }

    map<int, pair<int, int>> selected;  // 
    auto it = activities.begin();
    selected[it->first] = it->second;
    int lastFinish = it->first;     

    // Iterate through the rest
    it++;
    for (; it != activities.end(); it++) {
        int currentFinish = it->first;
        int currentStart  = it->second.first;

        // If this activity starts after or at the finish of the last selected one
        if (currentStart >= lastFinish) {
            selected[currentFinish] = it->second;
            lastFinish = currentFinish;
        }
    }

    return selected;
    //if two activities have the same finish time, then thats a problem
}   


//very similar to using map, but solves the duplicate finish time problem 
int activitySelectionMultimap(vector<int> &start, vector<int> &finish) {
        
    int n = start.size();    
    multimap<int, pair<int,int>> activities;
    
    for (int i = 0; i < n; i++)
    {
        activities.insert({finish[i], {start[i], i}});
    }

    for(auto it:activities){
        cout<<it.second.first<<" - "<<it.first<<endl;
    }
    
    map<int , pair<int,int>> selected;
    auto itt = activities.begin();

    selected[itt->first] = {itt->second.first,itt->second.second};

    int lastSelected = selected.begin()->first;

    int count = 1;
    for (auto it:activities )
    {
        if(it.second.first > lastSelected){
            count++;
            lastSelected = it.first;
            selected[it.first] = {it.second.first, it.second.second};
            
        }
    }

    for(auto it:selected){
        cout<<it.second.first << " - "<< it.first<<endl;
    }
    
        
    return count;
}


int main() {
    vector<int> start  = {1, 3, 0, 5, 8, 6};
    vector<int> finish = {2, 4, 6, 7, 9, 10};


    map<int, pair<int, int>> selected = activitySelection(start, finish);

    // Print selected activities
    cout << "Selected Activities (sorted by finish time):" << endl;
    for (auto& [finish_time, val] : selected) {
        auto [start_time, idx] = val;
        cout << "  A" << idx << " -> Start: " << start_time << ", Finish: " << finish_time << endl;
    }
    cout << endl;

    cout << "Total activities selected: " << selected.size() << " out of " << start.size() << endl;

    return 0;
}