//Ruel Riego R. Lofranco
//BSCPE 4A
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//string data
string Ones_complement(string data)

//data length
{
for (int x = 0; x < data.length(); x++) {
if (data[x] == '0')
data[x] = '1';
else
data[x] = '0';
} 
return data;
}

//checksum 
string checksum(string data, int block_size)
{
int y = data.length();
if (y % block_size != 0) {
int pad_size = block_size - (y % block_size);
for (int x = 0; x < pad_size; x++) {
data = '0' + data;
}
}
    
//result
string result = "";
for (int x = 0; x < block_size; x++) {
result += data[x];
}

for (int x = block_size; x < y; x += block_size) {
        string next_block = "";
 for (int z = x; z < x + block_size; z++) {
        next_block += data[z];
        }
        
string additions = "";
int sum = 0, carry = 0;
for (int a = block_size - 1; a >= 0; a--) {
sum += (next_block[a] - '0')
                   + (result[a] - '0');
                   
carry = sum / 2;
if (sum == 0) {
additions = '0' + additions;
sum = carry;
}
else if (sum == 1) {
additions = '1' + additions;
sum = carry;
}
else if (sum == 2) {
additions = '0' + additions;
sum = carry;
}
else {
additions = '1' + additions;
sum = carry;
}
}
 
string final = "";
if (carry == 1) {
for (int e = additions.length() - 1; e >= 0;
                 e--) {
                if (carry == 0) {
                    final = additions[e] + final;
                }
                else if (((additions[e] - '0') + carry) % 2
                         == 0) {
                    final = "0" + final;
                    carry = 1;
                }
                else {
                    final = "1" + final;
                    carry = 0;
                }
            }
 
            result = final;
        }
        else {
            result = additions;
        }
    }
 
    return Ones_complement(result);
}
 
bool checker(string sent_message, string rec_message, int block_size)
{
    string sender_checksum = checksum(sent_message, block_size);
    string receiver_checksum = checksum(rec_message + sender_checksum, block_size);
 
    if (count(receiver_checksum.begin(), receiver_checksum.end(), '0') == block_size) {
return true;
}
else {
return false;
}
}


int main()
{
string sent_o;
string receive_o;
int block_size = 8;

cout<< "Enter sent message:  ";
cin>> sent_o;
cout<< "Enter receive message:  ";
cin>> receive_o; 
	
if (checker(sent_o, receive_o, block_size)) {
cout << "No Error!";
}
else {
cout << "Error!";
}
return 0;
}
