#include<iostream>
#include<fstream>
using namespace std;

int number_of_paragraph = 0;

void numberofparagraph();

int main()
{
	
    string line;
    ifstream myfile("textexample.txt");

    if(myfile.is_open())
	{
        while(!myfile.eof())
	
		{
            getline(myfile,line);
            cout<<paragraph << endl;
            number_of_paragraph++;
        }
        
        myfile.close();
    }
    
    numberofparagraph();
}

void numberofparagraph()
{
    number_of_paragraph--;
    cout<<"number of paragraph in text file: " << number_of_paragraph << endl;
}

