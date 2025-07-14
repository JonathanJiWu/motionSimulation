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

    friend std::ostream& operator<<(std::ostream& os, const MotionEvent& ev) //what does this mean? => an object that's easy to cout? => how can we use it? 
    {
        return os << "t=" << std::fixed << std::setprecision(2) << ev.time
                  << "  x=" << ev.position << "  v=" << ev.velocity;
    }
};

// Generate a discrete list of events (simulated motion)
std::vector<MotionEvent> Simulate1DMotion
(
    double initialPosition,
    double initialVelocity,
    double acceleration,
    double timeStep,
    double totalTime
){
    std::vector<MotionEvent> result;
    double position = initialPosition;
    double velocity = initialVelocity;
    double currentTime = 0.0;

    while (currentTime < totalTime) 
    {
        velocity += acceleration * timeStep;
        position += velocity * timeStep;
        currentTime += timeStep;
        result.push_back({currentTime, position, velocity});
    }

    return result;
}

// 1. Return all events where velocity > threshold
std::vector<MotionEvent> FilterByVelocity(const std::vector<MotionEvent>& events, double threshold)
{


}

// 2. Return a new vector sorted by descending |velocity|
std::vector<MotionEvent> SortByAbsoluteVelocityDesc(const std::vector<MotionEvent>& events)
{

}

// 3. Compute total change in position from the first to last event
double ComputeTotalDisplacement(const std::vector<MotionEvent>& events)
{

}


// 4. Use ranges to find maximum speed (abs velocity)
double MaxSpeed(const std::vector<MotionEvent>& events)
{

}


// 5. Return vector<string> formatted as CSV: "time,position,velocity"
std::vector<std::string> FormatAsCSV(const std::vector<MotionEvent>& events)
{

}



int main()
{
    Simulate1DMotion(0, 0, 4, 0.1, 10);
}