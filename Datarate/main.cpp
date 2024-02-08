#include <iostream>
#include <cstdio>
#include <limits>
#include <iomanip>

using namespace std;

string formatCurrencybaud(double amount);
string formatCurrencybps(double amount);
string formatCurrencyMbytes(double amount);
string formatCurrencys(double amount);
int ParityBit(char n);

int main(){
    cout<<"-[Infomation]";
    for(int i = 0; i<45; i++)
    cout<<"-";
    cout<<endl;
    cout<<"ID: 64028780"<<endl;
    cout<<"Name: Mr.Phonsing Ps."<<endl;
    cout<<"Description: Bitrete Calculation"<<endl<<endl;

    int DataBits;
    bool DataBitStatus = false;

    cout<<"-[Input]";
    for(int i = 0; i<50; i++)
    cout<<"-";
    cout<<endl;
    cout<<"Start bit (fixed): 1"<<endl;
    cout<<"Data bits (5, 6, 7, 8, 9): ";
    cin>> DataBits;
    while(!DataBitStatus){
        if((DataBits != 5 && DataBits != 6 && DataBits != 7 && DataBits != 8 && DataBits != 9) || cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits < streamsize >::max(), '\n');
            cout<<"Pless! Data bits (5, 6, 7, 8, 9): ";
            cin>> DataBits;
        }else DataBitStatus = true;
    }

    char ParityBits;
    bool ParityBitStatus = false;

    cout<<"Parity bits (n:none, o:odd, e:even): ";
    cin>>ParityBits;
    while(!ParityBitStatus){
        if(ParityBits != 'n' && ParityBits != 'o' && ParityBits != 'e'){
            cout<<"Pless! Parity bits (n:none, o:odd, e:even): ";
            cin>>ParityBits;
        }else ParityBitStatus = true;
    }

    int StopBits;
    bool StopBitStatus = false;

    cout<<"Stop bits (1, 2): ";
    cin>>StopBits;
    while(!StopBitStatus){
        if((StopBits != 1 && StopBits != 2) || cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits < streamsize >::max(), '\n');
            cout<<"Pless! Stop bits (1, 2): ";
            cin>>StopBits;
        }else StopBitStatus = true;
    }

    int Baudrate;
    bool BaudrateStatus = false;

    cout<<"Baudrate: (min: 10 buad): ";
    cin>>Baudrate;
    while(!BaudrateStatus){
        if(Baudrate < 10 || cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits < streamsize >::max(), '\n');
            cout<<"Pless! Baudrate: (min: 10 buad): ";
            cin>>Baudrate;
        }else BaudrateStatus = true;
    }
    string durationTime = formatCurrencybaud(Baudrate);
    double Totalbits = DataBits + StopBits + ParityBit(ParityBits) + 1;
    cout<<endl<<"-[Summary]";
    for(int i = 0; i<48; i++)
    cout<<"-";
    cout<<endl;
    cout<<"Total bits: "<< Totalbits <<" bist (start: 1, data: "<<DataBits<<", parity: "<<ParityBit(ParityBits)<<", stop: "<<StopBits<<")"<<endl;
    cout<<"Boaudrate: "<<durationTime<<endl<<endl;

    cout<<"-[Result]";
    for(int i = 0; i<49; i++)
    cout<<"-";
    cout<<endl;

    double signalTime = 1;
    double r = DataBits / Totalbits;
    double Byterate = Baudrate * r / 8;
    //double byteHour;

    cout<<"Signal time:     "<<formatCurrencys(signalTime / Baudrate)<<endl;
    cout<<"Bitrate:           "<<formatCurrencybps(Baudrate * r )<<" (with r = "<<r<<")"<<endl;
    cout<<"Bytes/hour:        "<<formatCurrencyMbytes(Byterate * 60 * 60)<<endl<<endl;

    for(int i = 0; i<58; i++)
    cout<<"-";
    cout<<endl;
    return 0;
}

string formatCurrencybaud(double amount) {
    double thousands= 0.0 , millions = 0.0;
    if (amount < 1000) 
        return to_string(amount) + " baud";
    else if (amount < 1000000) 
        return to_string(thousands = static_cast<double>(amount) / 1000) + " kbaud";
    else 
        return to_string(millions = static_cast<double>(amount) / 1000000) + " Mbaud";  
}

string formatCurrencybps(double amount) {
    double thousands= 0.0 , millions = 0.0;
    if (amount < 1000) 
        return to_string(amount) + " bps";
    else if (amount < 1000000) 
        return to_string(thousands = static_cast<double>(amount) / 1000) + " kbps";
    else 
        return to_string(millions = static_cast<double>(amount) / 1000000) + " Mbps";  
}

string formatCurrencyMbytes(double amount) {
    double thousands= 0.0 , millions = 0.0;
    if (amount < 1000) 
        return to_string(amount) + " baud";
    else if (amount < 1000000) 
        return to_string(thousands = static_cast<double>(amount) / 1000) + " Kbytes";
    else 
        return to_string(millions = static_cast<double>(amount) / 1000000) + " Mbytes";  
}

string formatCurrencys(double amount) {
    if (amount < 0.0001) 
        return to_string(amount) + " s";
    else if (amount < 0.0000001) 
        return to_string(amount * 1000) + " ms";
    else 
        return to_string(amount * 1000000) + " us";  
}

int ParityBit(char n){
    switch (n){
        case  'n':
            return 0;
            break;
        case  'o':
            return 1;
            break;
        case  'e':
            return 1;
            break;
    default:
        return 1;
        break;
    }
}