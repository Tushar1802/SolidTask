#include <bits/stdc++.h>
using namespace std;

// interface 
class paymentProvider {
public:
    virtual void processPayment() = 0; 
};
 
// Concrete  classes for paytm amazonpay and phonepe
class Paytm : public paymentProvider {
public:
    void processPayment(){ cout << "Payment processed via Paytm.\n"; }
};
 
class AmazonPay : public paymentProvider {
public:
    void processPayment() { cout << "Payment processed via Amazon Pay.\n"; }
};
 
class PhonePe : public paymentProvider {
public:
    void processPayment(){ cout << "Payment processed via PhonePe.\n"; }
};
 
//payment methods interface
class PaymentMethod {
public:
    virtual bool getDetails() = 0;  // Pure virtual function to collect payment details
    virtual void makePayment() = 0; // Pure virtual function to complete the payment
};
 
// Concrete classes for wallet upi debit caes and credit card
class Wallet : public PaymentMethod {
public:
    bool getDetails() {
        string phone;
        
        cout << "Enter Phone number  ";
        cin >> phone;
        cout << "Phone number entered: " << phone << endl;
        cout<<phone.size();
        if(phone.size()!=10){
            
           return false;
        }
        else
        return true;
        
    }
    void makePayment()  {
        cout << " Wallet Payment successful .\n";
    }
};
 
class UPI : public PaymentMethod {
public:
    bool getDetails() {
        string upiID;
        cout << "Enter UPI ID  ";
        cin >> upiID;
        cout << "UPI ID entered: " << upiID << endl;
        bool flag=false;
        for( int i=0;i<upiID.size();i++){
            if(i=='@')flag=true;
        }

        if(flag==true)return true;
        else return false;
        
    }
    void makePayment() {
        cout << "Payment successful.\n";
    }
};
 
class CreditCard : public PaymentMethod {
public:
    bool getDetails(){
        string cardNumber, expiryDate, cvv;
        cout << "Enter Credit Card details:\n";
        cout << "Card Number: ";
        cin >> cardNumber;
 if(cardNumber.size()!=16)return false;

        cout << "Expiry Date (MM/YY): ";
        cin >> expiryDate;
        cout << "CVV: ";
        cin >> cvv;
        int stringToInt=stoi(cvv);

        if(cvv.size()!=3 || !isdigit(stringToInt))return false;
        cout << "Credit Card details entered: " << cardNumber << ", Expiry: " << expiryDate << ", CVV: " << cvv << endl;
       return true;
    }
    void makePayment() {
        cout << "Payment successful using Credit Card.\n";
    }
};
 
class DebitCard : public PaymentMethod {
public:
    bool getDetails(){
        string cardNumber, expiryDate, cvv;
        cout << "Enter Debit Card details:\n";
        cout << "Card Number: ";
        cin >> cardNumber;
        if(cardNumber.size()!=16)return false;
        cout << "Expiry Date (MM/YY): ";
        cin >> expiryDate;
        if(expiryDate[2]!='/')return false;
        cout << "CVV: ";
        cin >> cvv;
        int stringToInt=stoi(cvv);
         if(cvv.size()!=3 || !isdigit(stringToInt) )return false;
        cout << "Debit Card details entered: " << cardNumber << ", Expiry: " << expiryDate << ", CVV: " << cvv << endl;

        return true;
    }

    void makePayment() {
        cout << "Debit card DePayment successful.\n";
    }
};
 
// PaymentProcess class
class PaymentProcess {
private:
    paymentProvider* provider;  //payment provider
    PaymentMethod* method;      //payment method
 
public:
    void choosepaymentProvider() {
        int choice;
        cout << "Choose Payment Provider:\n1. Paytm\n2. Amazon Pay\n3. PhonePe\n";
        cin >> choice;
 
        // Selecting the provider
        if (choice == 1) provider = new Paytm();
        else if (choice == 2) provider = new AmazonPay();
        else if (choice == 3) provider = new PhonePe();
        else cout << "Invalid choice.\n";
    }
 
    void choosePaymentMethod() {
        int choice;
        cout << "Choose Payment Method:1. Wallet 2. UPI 3. Credit Card  4. Debit Card\n";
        cin >> choice;
 
        // Selecting the payment method 
        if (choice == 1) method = new Wallet();
        else if (choice == 2) method = new UPI();
        else if (choice == 3) method = new CreditCard();
        else if (choice == 4) method = new DebitCard();
        else cout << "Invalid choice.\n";
    }
 
    void processPayment() {
        float amount;
        cout << "Enter the amount to pay: ";
        cin >> amount;
 
        if (amount <= 0) {
            cout << "Amount should be greater than zero.\n";
            return;
        }
 
       bool istrue= method->getDetails();  // Get payment details.
       
       if(istrue){
        provider->processPayment();  // Process payment.
        method->makePayment();  // Complete the payment.
        cout << "Payment of Rs." << amount << " completed successfully.\n";}
        else{
            cout<<"Invalid details"<<endl;
        }
    }
 
    
};
 
// Main function to run the application
int main() {
    PaymentProcess payment;  // Create a PaymentProcess object
 
    payment.choosepaymentProvider();  // Let the user choose a payment provider
    payment.choosePaymentMethod();    // Let the user choose a payment method
    payment.processPayment();         // Process the payment and complete the flow
 
    return 0;  // Exit the program
}
 
 