#include <iostream>
#include <cstring>
#include<iostream>
#include<fstream>
#include <sstream>
using namespace std;
void preKMP(string pattern, int f[])
{
    int m = pattern.length(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}
 
int KMP(int i,string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    int f[m];     
    preKMP(pattern, f);     
    
    int k = 0;        
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return i-k+1;
        }
        else
            k = f[k];
    }
    return -2;
}
void word(int m,int count){
	ifstream file("cic.txt");
	string myArray[1000];
    if(file.is_open())
    {
        for(int i = 0; i < 1000; i++)
        {
            file >> myArray[i];
        }
    }
    cout<<myArray[count]<<endl;
} 
int main()
{
	ifstream file("cic.txt");
	int i=0;
    stringstream buffer;
    buffer << file.rdbuf();
    string str = buffer.str();
    cout << str;
    string pat;
    int m=0;
    cout<<"Enter substring"<<endl;
    cin>>pat;
    while(i<str.length() && i>=0){
	    int m=KMP(i,pat,str);
	    int count=0;
	    m++;
	    i=m;
	    if(i!=-1){
	    	for (int j= 0; j <i; j++){
	            if (str[j] == ' '){
	                	count++;
	            }
			}
			cout<<"The substring starts at "<<i-1<<" and the word is ";
			word(i,count);
		}  
	}
}

