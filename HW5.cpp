//Preston Peck
//CS 365
//October 27, 2017
//HW 5

#include <iostream>
#include <cmath>
using namespace std;

void optionCall(double K, double S, double& H, double& W, double M, bool l);
void optionPut(double K, double S, double& H, double& W, double M, bool l);
void optionCalls(double K, double Ss[], double Ps[], int t, double& H, double& W, double M, bool lng);
void optionPuts(double K, double Ss[], double Ps[], int t, double& H, double& W, double M, bool lng);

int main() {
    int trades = 0;
    double strike, stock, holder, writer = 0.0;
    double multiplier = 1.0;
    bool lng = true;

    //5.1 Exercise of long & short call option positions
    cout << "5.1.1 Long American call option" << endl;
    strike = 101;
    stock = 107;
    optionCall(strike, stock, holder, writer, multiplier, lng);

    cout << "5.1.2 Long European call option" << endl;
    strike = 102;
    stock = 106;
    optionCall(strike, stock, holder, writer, multiplier, lng);

    lng = false;
    cout << "5.1.3 Short American call option 1" << endl;
    strike = 99;
    stock = 104;
    optionCall(strike, stock, holder, writer, multiplier, lng);

    trades = 3;
    cout << "5.1.4 Short American call option 2" << endl;
    strike = 55;
    double stocks1[] = {48, 52, 56, 58};
    double prices1[] = {1.1, 1.2, 1.5};
    optionCalls(strike, stocks1, prices1, trades, holder, writer, multiplier, lng);
    //The stock prices do not affect A or B

    cout << "5.1.5 Short European call option 1" << endl;
    strike = 85;
    stock = 88;
    optionCall(strike, stock, holder, writer, multiplier, lng);

    cout << "5.1.6 Short European call option 2" << endl;
    strike = 77;
    stock = 75;
    optionCall(strike, stock, holder, writer, multiplier, lng);

    cout << "5.1.7 Short European call option 3" << endl;
    strike = 55;
    double stocks2[] = {48, 52, 56, 58};
    double prices2[] = {1.1, 1.2, 1.5};
    optionCalls(strike, stocks2, prices2, trades, holder, writer, multiplier, lng);
    //The stock prices do not affect A or B

    //5.2 Exercise of long & short put option positions
    lng = true;
    cout << "5.2.1 Long American put option" << endl;
    strike = 96;
    stock = 91;
    optionPut(strike, stock, holder, writer, multiplier, lng);

    cout << "5.2.2 Long European put option" << endl;
    strike = 98;
    stock = 97;
    optionPut(strike, stock, holder, writer, multiplier, lng);

    lng = false;
    cout << "5.2.3 Short American put option 1" << endl;
    strike = 66;
    stock = 59;
    optionPut(strike, stock, holder, writer, multiplier, lng);

    cout << "5.2.4 Short American put option 2" << endl;
    strike = 45;
    double stocks3[] = {48, 47, 46, 44};
    double prices3[] = {1.1, 1.2, 1.5};
    optionPuts(strike, stocks3, prices3, trades, holder, writer, multiplier, lng);
    //The stock prices do not affect A or B

    cout << "5.2.5 Short European put option 1" << endl;
    strike = 81;
    stock = 78;
    optionPut(strike, stock, holder, writer, multiplier, lng);

    cout << "5.2.6 Short European put option 2" << endl;
    strike = 66;
    stock = 68;
    optionPut(strike, stock, holder, writer, multiplier, lng);

    cout << "5.2.7 Short European put option 3" << endl;
    strike = 45;
    double stocks4[] = {48, 47, 46, 44};
    double prices4[] = {1.1, 1.2, 1.5};
    optionPuts(strike, stocks4, prices4, trades, holder, writer, multiplier, lng);
    //The stock prices do not affect A or B
    
    //5.3 Exercise of cash settled option positions
    lng = true;
    multiplier = 100;
    strike = 1000;
    cout << "5.3.1 Long cash-settled call option" << endl;
    stock = 1050;
    optionCall(strike, stock, holder, writer, multiplier, lng);
    
    lng = false;
    cout << "5.3.2 Short cash-settled call option" << endl;
    stock = 1075;
    optionCall(strike, stock, holder, writer, multiplier, lng);
    
    lng = true;
    cout << "5.3.3 Long cash-settled put option" << endl;
    stock = 925;
    optionPut(strike, stock, holder, writer, multiplier, lng);
    
    lng = false;
    cout << "5.3.4 Short cash-settled put option" << endl;
    stock = 940;
    optionPut(strike, stock, holder, writer, multiplier, lng);
}

void optionCall(double K, double S, double& H, double& W, double M, bool l) {
    H = M * (S - K);

    if (l == true) {
        cout << "-YOU-" << endl;
    }

    else {
        cout << "-THEM-" << endl;
    }

    cout << "Holder BUYS stock at: $" << M * K << endl;
    cout << "Holder CAN SELL stock at: $" << M * S << endl;
    cout << "NET: $" << H << endl << endl;

    W = M * (K - S);
    
    if (l == false) {
        cout << "-YOU-" << endl;
    }

    else {
        cout << "-THEM-" << endl;
    }

    cout << "Writer RECIEVES for stock: $" << M * K << endl;
    cout << "Writer COULD HAVE SOLD stock at: $" << M * S << endl;
    cout << "NET: $" << W << endl << endl << endl;
}

