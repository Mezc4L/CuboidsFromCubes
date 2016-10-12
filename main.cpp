/* Damian Polak @ 2014
 * Algorithm to count number of cuboids from cubes.
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int s, v;
bool loop = true;

int licz_mod(int n)
{
    int m = 0;
    
    for(int i = 1; i <= n; i++)
    {
		if((n%i) == 0)
		{
			m++;       
		}        
    }   
    return m;
}

int main(int argc, char *argv[]) {

while(loop == true) {

system("CLS");
cout << endl << " 1 " << (char)175 << " Count number of cuboids from the cubes" << endl;
cout << " 2 " << (char)175 << " Exit" << endl << endl;
cout << "    Your choice: " << (char)175 << " ";
cin >> v;

if(v == 1) {

	system("CLS");
    cout << endl << " - Enter the number of cubes " << (char)175 << " ";
    cin >> s;
    cout << endl;
    
    if(s == 0)
    {
         cout << " Not specified amount of cubes!" << endl << endl;
         system("PAUSE");
         v = 0; 
    }
    
    if(s < 0)
    {
         cout << " Your mistake! Values of cubes are negative." << endl << endl;
         system("PAUSE");
         v = 0;    
    }
    
	if(s >= 1) {

    int tsize = licz_mod(s)*licz_mod(s);

	int *tabxtemp = new int [tsize];
	int *tabytemp = new int [tsize];
	int *tabztemp = new int [tsize];

    int it = 0;
    
	cout << endl << "---- ALL POSSIBLE COMBINATIONS ----" << endl;
    
	for(int i = 1; i <= s; i++)
    {
        for(int j = 1; j <= s; j++)
        {
              for(int k = 1; k <= s; k++)
              {
                   if(i*j*k == s)
                   {
                       tabxtemp[it] = i;
                       tabytemp[it] = j;
                       tabztemp[it] = k;
                       
					   cout << it+1 << ": " << tabxtemp[it] << " x " << tabytemp[it] << " x " << tabztemp[it] << endl;
                       it++;    
                   }
              }        
        }
    }
    
	int *tabx = new int [it];
	int *taby = new int [it];
	int *tabz = new int [it];

    for(int i = 0; i <= it-1; i++)
    {
        tabx[i] = tabxtemp[i];
        taby[i] = tabytemp[i];
        tabz[i] = tabztemp[i];      
    }
    
	delete [] tabxtemp;
	delete [] tabytemp;
	delete [] tabztemp;
	
	if(s > 1) {

    for(int i = 0; i <= it-1; i++)
    {
			
         for(int j = 0; j <= it-1; j++)
         {
			if(tabx[i] != taby[i] && tabz[i]) {
				if(((tabx[i] == tabx[j]) && (taby[i] == tabx[j])) && (tabx[i] || taby[i] || tabz[i]) != 0)
				{
					tabx[j] = 0;
					taby[j] = 0;
					tabz[j] = 0;
				}
			 
				if(((taby[i] == taby[j]) && (tabz[i] == tabx[j])) && (tabx[i] || taby[i] || tabz[i]) != 0)
				{
					tabx[j] = 0;
					taby[j] = 0;
					tabz[j] = 0;
				}
				
				if(((tabz[i] == tabz[j]) && (taby[i] == tabx[j])) && (tabx[i] || taby[i] || tabz[i]) != 0)
				{
					tabx[j] = 0;
					taby[j] = 0;
					tabz[j] = 0; 
				}
			}
		 }  
    }
	
    for(int i = 0; i <= it-1; i++)
    {
         for(int j = 0; j <= it-1; j++)
         {
			 if(((tabx[i] == tabx[j]) && (taby[i] == tabz[j])) && (tabz[i] == taby[j]) && (tabx[i] || taby[i] || tabz[i]) != 0)
			 {
				 if(taby[i] != tabz[i])
				 {
					 tabx[j] = 0;
					 taby[j] = 0;
					 tabz[j] = 0;
				 }
			 }
         }   
    }

    int j = 0;
    
	cout << endl << "---- COMBINATIONS WITHOUT REPETITIONS ----" << endl;

    for(int i = 0; i <= it-1; i++)
    {
        if((tabx[i] && taby[i] && tabz[i]) != 0)
        {
            j++;
            cout << j << ": " << tabx[i] << " x " << taby[i] << " x " << tabz[i] << endl;        
        }
    }
	}
	delete [] tabx;
	delete [] taby;
	delete [] tabz;

	v = 0;

	cout << endl << endl;
	system("PAUSE");
	}
}

if(v == 2) {
	loop = false;
}

}
    cout << endl << endl;
    return EXIT_SUCCESS;
}
