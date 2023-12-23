#include <iostream>
#include <queue>
#include <set>

struct State {
    int a, b, steps;

    State(int _a, int _b, int _steps) : a(_a), b(_b), steps(_steps) {}
};

void pourWater(int aCapacity, int bCapacity, int target) {
    std::queue<State> states;
    std::set<std::pair<int, int>> visited;

    states.push(State(0, 0, 0));

    while (!states.empty()) {
        State currentState = states.front();
        states.pop();

        if (currentState.a == target || currentState.b == target) {
            std::cout << currentState.steps << std::endl;
            return;
        }

        // Đổ nước từ cốc a sang cốc b
        if (currentState.a > 0 && currentState.b < bCapacity) {
            int pourAmount = std::min(currentState.a, bCapacity - currentState.b);
            int newA = currentState.a - pourAmount;
            int newB = currentState.b + pourAmount;
            if (visited.find(std::make_pair(newA, newB)) == visited.end()) {
                visited.insert(std::make_pair(newA, newB));
                states.push(State(newA, newB, currentState.steps + 1));
            }
        }

        // Đổ nước từ cốc b sang cốc a
        if (currentState.b > 0 && currentState.a < aCapacity) {
            int pourAmount = std::min(currentState.b, aCapacity - currentState.a);
            int newA = currentState.a + pourAmount;
            int newB = currentState.b - pourAmount;
            if (visited.find(std::make_pair(newA, newB)) == visited.end()) {
                visited.insert(std::make_pair(newA, newB));
                states.push(State(newA, newB, currentState.steps + 1));
            }
        }

        // Đổ nước ra khỏi cốc a
        if (currentState.a > 0) {
            int newA = 0;
            int newB = currentState.b;
            if (visited.find(std::make_pair(newA, newB)) == visited.end()) {
                visited.insert(std::make_pair(newA, newB));
                states.push(State(newA, newB, currentState.steps + 1));
            }
        }

        // Đổ nước ra khỏi cốc b
        if (currentState.b > 0) {
            int newA = currentState.a;
            int newB = 0;
            if (visited.find(std::make_pair(newA, newB)) == visited.end()) {
                visited.insert(std::make_pair(newA, newB));
                states.push(State(newA, newB, currentState.steps + 1));
            }
        }

        // Đổ nước vào cốc a đầy
        if (currentState.a < aCapacity) {
            int newA = aCapacity;
            int newB = currentState.b;
            if (visited.find(std::make_pair(newA, newB)) == visited.end()) {
                visited.insert(std::make_pair(newA, newB));
                states.push(State(newA, newB, currentState.steps + 1));
            }
        }

        // Đổ nước vào cốc b đầy
        if (currentState.b < bCapacity) {
            int newA = currentState.a;
            int newB = bCapacity;
            if (visited.find(std::make_pair(newA, newB)) == visited.end()) {
                visited.insert(std::make_pair(newA, newB));
                states.push(State(newA, newB, currentState.steps + 1));
            }
        }
    }

    std::cout << -1 << std::endl;
}

int main() {
    int a,b,c;
    std::cin >> a >> b >> c;

    pourWater(a,b,c);

    return 0;
}