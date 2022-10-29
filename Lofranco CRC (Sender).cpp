//Ruel Riego R. Lofranco
//BSCPE 4A
#include <iostream>
using namespace std;
int main(){ 
string message,crc,encoded="";

cout <<"Enter message: ";
getline(cin,message);
cout <<"Enter divisor: ";
getline(cin,crc);

int c=message.length(),n=crc.length();
encoded+=message;
for(int x=1;x<=n-1;x++)
encoded+='0';
for(int x=0;x<=encoded.length()-n; ){
for(int y=0;y<n; y ++)
encoded [x+y] = encoded[x+y] == crc[y]? '0':'1';
for(;x<encoded.length() && encoded[x]!='1';x++); 
}
cout << "Final Encoded CRC:" << message+encoded.substr(encoded.length()-n+1);
    return 0;
}
