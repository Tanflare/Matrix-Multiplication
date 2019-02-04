/**
    matmult.cpp
    Purpose: Multiplying 2 n*n matrices.

    @author Tanush Samson
    @version 3.1 1/28/19
*/
//--------------------------INCLUDES------------------------------------
    #include <chrono> 
    #include <stdio.h>
    #include <stdlib.h> 
    #include <iostream>
    #include <time.h> 
    #include <fstream>
    using namespace std;
    using namespace std::chrono; 

int main() {   
//--------------------------SETUP---------------------------------------
    //Get upper-bound for iteration variable
    int ub;
    cout << "Enter an upper-bound for the n by n matrices: \n";
    cin >> ub;  
    
    //Initialize ofstream variable
    ofstream myfile;
    myfile.open ("Output.txt");
    
    //Initalize RNG
    srand(time(0)); 

    //Output headers
    myfile << "n" << "," << "time" << endl;

    for(int x=1; x<=ub; x++)
    {
    //creates 3 x*x matrices
    int matrixA[x][x]; 
    int matrixB[x][x]; 
    int matrixC[x][x];

//--------------------------GENERATE MATRICES---------------------------

    for(int i=0; i<x; i++) //rows 
	{   
		for(int j=0; j<x; j++) //columns
		{
			matrixA[i][j] = rand() % 10;
            matrixB[i][j] = rand() % 10;
		}
	}

//--------------------------MULTIPLY MATRICES---------------------------
    
    //Start timer
    auto start =  high_resolution_clock::now();

    for(int i=0; i<x; i++)
	{   
		for(int j=0; j<x; j++) 
		{
            for(int b = 0; b<x; b++) 
		    {
			    matrixC[i][j] += (matrixA[i][b] * matrixB[b][j]);                
		    }                       
		}       
	}

    //Stop timer
    auto stop =  high_resolution_clock::now();

    //Calculate time difference
    auto duration = duration_cast<nanoseconds>(stop - start); 

    myfile << x << "," << duration.count() << endl;

   } //for loop end

myfile.close();

cout << "Times written to 'Output.txt' \n" << endl;

return 0;	
}