#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct noiseLevel{
       short vehicleNo;
       short noise[7];
       };

noiseLevel sounds;

int main()
{
    int noiseTable[9][8];
    int x = 0;
    int y = 0;
    int avg = 0;
    int lowest = 0;
    int lowestCar = 0;
    int lowestSpeed = 0;
    
  fstream soundFile ("noise.dat", ios::in);
	
    //Let's create the labels first
    noiseTable[0][0] = 0;
    for(x=1;x<8;x++){
         noiseTable[x][0] = 10 * x;               
    }
    noiseTable[8][0] = 0;
       
    //Take in new read/data for the iteration
    for (y=1; y<7; y++){
	soundFile.read (reinterpret_cast<char *> (&sounds), sizeof (sounds));
	noiseTable[0][y] = sounds.vehicleNo;
	for (x=1;x<8;x++){
		noiseTable[x][y] = sounds.noise[x-1];
		}
    }
	
	//Calculate Car Average
	for (y=1;y<8;y++){
        avg = 0;
        for (x=1;x<8;x++){avg += noiseTable[x][y];}
        noiseTable[8][y] = (avg /= 7);      
    }
	
	//Calculate Speed Average
	for (x=1;x<9;x++){
        avg = 0;
        for (y=1;y<7;y++){avg += noiseTable[x][y];}
        noiseTable[x][7] = (avg /= 6);    
    }
	
	//Find Lowest Car Average
	lowest = noiseTable[0][1];
	for (y=1;y<8;y++){
        for (x=1;x<8;x++){if (noiseTable[x][y] < lowest){lowest = noiseTable[x][y]; lowestCar = noiseTable[0][y];}}    
    }
	cout << "Lowest Car Average is: " << lowestCar << endl;
	
	//Find Lowest Speed Average
	lowest = noiseTable[2][2];
	for (x=1;x<9;x++){
        for (y=1;y<7;y++){if (noiseTable[x][y] < lowest){lowest = noiseTable[x][y]; lowestSpeed = noiseTable[x][0];}}    
    }
	cout << "Lowest Speed Average is: " << lowestSpeed << endl;
	
	noiseTable[8][7] = 0;
	
    //Read Data in Array
    for (y=0; y<8;y++){
        for (x=0; x<9; x++){
            cout << setw(8);
            if (x == 0 && y == 0){cout << "Car ";}
            else if (x == 8 && y == 0){cout << "Car Avg ";}
            else if (x == 0 && y == 7){cout << "SpdAvg ";}
            else{cout << noiseTable[x][y] << " ";}
            }
        cout << endl; 
    }

	system("PAUSE");
		  
    
    return 0;
}
