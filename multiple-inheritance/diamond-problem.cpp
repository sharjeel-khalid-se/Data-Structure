#include <iostream>
using namespace std;

class Vehicle{
    public:
        void changeGear(){
            cout << "Changing Gear" ;
        };
};

class LandVehicle : public Vehicle{
};

class WaterVehicle : public Vehicle{
};

class AmphibiousVehicle : public LandVehicle , public WaterVehicle{
};

int main(){
    AmphibiousVehicle a;
    a.changeGear(); //
    return 0;
}