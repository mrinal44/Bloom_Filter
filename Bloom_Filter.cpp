#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*
  This is a Simple Implementation of Bloom Filter
  This program is written by-
  Mrinal Kanti Sadhukhan
  M.Tech CSE(AC) NIT Bhopal
  Scholar Number: 212112313
*/

class BloomFilter{
private:
    vector<bool>filter;
    int filterSize;

    //Hash Functions
    int hashFunc_1(string str){
        int hashValue=0;
        for(int i=0;i<str.size();i++){
            hashValue+=(pow(13,i)*(int)str[i]);
            hashValue%=filterSize;
        }
        return hashValue;
    }
    int hashFunc_2(string str){
        int hashValue=0;
        for(int i=0;i<str.size();i++){
            hashValue+=(str[i]*7)%filterSize;
            hashValue%=filterSize;
        }
        return hashValue;
    }

public:
    //Initialize the Filter
    BloomFilter(int filterSize){
        filter=vector<bool>(filterSize,0);
        this->filterSize=filterSize;
    }

    //Insert into Filter
    void insertion(string str){
        int pos1=hashFunc_1(str)%filterSize;
        int pos2=hashFunc_2(str)%filterSize;
        //Marking the positions
        filter[pos1]=true;
        filter[pos2]=true;
    }

    //If returns True; it can be false also (False +ve)
    //If returns False; it is false
    bool lookUp(string str){
        //Position 1
        int pos1=hashFunc_1(str)%filterSize;
        //Position 2
        int pos2=hashFunc_2(str)%filterSize;
        //Returns True, if both positions are Set Already

        if(filter[pos1] && filter[pos2])return true;
        //Return False, otherwise
        return false;
    }
};
int main(){
    int filterSize;
    //Taking Filter size input
    cout<<"Enter Filter Size:"<<endl;
    cin>>filterSize;

    //Creating Bloom Filter Object with
    //user-defined filter size
    BloomFilter filter(filterSize);

    //Inserting items into the Filter
    string item1,item2;
    cout<<"Enter the items:"<<endl;
    cin>>item1>>item2;  //Taking inputs from User
    filter.insertion(item1);
    filter.insertion(item2);

    //Checking if an item is already present
    cout<<"Enter the item you want to search: "<<endl;
    string item;
    cin>>item;
    if(filter.lookUp(item)){
        //False +ve case
        cout<<item<<" is Probably Present!"<<endl;
    }else{
        cout<<item<<" Not Present"<<endl;
    }

    return 0;
}
