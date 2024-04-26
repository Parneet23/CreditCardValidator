#include <iostream>
#include <string>
using namespace std;
void creditCardValidator(string cc_num) {
	//Luhn Algorithm for validating credit card number
	//starting from second last digit to all other digit multiplying the number by 2 and then adding all the digits and storing the sum in checkSum 
	int checkSum=0;
	for(int i=cc_num.length()-2; i>=0; i=i-2) {
		int num=cc_num[i]-'0';
		num=num*2;
		while(num != 0) {
			checkSum += num%10;
			num=num/10;
		}
	}
	//From the last digit for every other number adding the number in checkSum
	for(int i=cc_num.length()-1; i>=0; i=i-2) {
		int num=cc_num[i]-'0';
		checkSum += num%10;
	}
	//if checkSum is divisible by 10, then credit card is valid
	if(checkSum % 10 == 0) {
		cout << "Credit card number is valid\n";
	}
	//Else not valid
	else {
		cout << "Credit card number is not valid\n";
	}
}
int main() {
	string creditNum;
	cout << "Enter credit card number\n";
	cin >> creditNum;
	creditCardValidator(creditNum);
}