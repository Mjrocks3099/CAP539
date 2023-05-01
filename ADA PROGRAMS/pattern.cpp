#include <iostream>
#include <string>

using namespace std;
 int main()
 {
     string str="gfghtyzxfds";
     string str1="f";
     bool index;
     int lt =str.length();//use for length of string1
     int lp=str1.length();//use for length of substring

     int m= lt-lp+1;
     for(int i=0;i<m;i++){
        int cou=0;//use for count
        while(cou<=lp && str[i+cou]==str1[cou])
        {
            cou+=1;
        }
        if( cou>=lp){

            index=true;
              break;
        }
        else
            index=false;

     }
if(index==true){
  cout<<"Pattern  matched"<<endl;
}
else{
   cout<<" Pattern not matched"<<endl;
}
 }
