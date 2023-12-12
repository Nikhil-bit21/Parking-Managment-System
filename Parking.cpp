#include<iostream>
#include<math.h>
#include<set>
#include<unordered_map>
using namespace std;

class ParkingSystem{
private:
    set<int> availableSlots;
    unordered_map<int,pair<string,string> > System;

public:

    ParkingSystem(){
        int totalslots = 10;
        for(int i = 1; i <= totalslots ; i++){
            availableSlots.insert(i);
        }
    }

    string Deposit(const string& vehicleNumber , const string& vehicleType){
        if(availableSlots.empty()){
            return "Sorry Slots are Full For Now ! ";
        }
        int slotNo = *availableSlots.begin();

        availableSlots.erase(slotNo);
        
        int userId = slotNo;
        System[slotNo] = make_pair(vehicleNumber,vehicleType);

        return vehicleType + " with number " + vehicleNumber + " is Successfully Deposited! Thanks You for Coming. Your UserId is " + to_string(userId);
    }

    string Retrive(int userId){
        auto it = System.find(userId);
        
        if(it == System.end()){
            return "Invalid UserId ! No Vehicle with id : " + to_string(userId) + " is deposited here.";
        }

        int slot = it->first;
        System.erase(it);
        availableSlots.insert(slot);

        string number = it->second.first;
        string type = it->second.second;

        return type + " with number " + number + " is Successfully retrieved from the Parking. " + to_string(slot) + " is now available";

    }

};

int main(){

    ParkingSystem rsnr;

    cout << rsnr.Deposit("1234" , "Car")<<endl;
    cout << rsnr.Deposit("1221" , "Bike")<<endl;

    cout << rsnr.Retrive(3)<<endl;
    cout << rsnr.Retrive(2)<<endl;

    cout<< rsnr.Deposit("1111","Truck")<<endl;
    
    return 0;
}