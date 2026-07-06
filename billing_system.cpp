#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

// Number to Words Arrays
string o[] = {"","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine "};
string t[] = {"","","Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
string teen[] = {"Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};

// Function to print amount in words
void printWords(int n, ofstream &file){
    if (n == 0){
        cout << "Zero ";
        file << "Zero ";
        return;
    }
    if (n >= 100000){
        cout << o[n/100000] << "Lakh "; file << o[n/100000] << "Lakh ";
        n %= 100000;
    }
    if (n >= 1000){
        cout << o[n/1000] << "Thousand "; file << o[n/1000] << "Thousand ";
        n %= 1000;
    }
    if (n >= 100){
        cout << o[n/100] << "Hundred "; file << o[n/100] << "Hundred ";
        n %= 100;
    }
    if (n >= 10 && n < 20){
        cout << teen[n-10]; file << teen[n-10];
    } else {
        if (n >= 20){
            cout << t[n/10]; file << t[n/10];
        }
        if (n % 10 > 0){
            cout << o[n%10]; file << o[n%10];
        }
    }
}

// Function for rupees & paise
void printInWord(float amount, ofstream &file){
    int rupees = (int)amount;
    int paise = (int)((amount - rupees) * 100 + 0.5);

    cout << "Final Total in words: ";
    file << "Final Total in words: ";

    if (rupees == 0){
        cout << "Zero Rupees ";
        file << "Zero Rupees ";
    } else {
        printWords(rupees, file);
        cout << "Rupees ";
        file << "Rupees ";
    }

    if (paise > 0){
        printWords(paise, file);
        cout << "Paise ";
        file << "Paise ";
    }

    cout << "Only\n";
    file << "Only\n";
}

int main(){
    string CustomerName;
    int NumItems;
    string iteamName;
    string itemName[50];
    float qty[50], price[50], total[50];
    float SubTotal = 0;

    // File created
    ofstream file("bill system file.txt");

    cout << "Enter Customer Name : ";
    getline(cin, CustomerName);

    cout << "Enter number of items : ";
    cin >> NumItems;

    // Date
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char date[20];
    strftime(date, sizeof(date), "%d-%m-%Y", ltm);

    for (int i = 0; i < NumItems; i++){
        cout << "\nEnter name of item " << i+1 << ": ";
        cin.ignore();
        getline(cin,itemName[i]);

        cout << "Enter quantity of " << itemName[i] << ": ";
        cin >> qty[i];
        cout << "Enter price of " << itemName[i] << ": ";
        cin >> price[i];

        total[i] = qty[i] * price[i];
        SubTotal += total[i];
    }

    float gst = SubTotal * 0.18;
    float discount = SubTotal * 0.10;
    float FinalTotal = SubTotal + gst - discount;


    // Header
    file << "===================================================================\n";
    file << "                             TAX INVOICE                  \n";
    file << "============================== BILL ===============================\n";
    file << "Invoice No    : INV1001\n";
    file << "Date          : " << date << "\n";
    file << "Customer Name : " << CustomerName << "\n";
    file << "--------------------------------------------------------------------\n";
    file << "Item\t\tQty\tPrice\tTotal\n";
    file << "--------------------------------------------------------------------\n";

    cout << "\n===================================================================\n";
    cout << "                              TAX INVOICE                  \n";
    cout << " =============================== BILL ===============================\n";
    cout << "Invoice No    : INV1001\n";
    cout << "Date          : " << date << "\n";
    cout << "Customer Name : " << CustomerName << "\n";
    cout <<"-----------------------------------------------------------------------\n";
    cout << "Item\t\tQty\tPrice\tTotal\n";
    cout << "----------------------------------------------------------------------\n";
    for (int i = 0; i < NumItems; i++){
        file << itemName[i] << "\t\t" << qty[i] << "\t" << price[i] << "\t" << total[i] << "\n";
        cout << itemName[i] << "\t\t" << qty[i] << "\t" << price[i] << "\t" << total[i] << "\n";
    }

    file << "--------------------------------------------------------------------\n";
    file << "Sub Total            : " << SubTotal << "\n";
    file << "GST (18%)            : " << gst << "\n";
    file << "Discount (10%)       : " << discount << "\n";
    file << "Final Total with GST : " << FinalTotal << "\n";
    file << "--------------------------------------------------------------------\n";
    file << "Final Total          : " << FinalTotal << "\n";

    cout <<"---------------------------------------------------------------------\n";
    cout << "Sub Total            : " << SubTotal << "\n";
    cout << "GST (18%)            : " << gst << "\n";
    cout << "Discount (10%)       : " << discount << "\n";
    cout << "Final Total with GST : " << FinalTotal << "\n";
    cout <<"---------------------------------------------------------------------\n";
    cout << "Final Total          : " << FinalTotal << "\n";

    // Print amount in words
    printInWord(FinalTotal, file);

    // Footer
    cout << "====================================================================\n";
    cout << "                 Thank you for shopping with us!            \n";
    cout << "====================================================================\n";

    file << "=====================================================================\n";
    file << "                 Thank you for shopping with us!            \n";
    file << "=====================================================================\n";

    file.close(); // Important!
    return 0;
}

