enum VehicleType {
  motorCycle, car
};
 
class Vehicle{
  public:
  VehicleType vehicleType;
  int vehicleId;
  vector<int> allotedSlot;
};
 
class Slot{
  public:
  VehicleType vehicleType;
  int slotId;
  bool empty;
};
 
class Row{
  public:
  vector<Slot> slots;
  int rowId;
};
 
class Level{
  public:
  vector<Row> rows;
  int levelId;
};
 
class ParkingSystem{
 
    public:
    vector<Level> slotMappings;
    // vector<vector<int> > bookedSlots;
    ParkingSystem(){
 
    }
 
    vector<int> getParkingSlot(Vehicle *vehicle){
        int vehicleId = vehicle->vehicleId;
        VehicleType vehicleType = vehicle->vehicleType;
        vector<int> getSlot = getAvailableSlot(vehicleType);
        vehicle->allotedSlot = getSlot;
        return {slotMappings[getSlot[0]].levelId, slotMappings[getSlot[0]].rows[getSlot[1]].rowId, slotMappings[getSlot[0]].rows[getSlot[1]].slots[getSlot[2]].slotId};
    }
 
    void emptySlot(Vehicle *vehicle){
        vector<int> parkingSlot=vehicle->allotedSlot;
        slotMappings[parkingSlot[0]].rows[parkingSlot[1]].slots[parkingSlot[2]].empty = true;
    }
 
    private:
    vector<int> getAvailableSlot(VehicleType vehicleType){
        for(int i=0;i<slotMappings.size(); i++){
            vector<Row> rows=slotMappings[i].rows;
            for(int j=0;i<rows.size();j++){
              vector<Slot> slots = rows[j].slots;
              for(int k=0;k<slots.size();k++){
                  if(slots[k].vehicleType == vehicleType && slots[k].empty){
                      slots[k].empty=false;
                      return {i, j, k};
                  } 
              }
            }
        }
        return {-1, -1, -1};
    }
 
 
 
};
 
int main() {
  cout << "Hello world" << std::endl;
  return 0;
}
