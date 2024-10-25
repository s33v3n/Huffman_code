#include <iostream>
#include <fstream>

using namespace std;

string Filename;
string* pFilename = &Filename;

char first_char;

int row = 0, col = 0, num_of_rows = 0, num_of_cols = 0, greyscale = 0;

int main()
{
    Filename = "geometr_05.pgm";

    ifstream FILE;
    FILE.open(Filename, ios::binary);

    if (FILE.good()==false)
    {
        cout<<"Error"<<endl;
        exit(0);
    }

    string line = "";

    /// First line - magic number ///

    getline(FILE, line);
    if(line.compare("P2") == 0)
    {
        cout<<"Magic number is P2. ASCII format"<<endl;
        char pixel;
    }
    else if(line.compare("P5") == 0)
    {
        cout<<"Magic number is P5. Binary format"<<endl;
        unsigned char pixel;
    }
    else
    {
        cout<<"Magick number error"<<endl;
        exit(0);
    }

    /// Second line - comment ///

    do
    {
        FILE.get(first_char);

        if (first_char == "#")  {getline(FILE, line);}
        else {FILE.unget();}

    }while(first_char == "#");

    /// Picture size - X, Y, Greymap///

    FILE >> num_of_rows >> num_of_cols >> greyscale;
    cout << "Picture size: "<<num_of_rows<<"x"<<num_of_cols<<endl;
    cout <<"Grey scale:"<<greyscale<<endl;


    /// Picture array ///

    /// We are creating 2 dimension dynamic array, so we need to create
    /// pointer to row's pointers and then from rows pointers to columns
    /// pointers

    int** picture_array = new int *[num_of_rows]; //pointer to a pointer - ROWS
    for (int i=0; i<num_of_rows; i++)
    {
        picture_array[i] = new int[num_of_cols]; // pointer to columns - COLS
    }

    unsigned char pixel;
    for (int row=0; row<num_of_rows; row++)
    {
        for (int col=0; col<num_of_cols; col++)
        {
           FILE >> pixel;
           picture_array[row][col] = pixel;
        }
    }


    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            cout <<j<<". "<<picture_array[i][j]<<endl;
        }

    }

    for (int i=0; i<num_of_rows; i++)
    {
        delete[] picture_array[i];
    }
    delete[] picture_array;
    picture_array = NULL;

    FILE.close();
    return 0;
}


