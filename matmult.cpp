/**
    matmult.cpp
    Purpose: Multiplying 2 n*n matrices.

    @author Tanush Samson
    @version 1.1 1/28/19
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
    //Mode variable
    int m;
    cout << "Automatic or Manual? (1 for Auto, 0 for Manual): \n";
    cin >> m;
    
    int x;
    int y;
    ofstream myfile;

    if(m==1)
    {
       
    }else{
        //Matrix variable
        cout << "Please enter an integer value n to generate n by n matrices: \n";
        cin >> x;

        //Print variable
        cout << "Do you want to print the matrices? (1 for yes, 0 for no): \n";
        cin >> y;

        if(y!=1 && y != 0)
        {
            y=0;
        }
    }


    //creates 3 x*x matrices
    int matrixA[x][x]; 
    int matrixB[x][x]; 
    int matrixC[x][x];

    //Initalize RNG
    srand(time(0)); 
//--------------------------GENERATE MATRICES---------------------------
    
    cout << "Generating matrices...\n" << endl;

    for(int i=0; i<x; i++) //rows 
	{   
		for(int j=0; j<x; j++) //columns
		{
			matrixA[i][j] = rand() % 10;
            matrixB[i][j] = rand() % 10;
            matrixC[i][j] = 0;
		}
	}

//--------------------------MULTIPLY MATRICES---------------------------
    
    cout << "Multiplying matrices...\n" << endl;

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

    
//--------------------------PRINT MATRICES------------------------------
    
    if(y==1){
    //Print Matrix
    cout << "Matrix A" << endl;
    for(int i=0; i<x; i++)
	{
		for(int j=0; j<x; j++) 
		{
			cout << matrixA[i][j]  << "  ";
		}
		cout << endl;
	}

    cout << endl;

    cout << "Matrix B" << endl;
    for(int i=0; i<x; i++)
	{
		for(int j=0; j<x; j++) 
		{
			cout << matrixB[i][j]  << "  ";
		}
		cout << endl;
	}

    cout << endl;

    cout << "Matrix C = Matrix A * Matrix B" << endl;
    for(int i=0; i<x; i++)
	{
		for(int j=0; j<x; j++) 
		{
			cout << matrixC[i][j]  << "  ";
		}
		cout << endl;
	}

    cout << endl;
    }
    //Print out the time taken
    cout << "Time taken: " << duration.count() << " nanoseconds \n" << endl;



  myfile.open ("Output.txt");
  myfile << x << "," << duration.count() << endl;
  myfile.close();

return 0;	
}