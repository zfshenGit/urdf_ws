#include <iostream>
#include <vector>
using namespace std;

#define PI (3.1415926535897932346f)

int main(int argc, char **argv)
{
    double start_position[6];
    start_position[0] = 19.7042;
    start_position[1] = -102.796;
    start_position[2] = -119.118;
    start_position[3] = -93.5222;
    start_position[4] = -107.163;
    start_position[5] = -59.4297;

    std::vector<double> joint_value(start_position,start_position+6);
    for(int i=0;i<6;i++){
        joint_value[i] = joint_value[i]/180.*PI;
        cout << "joint value " << i << " :" << joint_value[i] << endl;
    }

    return 0;
}
