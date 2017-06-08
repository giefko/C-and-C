#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main()
{   // DATA ENTRY BEGIN --------------------------------------------------------
    system("cls");
    unsigned short int error=0;
    string poss;//POSSIBLE CHARACTER COMBINATIONS
    unsigned short int pass;//MAXIMUM PASSWORD LENGTH
    string password; //ACTUAL PASSWORD
    unsigned short int found=0;

    cout << "SELECT CHARACTER SET:\n\n";
    cout << "\t1. abcdefghijklmnopqrstuvwxyz\n";
    cout << "\t2. ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
    cout << "\t3. 0123456789\n\n";
    cout << "\t4. 1&2\n";
    cout << "\t5. 1&2&3\n";
    cout << "\t6. Other\n\t";
    cout << "----------------------------------\n\t";

    unsigned short int choice; // SELECTION FROM CHARACTER SET
    string dataset; //STRING FOR CHARACTER SET
    cin >> choice;

    switch ( choice ) {

      case 1 :
        // Process for test = 1
        dataset="abcdefghijklmnopqrstuvwxyz";
        break;

      case 2 :
        // Process for test = 5
        dataset="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        break;

      case 3 :
        // Process for test = 5
        dataset="0123456789";
        break;

      case 4 :
        // Process for test = 5
        dataset="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        break;

      case 5 :
        // Process for test = 5
        dataset="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        break;

      case 6 :
        // Process for all other cases.
        cout << "\nENTER YOUR OWN CHARACTER SET: ";
        cin >> dataset;
        break;

      default :
        error=1;

    }
    if(error==0){
        poss=dataset;

        cout << "\nENTER PASSWORDS MAXIMUM LENGTH: ";
        cin >> pass;

        unsigned short int i=0;
        while(poss[i])
        {
                      i++;
        }

        int pass_array[pass-1];
        unsigned short int j=0;
        while(j<pass)
        {
                      pass_array[j]=0;
                      j++;
        }

        unsigned short int comb_max=i-1; // SIZE OF COMBINATIONS ARRAY
        signed short int pass_max=j-1; // MAXIMUM SIZE OF PASSWORD

        signed short int pointer; //POINTER WILL EQUAL THE CURRENT PASS SIZE
        // THIS ENABLES THE FLOATING POINT TO CHANGE THE COMBINATIONS

        unsigned int counter=0; // COUNTER FOR EACH COMBINATION TRY

        // DATA ENTRY END ----------------------------------------------------------

        // OPENS THE TEXT FILE TO WRITE PASSWORDS TO
        ofstream myfile;
        myfile.open ("C:\\Users\\stratos\\Desktop\\passwords.txt");
        // -----------------------------------------

        // ---- start timer ----
        time_t start,end;
        double dif;
        time (&start);

        while(pass_max>=0)
        {
        do
        {
                 pointer=pass_max;
                 while(pass_array[pointer]<=comb_max)
                 {
                                                     string curr;//  CURRENT PASSWORD TRY
                                                     counter++;
                                                     j=0;
                                                     while(j<=pass_max)
                                                     {
                                                                       curr+= poss[pass_array[j]];
                                                                       j++;
                                                     }
                                                     myfile << curr << " \n";
                                                     pass_array[pointer]=pass_array[pointer]+1;
                 }
                 pass_array[pointer]=0;
                 pointer--;
                 while(pass_array[pointer]==comb_max)
                 {
                                                     pass_array[pointer]=0;
                                                     pointer--;
                 }
                 pass_array[pointer]=pass_array[pointer]+1;
        }
        while(pointer>=0);

        pass_max--;
        }
        // ---- end timer ----
        end:
        time (&end);
        dif = difftime (end,start);

        // ---- close text file ---- //
        myfile.close();
        // ------------------------- //

        // ----- DISPLAY RESULTS ---- //
        unsigned int combinations_per_second;
        combinations_per_second=counter/dif;
        system("cls");
        cout << "\nWORDLIST CREATED";
        cout << "\n------------------------------";
        cout << "\nRUN TIME:\t " << dif << " sec";
        cout << "\nCOMBINATIONS:\t " << counter;
        cout << "\nCOMB/SEC: \t " << combinations_per_second;
        cout << "\n\n\n";
        system("pause");
        return 0;
    }else{
        cout << "\tINVALID CHOICE!";
        system("pause");
    }
}
