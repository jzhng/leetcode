#include <vector>
using namespace std;

class ParkingSystem {
    vector<int> spaces;
public:
    ParkingSystem(int big, int medium, int small) : spaces({big, medium, small}) {

    }
    
    bool addCar(int carType) {
        if (spaces[carType - 1] > 0) {
            --spaces[carType - 1];
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */