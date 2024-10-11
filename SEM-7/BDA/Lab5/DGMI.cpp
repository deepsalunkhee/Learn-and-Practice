
#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

// Struct representing a bucket in DGIM
struct Bucket {
    int timestamp;  // The position in the stream (i.e., when the bucket was created)
    int size;       // The size of the bucket (power of 2)
};

// DGIM class for managing the stream and calculating the number of 1s
class DGIM {
public:
    DGIM(int windowSize) : windowSize(windowSize) {}

    // Function to update the stream with a new bit (either 0 or 1)
    void update(int bit, int currentTime) {
        if (bit == 1) {
            // Add a new bucket with size 1 for the latest 1
            buckets.push_front({currentTime, 1});
            
            // Merge buckets if needed (to maintain at most 2 buckets of the same size)
            mergeBuckets();
        }

        // Remove buckets that are outside the window
        while (!buckets.empty() && buckets.back().timestamp <= currentTime - windowSize) {
            buckets.pop_back();
        }

        // Display the current state of buckets
        displayBuckets();
    }

    // Function to approximate the count of 1s in the last 'k' bits
    int countOnes(int k, int currentTime) {
        int count = 0;
        int boundary = currentTime - k;
        bool firstBucket = true;

        for (auto& bucket : buckets) {
            if (bucket.timestamp <= boundary) {
                // If this bucket starts before the boundary, estimate its contribution
                if (firstBucket) {
                    count += bucket.size / 2;  // Approximate contribution
                    firstBucket = false;
                }
                break;
            } else {
                count += bucket.size;  // Exact contribution from within the window
            }
        }

        return count;
    }

private:
    deque<Bucket> buckets;  // Store the list of buckets
    int windowSize;         // The window size for DGIM

    // Function to merge buckets if there are more than 2 of the same size
    void mergeBuckets() {
        for (auto it = buckets.begin(); it != buckets.end();) {
            // Ensure that at most 2 buckets of the same size exist
            auto nextBucket = next(it);
            auto thirdBucket = next(nextBucket);

            if (thirdBucket != buckets.end() && it->size == nextBucket->size && nextBucket->size == thirdBucket->size) {
                // Merge the last two buckets of the same size
                thirdBucket->size *= 2;
                thirdBucket->timestamp = nextBucket->timestamp;  // Keep the most recent timestamp
                buckets.erase(nextBucket);  // Remove the earlier bucket after merging
            } else {
                ++it;
            }
        }
    }

    // Function to display the current state of buckets
    void displayBuckets() {
        cout << "Buckets: [";
        for (auto& bucket : buckets) {
            cout << "{Timestamp: " << bucket.timestamp << ", Size: " << bucket.size << "}, ";
        }
        cout << "]" << endl;
    }
};

int main() {
    int windowSize, k, n, bit;
    
    // Input window size and number of bits to process
    cout << "Enter window size for DGIM: ";
    cin >> windowSize;

    DGIM dgim(windowSize);

    // Input the number of bits in the stream
    cout << "Enter the number of bits in the stream: ";
    cin >> n;

    // Input the stream bits and update DGIM
    cout << "Enter the binary stream (space separated): ";
    for (int i = 0; i < n; i++) {
        cin >> bit;
        dgim.update(bit, i);
    }

    // Input the number of bits (k) for which we want to count set bits
    cout << "Enter the number of bits to calculate the number of set bits: ";
    cin >> k;

    // Get the approximate count of 1s in the last 'k' bits
    int count = dgim.countOnes(k, n);
    cout << "Approximate number of set bits in the last " << k << " bits: " << count << endl;

    return 0;
}

