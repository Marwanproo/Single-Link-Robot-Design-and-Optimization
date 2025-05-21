#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Motor {
private:
    string modelName;
    double torque;
    double speed;
    double mass;
    double diameter;
    double width;
    double cost;
    bool meetsRequirements(double requiredTorque, double requiredSpeed) const {
    return (torque >= requiredTorque) && (speed >= requiredSpeed);
    }
public:
    Motor(const string& name, double t, double s, double m, double d, double w, double c = 0)
        : modelName(name), torque(t), speed(s), mass(m), diameter(d), width(w), cost(c) {}
    void printInfo() const {
        cout << "Model: " << modelName << endl
             << "Torque: " << torque << " Nm" << endl
             << "Speed: " << speed << " RPM" << endl
             << "Mass: " << mass << " kg" << endl
             << "Diameter: " << diameter << " mm" << endl
             << "Width: " << width << " mm" << endl
             << "Cost: $" << cost << endl;
    }
    double calculatePerformance() const {
        return torque * speed;
    }



    vector<Motor> filterCompatibleMotors(const vector<Motor>& motors,
                                       double requiredTorque,
                                       double requiredSpeed) const {
        vector<Motor> result;
        for (const Motor& m : motors) {
            if (m.meetsRequirements(requiredTorque, requiredSpeed)) {
                result.push_back(m);
            }
        }
        return result;
    }


    bool isLightweight(double thresholdMass) const {
        return mass <= thresholdMass;
    }

    void updateCost(double massCostFactor, double diameterCostFactor, double widthCostFactor) {
        cost = (mass * massCostFactor)
             + (diameter * diameterCostFactor)
             + (width * widthCostFactor);
    }


    string getModel() const { return modelName; }
    double getTorque() const { return torque; }
    double getSpeed() const { return speed; }
    double getMass() const { return mass; }
    double getDiameter() const { return diameter; }
    double getWidth() const { return width; }
    double getCost() const { return cost;}
};
