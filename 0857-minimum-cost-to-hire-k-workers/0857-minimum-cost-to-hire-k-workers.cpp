#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

class Solution {
public:
    /**
     * Calculates the minimum cost to hire k workers.
     * 
     * The problem requires that for any group of k workers, the wage paid to each worker 
     * must be proportional to their quality, and each worker must receive at least their 
     * minimum wage expectation.
     * 
     * Strategy:
     * 1. Calculate the wage-to-quality ratio for every worker.
     * 2. Sort workers by this ratio in ascending order.
     * 3. Iterate through the sorted workers, treating each as the 'captain' who sets the 
     *    minimum ratio for the group.
     * 4. Use a max-priority queue to keep track of the k workers with the smallest 
     *    qualities encountered so far to minimize the total cost.
     */
    double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
        int n = quality.size();
        struct Worker {
            double ratio;
            int quality;
        };

        std::vector<Worker> workers(n);
        for (int i = 0; i < n; ++i) {
            workers[i] = {(double)wage[i] / quality[i], quality[i]};
        }

        // Sort by ratio to ensure that when we pick a worker as the 'captain',
        // all previously considered workers satisfy the ratio requirement.
        std::sort(workers.begin(), workers.end(), [](const Worker& a, const Worker& b) {
            return a.ratio < b.ratio;
        });

        std::priority_queue<int> pq;
        double sum_quality = 0;
        double min_cost = 1e18; // Initialize with a large value

        for (const auto& worker : workers) {
            sum_quality += worker.quality;
            pq.push(worker.quality);

            // If we have more than k workers, remove the one with the highest quality
            // to keep the sum of qualities as small as possible.
            if (pq.size() > (size_t)k) {
                sum_quality -= pq.top();
                pq.pop();
            }

            // Once we have exactly k workers, calculate the potential cost.
            if (pq.size() == (size_t)k) {
                min_cost = std::min(min_cost, sum_quality * worker.ratio);
            }
        }

        return min_cost;
    }
};