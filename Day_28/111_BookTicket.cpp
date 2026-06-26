//Program to Create ticket booking system

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <ctime>
using namespace std;

struct SeatLayout{

    // true = already booked, false = not booked
    bool filled[100]={false};
    int price =270;
    void seat(){
        char row=74;
        int c=1;
        cout << "Select seats at only $ " << price << " each seat " << "                   [--] = already booked, [A1] = empty\n"; 
        cout << "   1     2     3     4     5         6     7     8     9    10   \n\n";
        for(int i=1; i<=100; i++){

            if(filled[i-1] == true ){ 
                cout << " [--] ";
            c++;
        }
            else{ cout << " [" << row << c++ << "] "; }
            if(i%10 == 0){
                row--;
                c=1;
                cout << '\n' << endl; 
            }
            if(i%10 == 5) cout << "    ";
        }
        cout << "\n\n      = = = = = = = = = =  S C R E E N  = = = = = = = = = =     \n\n";
    }
    void fillrandom(){
        for(int i=0; i<40; i++){
            int num= rand()%100;
            filled[num] = true;
        }
    }
    int numofemptyseats(){
        int c=0;
        for(int i=0; i<100; i++){
            
            if(!filled[i])
            c++;
        }
        return c;
    }
};
struct show{

    string time;
    SeatLayout layout;
};
struct Movie {

    string name;
    vector<show> showtime;
    float duration;
    float imdb;
};
struct Ticket{

    long long id;
    string name;
    long long phone;
    string moviename;
    string movietime;
    int numofseats;
    vector<int> seatnumber;

};

int seatnum();
bool pin();
bool payment(int seats, int price);
void addmovie( vector<Movie> &movies);
void showseatnum(int seat);
void viewmovies( vector<Movie> &movie, vector<Ticket> &tickettoday);
void show_ticket( const Ticket &ticket);
void searchticket( const vector<Ticket> &ticket);
void cancelticket(vector<Ticket>& tickettoday, vector<Movie>& movietoday);

int main(){

    srand(time(0));
    int option;
    vector<Movie> movietoday;
    // vector<show> timetoday;
    vector<Ticket> tickettoday;

    addmovie(movietoday);
    
    cout << "*** BOOK MOVIE TICKETS ***\n";
    do{
        cout << "MENU => \n"
        << "1. View Movies\n"
        << "2. Search Tickets\n"
        << "3. Cancel Tickets\n"
        << "4. Exit\n";
        
        cin >> option;
        
        switch(option){
            case 1 : viewmovies(movietoday, tickettoday);
                    break;
            case 2 : searchticket(tickettoday);
                    break;
            case 3 :  cancelticket(tickettoday, movietoday);
                    break;
                    case 4 : cout << "*** ThankYou ***\n";
                    return 0;
            default : cout << "Choose from Options\n";
        }
    
    }while(option != 4);
}

