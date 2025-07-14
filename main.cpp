#include <vector>
#include <utility>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>
#include <iomanip>

struct MotionEvent {
    double time;
    double position;
    double velocity;

    friend std::ostream& operator<<(std::ostream& os, const MotionEvent& ev) {
        return os << "t=" << std::fixed << std::setprecision(2) << ev.time
                  << "  x=" << ev.position << "  v=" << ev.velocity;
    }
};

// Generate a discrete list of events (simulated motion)
std::vector<MotionEvent> Simulate1DMotion(
    double initialPosition,
    double initialVelocity,
    double acceleration,
    double timeStep,
    double totalTime)
{
    std::vector<MotionEvent> result;
    double position = initialPosition;
    double velocity = initialVelocity;
    double currentTime = 0.0;

    while (currentTime < totalTime) {
        velocity += acceleration * timeStep;
        position += velocity * timeStep;
        currentTime += timeStep;
        result.push_back({currentTime, position, velocity});
    }

    return result;
}
