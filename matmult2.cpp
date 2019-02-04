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


int main ()
{
  //--------------------------DECLARATIONS----------------------------------
   
    
    int x;
    int print;
    int mode;
    ofstream myfile;

    

    //Initalize RNG
    srand(time(0)); 


  cout << "Automatic or Manual? (1 for Auto, 0 for Manual): \n";
  cin >> mode; 

  if(mode==1)
    {
       
    }else{
        //Matrix variable
        cout << "Please enter an integer value n to generate n by n matrices: \n";
        cin >> x;

         //creates 3 x*x matrices
        int matrixA[x][x]; 
        int matrixB[x][x];
        int matrixC[x][x];

        //Print variable
        cout << "Do you want to print the matrices? (1 for yes, 0 for no): \n";
        cin >> print;

        if(print!=1 && print != 0)
        {
            print=0;
        }

      cout << endl;
      cout << "Generating matrices...\n" << endl;
      
      int *A = matrixA;
      int *B = matrixB[x][x];
      int *C = matrixC[x][x];
      
      int A[x][x]={}

      generate(x, (int*)matrixA, B);
      multiply(x, A, B, C);

    }
  return 0;
}
//--------------------------GENERATE FUNCTION---------------------------
  void generate (int x, int *A, int *)
  {
    
    for(int i=0; i<x; i++) //rows 
    {   
      for(int j=0; j<x; j++) //columns
      {
        A[i][j] = rand() % 10;
        B[i][j] = rand() % 10; // *(A + (i * x) + j
      }
    }
  }
//--------------------------MULTIPLY FUNCTION---------------------------
  int multiply (int x, int *A, int *B, int *C)
  {
   
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
  }
