#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// map<negative_ratio, pair<weight, original_index>>
// Negated ratio so map's ascending order becomes descending (highest ratio first)
// Returns map<original_index, weight_taken>
map<int, double> fractionalKnapsackMap(vector<int>& weight, vector<int>& price, int capacity) {
    int n = weight.size();

    // Insert all items into the map
    // Key = -ratio, Value = {weight, original_index}
    map<double, pair<int, int>> items;
    for (int i = 0; i < n; i++) {
        double ratio = (double)price[i] / weight[i];
        items[-ratio] = {weight[i], i};
    }

    // Greedy: pick highest ratio first
    map<int, double> selected; //{original_index, weight_taken}
    int remaining = capacity;

    for (auto& [negRatio, val] : items) {
        if (remaining <= 0) break;

        auto [w, idx] = val;

        if (w <= remaining) {
            selected[idx] = w;         // take whole item
            remaining -= w;
        } else {
            selected[idx] = remaining; // take fraction
            remaining = 0;
        }
    }

    return selected;
}

// priority_queue gives max heap by default (highest ratio first)
// Returns vector of pairs {original_index, weight_taken}
vector<pair<int, double>> fractionalKnapsackPQ(vector<int>& weight, vector<int>& price, int capacity) {
    int n = weight.size();

    // Max heap: stores {ratio, weight, original_index}  , so highest ratio is on top
    priority_queue<pair<double, pair<int, int>>> pq;
    
    for (int i = 0; i < n; i++) {
        double ratio = (double)price[i] / weight[i];
        pq.push({ratio, {weight[i], i}});
    }

    // Greedy: pick highest ratio first
    vector<pair<int, double>> selected; // {original_index, weight_taken}
    int remaining = capacity;

    while (!pq.empty() && remaining > 0) {
        auto top = pq.top();
        pq.pop();

        double ratio = top.first;
        int w = top.second.first;
        int idx = top.second.second;

        if (w <= remaining) {
            selected.push_back({idx, (double)w});  // take whole item
            remaining -= w;
        } else {
            selected.push_back({idx, (double)remaining}); // take fraction
            remaining = 0;
        }
    }

    return selected;
}

int main() {
    vector<int> weight = {10, 20, 30, 40, 50};
    vector<int> price  = {60, 100, 120, 140, 150};
    int capacity       = 50;

   

    // Using map
    map<int, double> selected = fractionalKnapsackMap(weight, price, capacity);

    cout << "Selected Items :" << endl;
    double totalValue = 0.0;

    for (auto& [idx, weightTaken] : selected) {
        double valueGained = (weightTaken / weight[idx]) * price[idx];
        totalValue += valueGained;

        cout << "  Item" << idx
             << " -> Weight Taken: " << weightTaken << "/" << weight[idx]
             << ", Value Gained: " << valueGained << endl;
    }
    cout << "Total Value (using map): " << totalValue << endl;



    // Using priority queue
    vector<pair<int, double>> selectedPQ = fractionalKnapsackPQ(weight, price, capacity);
    cout << "\nSelected Items (using PQ):" << endl;
    totalValue = 0.0;
    for (auto& [idx, weightTaken] : selectedPQ) {
        double valueGained = (weightTaken / weight[idx]) * price[idx];
        totalValue += valueGained;

        cout << "  Item" << idx
             << " -> Weight Taken: " << weightTaken << "/" << weight[idx]
             << ", Value Gained: " << valueGained << endl;
    }
    cout << "Total Value (using PQ): " << totalValue << endl;


    return 0;
}