int seatnum(){
    char seatchar;
    int seatnum;
    while(true){
        cin >> seatchar >> seatnum;
        seatchar = toupper(seatchar);

        if(seatnum < 1 || seatnum > 10){
            cout << "Enter valid seat number\n";
            continue;
        }
        switch(seatchar){
            case 'J' : return seatnum + (0-1);
            case 'I' : return seatnum + (10-1);
            case 'H' : return seatnum + (20-1);
            case 'G' : return seatnum + (30-1);
            case 'F' : return seatnum + (40-1);
            case 'E' : return seatnum + (50-1);
            case 'D' : return seatnum + (60-1);
            case 'C' : return seatnum + (70-1);
            case 'B' : return seatnum + (80-1);
            case 'A' : return seatnum + (90-1);
            default : cout << "Enter Valid seat number\n"; 
        }   
    }
}
bool pin(){
    
    string pinnum;
    // cin.ignore();
    
    for(int i=3; i>0; i--){
        cout << "Enter pin : ";
        getline(cin, pinnum);
        if(pinnum.length() == 4){
            bool valid = true;

            for(char x : pinnum){
                if(!isdigit(x)){
                    valid = false;
                    break;
                }
            }
            if(valid)
                return true;
        }
    }
    return false;
}
bool payment(int seats, int price){

    int option;
    string id;
    char yesno;
    cout << "\nAmount :                $ " << seats*price << "   ( " << seats << " * " << price << " )" << endl;
    cout << "Taxes & GST (@18%) :    $ " << 0.18*seats*price << endl << '\n';
    cout << "Total Payable Amount :  $ " << 1.18*seats*price << endl << '\n';
    while(true){
        cout << "Payment options \n"
            << "1. Pay by any UPI app\n"
            << "2. Debit/Credit Card\n"
            << "3. Net Banking\n"
            << "4. Cancel Transaction\n";
            cin >> option;
            cin.ignore();
            switch(option){
                case 1: cout << "Enter UPI ID : ";
                        getline(cin , id);
                        if(pin()) return true;
                        else return false;

                case 2 : cout << "Enter credit/debit card number : ";
                        getline(cin , id);
                        if(pin()) return true;
                        else return false;

 
                case 3 : cout << "Enter Netbanking id : ";
                        getline(cin , id);
                        if(pin()) return true;
                        else return false;

 
                case 4 : cout << "Do you want to cancel the transaction ? (y/n) ";
                        cin >> yesno;
                        if( yesno=='y' || yesno=='Y') return false;
                        else continue;

                default : cout << "Choose from options\n";
            }
        }
    return true;
};
void addmovie( vector<Movie> &movies){

    Movie newmovie1, newmovie2, newmovie3;
    newmovie1.name = "Dilwale Dulhaniya Le Jayenge";
    newmovie1.duration = 3.5;
    newmovie1.imdb = 9.2;

    show s1, s2, s3, s4, s5;

    s1.time = "01:00 PM";
    s1.layout.fillrandom();

    s2.time = "03:30 PM";
    s2.layout.fillrandom();

    s3.time = "06:50 PM";
    s3.layout.fillrandom();

    s4.time = "07:30 PM";
    s4.layout.fillrandom();

    newmovie1.showtime.push_back(s1);
    newmovie1.showtime.push_back(s2);
    newmovie1.showtime.push_back(s3);
    newmovie1.showtime.push_back(s4);

    movies.push_back(newmovie1);

    newmovie2.name = "Koi Mil Gaya";
    newmovie2.duration = 2.5;
    newmovie2.imdb = 8.9;

    s1.time = "12:10 PM";
    s1.layout.fillrandom();

    s2.time = "02:30 PM";
    s2.layout.fillrandom();

    s3.time = "06:100 PM";
    s3.layout.fillrandom();

    s4.time = "08:30 PM";
    s4.layout.fillrandom();

    newmovie2.showtime.push_back(s1);
    newmovie2.showtime.push_back(s2);
    newmovie2.showtime.push_back(s3);
    newmovie2.showtime.push_back(s4);
    
    movies.push_back(newmovie2);

    newmovie3.name = "Chennai Express";
    newmovie3.duration = 2.5;
    newmovie3.imdb = 9.5;

    s1.time = "11:10 AM";
    s1.layout.fillrandom();

    s2.time = "01:55 PM";
    s2.layout.fillrandom();

    s3.time = "04:50 PM";
    s3.layout.fillrandom();

    s4.time = "07:10 PM";
    s4.layout.fillrandom();

    s5.time = "09:10 PM";
    s5.layout.fillrandom();

    newmovie3.showtime.push_back(s1);
    newmovie3.showtime.push_back(s2);
    newmovie3.showtime.push_back(s3);
    newmovie3.showtime.push_back(s4);
    newmovie3.showtime.push_back(s5);
    
    movies.push_back(newmovie3);
    
};  
void showseatnum(int seat){

    if(seat<10){
        cout << "J" << seat+1;
        return;
    }
    if(seat<20){
        cout << "I" << (seat%10)+1;
        return;
    }
    if(seat<30){
        cout << "H" << (seat%20)+1;
        return;
    }
    if(seat<40){
        cout << "G" << (seat%30)+1;
        return;
    }
    if(seat<50){
        cout << "F" << (seat%40)+1;
        return;
    }
    if(seat<60){
        cout << "E" << (seat%50)+1;
        return;
    }
    if(seat<70){
        cout << "D" << (seat%60)+1;
        return;
    }
    if(seat<80){
        cout << "C" << (seat%70)+1;
        return;
    }
    if(seat<90){
        cout << "B" << (seat%80)+1;
        return;
    }
    if(seat<100){
        cout << "A" << (seat%90)+1;
        return;
    }
    
}
void viewmovies( vector<Movie> &movie, vector<Ticket> &tickettoday){

    int option, c, timeoption, numofseats, price;
    // Ticket ticket;
    string phone;
    
    while(true){
        c=1;
        cout << "Choose Movie :=> \n";

        for(int i=0; i<movie.size(); i++){
            cout << c << ". " << movie[i].name << endl;
            c++;
        } 
        cout << c << ". Exit\n";
        
        cin >> option;
        
        if(option == c) return;
        if(option <= 0 || option > c){
            cout << "Choose from options\n";
            continue;
        }
        cout << "****  " << movie[option-1].name << "  ****" << endl;
        cout << "Choose Time slot :=>" << endl;
        for(int i=0; i<movie[option-1].showtime.size(); i++){
            cout << i+1 << ". " << movie[option-1].showtime[i].time << endl;
        }
        cin >> timeoption;

        if(timeoption < 1 || timeoption > movie[option-1].showtime.size()){
            cout << "Invalid show\n";
            continue;
        }

        do{
            cout << "Choose Seat :=> \n\n";
            
            movie[option-1].showtime[timeoption-1].layout.seat();
            
            cout << "Number of Seats to choose? :  ";
            cin >> numofseats;
            
            if(numofseats > movie[option-1].showtime[timeoption-1].layout.numofemptyseats()){
                cout << "Not enough seats available\n";
                continue;
            }

            vector<int> seatnumber(numofseats);
            
            for(int j=0; j<numofseats; j++){
                cout << "Enter seat (A 1) : ";
                seatnumber[j] = seatnum();
                for(int i=0; i<j; i++){
                    if(seatnumber[i] == seatnumber[j]){
                        cout << "Seat Already Selected\n";
                        j--;
                        break;
                    }
                }
                if(movie[option-1].showtime[timeoption-1].layout.filled[seatnumber[j]] == true){
                    cout << "Seat Already booked\nChoose Another Seat\n";
                    j--;
                }
                else if(movie[option-1].showtime[timeoption-1].layout.filled[seatnumber[j]] == false){
                    cout << "Seat Selected\n";
                }
            }
            cout << "Proceeding for payment.... \n";

            Ticket ticket;
            cout << "Name : ";
            cin.ignore();
            getline(cin, ticket.name);
            do{
                cout << "Phone Number : +91 ";
                cin >> phone;
            } while( phone.length() != 10 || !all_of(phone.begin(), phone.end(), ::isdigit));
            ticket.phone = stoll(phone);

            price = movie[option-1].showtime[timeoption-1].layout.price;
            
            while(true){
                
                if(payment(numofseats, price)){
                    for(int i=0; i<numofseats; i++){
                        movie[option-1].showtime[timeoption-1].layout.filled[seatnumber[i]] = true;
                        ticket.seatnumber.push_back(seatnumber[i]);
                    }

                    ticket.numofseats = numofseats;
                    ticket.movietime = movie[option-1].showtime[timeoption-1].time;
                    ticket.moviename = movie[option-1].name;
                    ticket.id = (rand()%(99999999-9999999+1))+9999999;

                    tickettoday.push_back(ticket);
    
                    cout << "** Payment Done **\nTickets Confirmed\n";
                    cout << "~~~~~~~~~~~~~~~~~~~\n"
                        << "Ticket(s) ==> \n"
                        << "Username @" << ticket.name << " has booked tickets for the show \"" << ticket.moviename 
                        << " \" for today @ time " << ticket.movietime 
                        << " in INOX Cinemas, Delhi.  Seat Numbers are ";
                        show_ticket(ticket);
                    cout << "\nBooking ID : " << ticket.id
                        << " ( Please remember the booking id for future use )"
                        << "\nHappy Movie Time !!\n";
                    break;
                }
                else{
                    char back;
                    cout << "!!  The Transaction was cancelled !!\n";
                    cout << "Press 'B' to go back or any key to continue selecting seats ";
                    cin >> back;
                    if(back == 'B' || back == 'b') break;
                    else continue;
                }
            }
            
        }while(false);
        break;
    }

}
void show_ticket( const Ticket &ticket){

    for(int i=0; i<ticket.seatnumber.size(); i++){

        showseatnum(ticket.seatnumber[i]);
       
        if(i != ticket.seatnumber.size()-1)
        cout << ", ";
    }    
};    
void searchticket( const vector<Ticket> &ticket){

    int option, c=-1;
    string username;
    long long num;
    do{
        c=-1;
        cout << "Search ticket by ?\n"
            << "1. Booking ID\n"
            << "2. Username\n"
            << "3. Phone Number\n"
            << "4. Exit\n";
        cin >> option;

        switch(option){
            case 1 : cout << "Enter Booking ID : ";
                    cin >> num;
                    for( int i=0; i<ticket.size(); i++){
                        if( ticket[i].id == num) {
                            c=i;
                            break;
                        }
                    }
                    break;
            case 2 : cout << "Enter Username : ";
                    cin.ignore();
                    getline(cin, username);
                    for( int i=0; i<ticket.size(); i++){
                        if( ticket[i].name == username){
                            c=i;
                            break;
                        }
                    }
                    break;
            case 3 : cout << "Enter Phone Number : ";
                    cin >> num;
                    for( int i=0; i<ticket.size(); i++){
                        if( ticket[i].phone == num) {
                            c=i;
                            break;
                        }
                    }
                    break;
            case 4 : return;

            default : cout << "Choose from given options\n";
                    continue;
        }
        if(c==-1){
            cout << "No booking record found\n";
            continue;
        }
        cout << "~~~~~~~~~~~~~~~~~~~\n"
            << "Ticket(s) ==> \n"
            << "Username @" << ticket[c].name << " has booked tickets for the show \"" << ticket[c].moviename 
            << " \" for today @ time " << ticket[c].movietime 
            << " in INOX Cinemas, Delhi.  Seat Numbers are ";
            show_ticket(ticket[c]);
        cout << "\nBooking ID : " << ticket[c].id
            << " ( Please remember the booking id for future use )"
            << "\nHappy Movie Time !!\n";

    }while(option != 4);

};
void cancelticket(vector<Ticket>& tickettoday, vector<Movie>& movietoday){

    long long bookingid;
    cout << "Enter Booking ID : ";
    cin >> bookingid;

    int c = -1;

    for(int i=0;i<tickettoday.size();i++){
        if(tickettoday[i].id == bookingid){
            c = i;
            break;
        }
    }

    if(c == -1){
        cout << "Booking not found\n";
        return;
    }

    Ticket &ticket = tickettoday[c];

    cout << "\nBooking Found\n";
    cout << "Name : " << ticket.name << endl;
    cout << "Movie : " << ticket.moviename << endl;
    cout << "Time : " << ticket.movietime << endl;
    cout << "Seats : ";
    show_ticket(ticket);
    cout << endl;

    char confirm;

    cout << "Cancel this booking ? (y/n) : ";
    cin >> confirm;

    if(confirm!='Y' && confirm!='y'){
        cout << "Cancellation aborted\n";
        return;
    }

    for(int m=0;m<movietoday.size();m++){

        if(movietoday[m].name != ticket.moviename)
            continue;

        for(int s=0;s<movietoday[m].showtime.size();s++){
            if(movietoday[m].showtime[s].time != ticket.movietime)
                continue;

            for(int seat : ticket.seatnumber){
                movietoday[m]
                    .showtime[s]
                    .layout
                    .filled[seat] = false;
            }
            break;
        }
    }
    tickettoday.erase(tickettoday.begin() + c);

    cout << "\nBooking Cancelled Successfully\n";

    double refund = ( ticket.numofseats * movietoday[0].showtime[0].layout.price );

    cout << "Cancellation charges : $ " << refund*0.1 << "   (10% of seats price)\n";
    cout << "Refund Amount : $ " << refund*0.9 << endl;
}
