//
// Created by Robert on 18/09/2019.
//
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // Create a deque containing integers
    deque<int> d = {};

    // Add integer to the beginning and end of the deque
    d.push_front(13);
    d.push_front(25);
    d.push_front(99);
    // Iterate and print values of deque
    for (auto it = d.cbegin(); it != d.cend(); it++) {
        cout << *it << " . ";
    }
}
