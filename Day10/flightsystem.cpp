
#include <iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

struct Flight{
    string fno;
    string dair;
    string aair;
    string dtime;
    string atime;
    int aseat;
    float ppseat;
    
    Flight(string fn,string da,string aa,string dt,string at,int seats,float price):fno(fn),dair(da),aair(aa),dtime(dt),atime(at),aseat(seats),ppseat(price){}
    
};

void display(const vector<Flight>& flights){
    cout<<left<<setw(15)<<"Flight NO. "<<setw(15)<<"From"<<setw(15)<<"To"<<setw(20)<<"Departure Time"<<setw(20)<<"Arrival Time"<<setw(10)<<"Seats"<<setw(10)<<"Price"<<endl;
    
    for(const auto& flight:flights){
        cout<<left<<setw(15)<<flight.fno<<setw(15)<<flight.dair<<setw(15)<<flight.aair<<setw(20)<<flight.dtime<<setw(20)<<flight.atime<<setw(10)<<flight.aseat<<setw(10)<<flight.ppseat<<endl;
    }
}

void search(const vector<Flight>& flights,const string& from,const string& to,const string& date=""){
    cout<<"Available flights from "<<from<<" to "<<to<<(date.empty()?" ":" on "+date)<<" : "<<endl;
    cout<<left<<setw(15)<<"Flight NO. "<<setw(15)<<"From"<<setw(15)<<"To"<<setw(20)<<"Departure Time"<<setw(20)<<"Arrival Time"<<setw(10)<<"Seats"<<setw(10)<<"Price"<<endl;
    
    for(const auto& flight:flights){
        if(flight.dair==from && flight.aair==to &&(date.empty()||flight.dtime.substr(0,10)==date)){
            cout<<left<<setw(15)<<flight.fno<<setw(15)<<flight.dair<<setw(15)<<flight.aair<<setw(20)<<flight.dtime<<setw(20)<<flight.atime<<setw(10)<<flight.aseat<<setw(10)<<flight.ppseat<<endl;
        }
    }
}

void book(vector<Flight>& flights, const string& fno, int seats) {
    for (auto& flight : flights) {
        if (flight.fno == fno) {
            if (seats <= 0) {
                cout<<"Error: Number of seats to book must be positive."<<endl;
                return;
            }
            if (flight.aseat >= seats) {
                flight.aseat -= seats;
                cout << "Booked " << seats << " seats on flight " << fno << "." << endl;
            } else {
                cout << "Error: Not enough available seats." << endl;
            }
            return;
        }
    }
    cout << "Error: Flight " << fno << " not found." << endl;
}

void cancel(vector<Flight>& flights, const string& fno, int seats) {
    for (auto& flight : flights) {
        if (flight.fno == fno) {
            if (seats <= 0) {
                cout<<"Error: Number of seats to cancel must be positive."<<endl;
                return;
            }
            flight.aseat += seats;
            cout << "Cancelled " << seats << " seats on flight " << fno << "." << endl;
            return;
        }
    }
    cout << "Error: Flight " << fno << " not found." << endl;
}
void add(vector<Flight>& flights,const string& fno,const string& dair,const string& aair,const string& dtime,const string& atime,int aseat,float ppseat){
    flights.emplace_back(fno,dair,aair,dtime,atime,aseat,ppseat);
    cout<<"Added flight "<<fno<<" From "<<dair<<" To "<<aair<<"."<<endl;
}
int main()
{
   vector<Flight> flights;

    // Adding some initial flights
    add(flights, "AA123", "BEN", "BOI", "2024-07-10 08:00", "2024-07-10 11:00", 150, 300.0);
    add(flights, "BB456", "BOI", "BEN", "2024-07-11 09:00", "2024-07-11 13:00", 200, 250.0);
    add(flights, "CC789", "DEL", "MUM", "2024-07-12 14:00", "2024-07-12 18:00", 100, 220.0);
    
    display(flights);
    
    search(flights, "BEN", "BOI");
    
    book(flights, "AA123", 2);
    
    cancel(flights, "AA123", 1);
    
    display(flights);

    return 0;
}