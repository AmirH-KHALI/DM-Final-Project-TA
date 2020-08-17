#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main() {

    for (int k = 0; k < 40; ++k) {

        string inputFileName = "inputs/In_";
        stringstream ss;
        ss<<k+1;
        string ss1;
        ss>>ss1;
        inputFileName += ss1;
        inputFileName += ".txt";

        string inputFileName1 = "inputs/input";
        stringstream ssi;
        ssi<<k+1;
        string ss1i;
        ssi>>ss1i;
        inputFileName1 += ss1i;
        inputFileName1 += ".txt";

        int result;
        char oldname[inputFileName.size() + 1];
        char newname[inputFileName1.size() + 1];
        strcpy(oldname, inputFileName.c_str());
        strcpy(newname, inputFileName1.c_str());
        result = rename( oldname , newname );
        if ( result == 0 )
            puts ( "File successfully renamed" );
        else
            perror( "Error renaming file" );
    }

}
