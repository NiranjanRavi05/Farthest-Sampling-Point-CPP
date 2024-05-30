#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <cstdlib> // For rand()

struct Point {
    float x, y;
    Point(float x_val, float y_val) : x(x_val), y(y_val) {}
};

float distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

std::vector<Point> farthestPointSampling(const std::vector<Point>& points, int k) {
    std::vector<Point> sampledPoints;
    int n = points.size();
    if (n == 0 || k <= 0 || k > n) {
        return sampledPoints;
    }

    // Select a random starting point
    sampledPoints.push_back(points[rand() % n]);

    std::vector<float> minDistances(n, std::numeric_limits<float>::max());

    for (int i = 1; i < k; ++i) {
        int farthestIndex = -1;
        float maxDistance = -1;

        // Update minimum distances
        for (int j = 0; j < n; ++j) {
            float dist = distance(points[j], sampledPoints.back());
            if (dist < minDistances[j]) {
                minDistances[j] = dist;
            }

            // Find the point that has the maximum of these minimum distances
            if (minDistances[j] > maxDistance) {
                maxDistance = minDistances[j];
                farthestIndex = j;
            }
        }

        // Add the farthest point found to the sampled points
        if (farthestIndex != -1) {
            sampledPoints.push_back(points[farthestIndex]);
        }
    }

    return sampledPoints;
}

int main() {
    std::vector<Point> points = {
        {0.0, 0.0},
        {1.0, 1.0},
        {2.0, 2.0},
        {3.0, 3.0},
        {4.0, 4.0},
        {5.0, 5.0},
        {6.0, 6.0},
        {7.0, 7.0},
        {8.0, 8.0},
        {9.0, 9.0}
    };

    int k = 3;
    std::vector<Point> sampledPoints = farthestPointSampling(points, k);

    std::cout << "Sampled points:" << std::endl;
    for (const auto& p : sampledPoints) {
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
    }

    return 0;
}
