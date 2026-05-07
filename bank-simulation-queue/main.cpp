#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// ══════════════════════════════════
// CUSTOMER
// ══════════════════════════════════
struct Customer {
    int id;
    int arrivalTime;
    int duration;
    int queueIndex;    // kis queue mein hai (0-3)
    int departureTime;

    Customer(int i, int arr, int dur)
        : id(i), arrivalTime(arr),
          duration(dur), queueIndex(-1), departureTime(0) {}
};

// ══════════════════════════════════
// EVENT
// ══════════════════════════════════
struct Event {
    int       time;       // kab hoga
    Customer* customer;
    bool      isArrival;  // true=aaya, false=gaya

    Event(int t, Customer* c, bool arr)
        : time(t), customer(c), isArrival(arr) {}

    // Priority Queue ke liye: chota time = zyada priority
    bool operator>(const Event& other) const {
        return time > other.time;
    }
};

// ══════════════════════════════════
// BANK SIMULATION
// ══════════════════════════════════
int main() {
    // 4 teller queues
    vector<queue<Customer*>> tellerQueues(4);

    // Priority Queue (min-heap: chota time pehle)
    priority_queue<Event,
                   vector<Event>,
                   greater<Event>> pq;

    int totalWaitTime = 0;
    int customerCount = 0;
    int customerNo    = 0;

    // ── File kholo ──
    ifstream file("customers.txt");
    if (!file) {
        cout << "File nahi mili! Test data use kar rahe hain.\n";
    }

    // ── Test Data (file ki jagah) ──
    // Format: arrivalTime, duration
    vector<pair<int,int>> testData = {
        {2, 4},   // C1: minute 2 pe aaya, 4 min transaction
        {4, 6},   // C2: minute 4 pe aaya, 6 min transaction
        {12, 10}, // C3: minute 12 pe aaya, 10 min transaction
        {15, 3},  // C4
        {18, 5},  // C5
    };

    // Sab customers ke arrival events Priority Queue mein daalo
    for (auto& [arrTime, dur] : testData) {
        customerNo++;
        Customer* c = new Customer(customerNo, arrTime, dur);
        pq.push(Event(arrTime, c, true)); // arrival event
    }

    // ══ MAIN SIMULATION LOOP ══
    while (!pq.empty()) {
        Event e = pq.top();
        pq.pop();

        Customer* c = e.customer;

        // ── ARRIVAL EVENT ──
        if (e.isArrival) {
            // Sabse choti queue dhundo
            int minIdx = 0;
            for (int i = 1; i < 4; i++) {
                if (tellerQueues[i].size() ;
                    tellerQueues[minIdx].size())
                    minIdx = i;
            }

            c->queueIndex = minIdx;
            tellerQueues[minIdx].push(c);

            cout << "t=" << e.time
                 << ": C" << c->id
                 << " aaya → Queue " << minIdx+1 << "\n";

            // Agar akela hai → seedha teller ke paas
            if (tellerQueues[minIdx].size() == 1) {
                c->departureTime = e.time + c->duration;
                // Departure event banao
                pq.push(Event(c->departureTime, c, false));
            }
        }

        // ── DEPARTURE EVENT ──
        else {
            int qIdx    = c->queueIndex;
            int waitTime = c->departureTime - c->arrivalTime;
            totalWaitTime += waitTime;
            customerCount++;

            cout << "t=" << e.time
                 << ": C" << c->id
                 << " gaya (wait=" << waitTime << " min)\n";

            tellerQueues[qIdx].pop(); // nikaalo

            // Queue mein aur hain? → unka event banao
            if (!tellerQueues[qIdx].empty()) {
                Customer* next = tellerQueues[qIdx].front();
                next->departureTime = e.time + next->duration;
                pq.push(Event(next->departureTime, next, false));
            }

            delete c; // memory free
        }
    }

    // ── AVERAGE WAIT TIME ──
    if (customerCount > 0) {
        double avg = (double)totalWaitTime / customerCount;
        cout << "\n=== SIMULATION RESULTS ===\n";
        cout << "Total customers: " << customerCount << "\n";
        cout << "Total wait time: " << totalWaitTime << " min\n";
        cout << "Average wait:    " << avg << " min\n";
    }

    return 0;
}