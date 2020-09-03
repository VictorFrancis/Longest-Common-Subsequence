#include<iostream>

using namespace std;

int maximum(int num1, int num2){

    if(num1>num2){
        return num1;
    }
    else{
        return num2;
    }

    }

int lcs(string line1, string line2, int line1Size, int line2Size){

    //Initializing length of LCS grid with additional 1 row and 1 column
    int lengthOfLcs[line1Size+1][line2Size+1];

    for(int i=0; i<=line1Size; i++){
        for(int j=0; j<=line2Size; j++){
            //when row=0 and column=0
            //length of LCS is 0
            if(i==0 && j==0){
                lengthOfLcs[i][j]=0;
            }
            //when last letters match for both strings
            else if(line1[i-1]==line2[j-1]){
                //we add the LCS length of [i-1 & j-1] +1
                //[diagonal grid from the LCS grid table] + 1
                lengthOfLcs[i][j]=lengthOfLcs[i-1][j-1]+1;
            }
            else{
                lengthOfLcs[i][j]=maximum(lengthOfLcs[i-1][j],lengthOfLcs[i][j-1]);
                //if the last letter dosen't match
                //we find the maximum value from the grid above the current grid
                //And the grid from the left of the current grid of LCS table
            }
        }
    }
    //return total length of LCS
    return lengthOfLcs[line1Size][line2Size];

    }

int main(){

    string line1;
    string line2;

    cout<<"Enter Line 1: ";
    cin>>line1;

    cout<<"Enter Line 2: ";
    cin>>line2;

    int line1Size= line1.size();
    int line2Size= line2.size();

    cout<<"LCS: "<<lcs(line1,line2,line1Size,line2Size);

    return 0;

    //n=length of line 1
    //m=length of line 2
    //Time Complexity = n*m
    //                = nxm

    }

