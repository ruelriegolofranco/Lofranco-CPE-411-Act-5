//Ruel Riego R. Lofranco
//BSCPE 4A
#include <iostream>
using namespace std;
int main(){
    
string crc, decoded;
cout << "Enter Message: ";
getline(cin, decoded);
cout << "Enter Divisor: ";
getline(cin, crc);
for(int x=0; x <= decoded.length() - crc.length(); ){
for(int y=0; y < crc.length(); y++)
decoded[x+y] = decoded[x+y] == crc[y] ? '0':'1';
for(; x < decoded.length() && decoded[x] != '1'; x++);

}
for(char x : decoded.substr(decoded.length() - crc.length() ) )
if(x != '0'){
cout <<"Status: Error";
return 0;
}
cout <<"Status: No Error!";

return 0;
}