void optionPut(double K, double S, double& H, double& W, double M, bool l) {
    H = M * (K - S);

    if (l == true) {
        cout << "-YOU-" << endl;
    }

    else {
        cout << "-THEM-" << endl;
    }

    cout << "Holder SELLS stock at: $" << M * K << endl;
    cout << "Holder COULD HAVE SOLD stock at: $" << M * S << endl;
    cout << "NET: $" << H << endl << endl;

    W = M * (S - K);
    
    if (l == false) {
        cout << "-YOU-" << endl;
    }

    else {
        cout << "-THEM-" << endl;
    }

    cout << "Writer BUYS stock at: $" << M * K << endl;
    cout << "Writer COULD HAVE BOUGHT stock at: $" << M * S << endl;
    cout << "NET: $" << W << endl << endl << endl;
}

void optionCalls(double K, double Ss[], double Ps[], int t, double& H, double& W, double M, bool lng) {
    char customer = 'A';
    double nets[t];

    for (int i = 0; i < t; i++) {
        nets[i] = Ps[i];

        if (i > 0) {
            nets[i] = nets[i] - Ps[i - 1];
        }

        if (i == 0 && lng == false) {
            cout << "-YOU-" << endl;
        }

        else {
            cout << "-" << customer << "-" << endl;

            if (i == (t - 1) && lng == true) {}

            else {
                customer = static_cast<char>(customer + 1);
            }
        }

        cout << "SELLS option at: $" << Ps[i] << endl;
        cout << "NET: $" << nets[i] << endl << endl;

        if (i == (t - 1) && lng == true) {
            cout << "-YOU-" << endl;
        }

        else {
            cout << "-" << customer << "-" << endl;
        }
        
        cout << "BUYS option at: $" << Ps[i] << endl;
        cout << "NET: $" << -1 * Ps[i] << endl << endl << endl;
    }

    H = M * (Ss[t] - K);

    if (lng == true) {
        cout << "-YOU-" << endl;
    }

    else {
        cout << "-" << customer << "-" << endl;
    }

    cout << "Holder BUYS option at: $" << Ps[t - 1] << endl;
    cout << "Holder BUYS stock at: $" << M * K << endl;
    cout << "Holder CAN SELL stock at: $" << M * Ss[t] << endl;
    cout << "NET: $" << H - Ps[t - 1] << endl << endl;

    W = M * (K - Ss[t]);

    if (lng == false) {
        cout << "-YOU-" << endl;
    }

    else {
        cout << "-" << customer << "-" << endl;
    }

    cout << "Writer RECIEVES for option: $" << Ps[0] << endl;
    cout << "Writer RECIEVES for stock: $" << M * K << endl;
    cout << "Writer COULD HAVE SOLD stock at: $" << M * Ss[t] << endl;
    cout << "NET: $" << W + Ps[0] << endl << endl << endl;
}

void optionPuts(double K, double Ss[], double Ps[], int t, double& H, double& W, double M, bool lng) {
    char customer = 'A';
    double nets[t];

    for (int i = 0; i < t; i++) {
        nets[i] = Ps[i];

        if (i > 0) {
            nets[i] = nets[i] - Ps[i - 1];
        }
        if (i == 0 && lng == false) {
            cout << "-YOU-" << endl;
        }

        else {
            cout << "-" << customer << "-" << endl;

            if (i == (t - 1) && lng == true) {}
            
            else {
                customer = static_cast<char>(customer + 1);
            }
        }

        cout << "SELLS option at: $" << Ps[i] << endl;
        cout << "NET: $" << nets[i] << endl << endl;;

        if (i == (t - 1) && lng == true) {
            cout << "-YOU-" << endl;
        }

        else {
            cout << "-" << customer << "-" << endl;
        }
        
        cout << "BUYS option at: $" << Ps[i] << endl;
        cout << "NET: $" << -1 * Ps[i] << endl << endl << endl;
    }

    H = M * (Ss[t] - K);

    if (lng == true) {
        cout << "-YOU-" << endl;
    }

    else {
        cout << "-" << customer << "-" << endl;
    }

    cout << "Holder BUYS option at: $" << Ps[t - 1] << endl;
    cout << "Holder BUYS stock at: $" << M * K << endl;
    cout << "Holder CAN SELL stock at: $" << M * Ss[t] << endl;
    cout << "NET: $" << H - Ps[t - 1] << endl << endl;

    W = M * (K - Ss[t]);

    if (lng == false) {
        cout << "-YOU-" << endl;
    }

    else {
        cout << "-" << customer << "-" << endl;
    }

    cout << "Writer RECIEVES for option: $" << Ps[0] << endl;
    cout << "Writer RECIEVES for stock: $" << M * K << endl;
    cout << "Writer COULD HAVE SOLD stock at: $" << M * Ss[t] << endl;
    cout << "NET: $" << W + Ps[0] << endl << endl << endl;
}