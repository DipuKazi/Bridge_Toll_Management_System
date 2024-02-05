#include<iostream>
#include<string>
#include<fstream>
using namespace std;

const int size=500;
class tollmanagesys
{
private:
    int buscount=0,bikecount=0,carcount=0,pickupcount=0,allowedtruckcount=0,bannedtruckcount=0,totalvehicle=0,startdate=0;
    int buslongamnt=0,buslocalamnt=0,bikeamnt=0,caramnt=0,pickupamnt=0,truckamnt=0,fineamnt=0,totalbustoll,totalcartoll;
    int totalbiketoll,totalpickuptoll,totaltrucktoll,totalfine,totaltoll=0;
    int bustoll[size],biketoll[size],cartoll[size],pickuptoll[size],trucktoll[size],fine[size];
    float allowedweight[size],bannedweight[size];
    string busname[size],busdrivername[size],buscode[size],bustype[size],bikername[size],bikecode[size],cardrivername[size],carcode[size];
    string pickupdrivername[size],pickupcode[size],truckdrivername[size],truckcode[size],bannedtruckcode[size],date[size];

public:
    void dateentry();
    void showdate();
    //void defaultsettoll();
    void gettoll();
    void showtoll();
    void bus();
    void bike();
    void car();
    void pickup();
    void truck();
    void showreport();
    void totalcollection();
    void tollsave();
    void tollgetfile();

};

void tollmanagesys::dateentry()
{
    string tarikh;
    cout<<"Enter today's date: ";
    cin>>tarikh;
    date[startdate]=tarikh;
    startdate++;
}

void tollmanagesys::showdate()
{
    startdate=0;
    cout<<endl<<"Report for: ";
    cout<<date[startdate];
}

/*void tollmanagesys::defaultsettoll()
{
    buslongamnt=800;
    buslocalamnt=500;
    bikeamnt=400;
    caramnt=500;
    pickupamnt=700;
    truckamnt=1200;
    fineamnt=5000;
}*/

void tollmanagesys::showtoll()
{
    cout<<"Current toll for all vehicles are listed below:"<<endl;
    cout<<"1.Bus: "<<endl<<"  1.Long route bus: "<<buslongamnt<<"Taka"<<endl<<"  2.Local bus: "<<buslocalamnt<<"Taka"<<endl;
    cout<<"2.Bike: "<<bikeamnt<<"Taka"<<endl;
    cout<<"3.Car: "<<caramnt<<"Taka"<<endl;
    cout<<"4.Pickup: "<<pickupamnt<<"Taka"<<endl;
    cout<<"5.Truck: "<<truckamnt<<"Taka"<<endl;
    cout<<"6.Fine :"<<fineamnt<<"Taka"<<endl;
}

void tollmanagesys::gettoll()
{
    int check,check2,check3;
    check3=0;
    do
    {
    showtoll();
    cout<<"Enter 0 to return to main menu"<<endl;
    cout<<endl<<"Enter the number of the vehicle to change the toll amount: ";
    cin>>check;
    switch(check)
    {
    case 1:
        {
        cout<<"1.Long route bus: "<<buslongamnt<<"Taka"<<endl;
        cout<<"2.Local bus :"<<buslocalamnt<<"Taka"<<endl;
        cout<<"Enter your option: ";
        cin>>check2;
        switch(check2)
        {
        case 1:
            {
                cout<<"Enter the new toll amount for long route bus: ";
                cin>>buslongamnt;
                tollsave();
                break;
            }
        case 2:
            {
                cout<<"Enter the new toll amount for local bus: ";
                cin>>buslocalamnt;
                tollsave();
                break;
            }
        }
        break;
        }
    case 2:
        {
            cout<<"Enter the new toll amount for bike: ";
                cin>>bikeamnt;
                tollsave();
                break;
        }
    case 3:
        {
            cout<<"Enter the new toll amount for car: ";
                cin>>caramnt;
                tollsave();
                break;
        }
    case 4:
        {
            cout<<"Enter the new toll amount for pickup: ";
                cin>>pickupamnt;
                tollsave();
                break;
        }
    case 5:
        {
            cout<<"Enter the new toll amount for truck: ";
                cin>>truckamnt;
                tollsave();
                break;
        }
    case 6:
        {
            cout<<"Enter the new fine amount: ";
                cin>>fineamnt;
                tollsave();
                break;
        }
    case 0:
        {
            check3++;
            break;
        }
    }
    }
    while(check3==0);
    tollsave();
}

void tollmanagesys::bus()
{
    string name,code,driver;
    int check,correction;
    cout<<endl<<"Enter Bus name: ";
    cin>>name;
    busname[buscount]=name;
    cout<<"Enter Bus driver name: ";
    cin>>driver;
    busdrivername[buscount]=driver;
    cout<<"Enter Bus code: ";
    cin>>code;
    buscode[buscount]=code;
    jump:
    cout<<endl<<"Enter 1 for long route or 2 for local: ";
    cin>>check;
    if(check==1)
    {
        cout<<endl<<"Toll for long route bus is "<<buslongamnt<<"TAKA";
        cout<<endl<<"For collecting the toll press 1";
        cout<<endl<<"For correction press 0"<<endl;
        cout<<"Enter your option: ";
        cin>>correction;
        if(correction==1)
        {
            bustoll[buscount]=buslongamnt;
            bustype[buscount]="Long route bus";
            buscount++;
            totalvehicle++;
            cout<<endl;
        }
        else
        {
            goto jump;
        }
    }
    else if(check==2)
    {
        cout<<endl<<"Toll for local bus is "<<buslocalamnt<<"TAKA";
        cout<<endl<<"For collecting the toll press 1";
        cout<<endl<<"For correction press 0"<<endl;
        cout<<"Enter your option: ";
        cin>>correction;
        if(correction==1)
        {
            bustoll[buscount]=buslocalamnt;
            bustype[buscount]="Local bus";
            buscount++;
            totalvehicle++;
            cout<<endl;
        }
        else
        {
            goto jump;
        }
    }
    else
    {
        cout<<"Wrong input"<<endl;
        goto jump;
    }
}

void tollmanagesys::bike()
{
    int timer;
    string name,code;
    cout<<"Enter bike rider's name: ";
    cin>>name;
    bikername[bikecount]=name;
    cout<<"Enter bike code: ";
    cin>>code;
    bikecode[bikecount]=code;
    cout<<"Toll for this bike is: "<<bikeamnt<<"TAKA\nEnter 1 to collect it: ";
    cin>>timer;
    biketoll[bikecount]=bikeamnt;
    bikecount++;
    totalvehicle++;
    cout<<endl;
}

void tollmanagesys::car()
{
    int timer;
    string driver,code;
    cout<<"Enter car driver name: ";
    cin>>driver;
    cout<<"Enter car code: ";
    cin>>code;
    cardrivername[carcount]=driver;
    carcode[carcount]=code;
    cout<<"Toll for this car is "<<caramnt<<"TAKA\nEnter 1 to collect it: ";
    cin>>timer;
    cartoll[carcount]=caramnt;
    carcount++;
    totalvehicle++;
}

void tollmanagesys::pickup()
{
    int timer;
    string driver,code;
    cout<<"Enter pickup driver name: ";
    cin>>driver;
    cout<<"Enter pickup code: ";
    cin>>code;
    pickupdrivername[pickupcount]=driver;
    pickupcode[pickupcount]=code;
    cout<<"Toll for this pickup is "<<pickupamnt<<"TAKA\nEnter 1 to collect it: ";
    cin>>timer;
    pickuptoll[pickupcount]=pickupamnt;
    pickupcount++;
    totalvehicle++;
}

void tollmanagesys::truck()
{
    int timer;
    float weight;
    string driver,code,unit;
    cout<<"Enter truck driver name: ";
    cin>>driver;
    cout<<"Enter truck code: ";
    cin>>code;
    cout<<"Enter the truck's weight in TON: ";
    cin>>weight;
    if(weight<=40)
    {
        cout<<"Toll of this truck is "<<truckamnt<<"TAKA";
        cout<<endl<<"Enter 1 to collect it: ";
        cin>>timer;
        trucktoll[allowedtruckcount]=truckamnt;
        truckcode[allowedtruckcount]=code;
        allowedweight[allowedtruckcount]=weight;
        allowedtruckcount++;
        totalvehicle++;
    }
    else
    {
        cout<<"The truck is overweight";
        cout<<endl<<"The fine is "<<fineamnt<<"TAKA";
        cout<<endl<<"Enter 1 to collect the fine: ";
        cin>>timer;
        bannedtruckcode[bannedtruckcount]=code;
        fine[bannedtruckcount]=fineamnt;
        bannedweight[bannedtruckcount]=weight;
        bannedtruckcount++;
    }
}

void tollmanagesys::showreport()
{
    int i;
    totalbiketoll=totalbustoll=totalcartoll=totalpickuptoll=totaltrucktoll=totalfine=0;
    showdate();
    cout<<endl<<endl<<"Individual Bus report:"<<endl;
    if(buscount>0)
    {
        cout<<endl<<"Today entered busses:"<<endl;
        for(i=0;i<buscount;i++)
        {
            cout<<endl<<"Bus name: "<<busname[i]<<endl;
            cout<<"Bus driver name: "<<busdrivername[i]<<endl;
            cout<<"Bus code: "<<buscode[i]<<endl;
            cout<<"Bus type: "<<bustype[i]<<endl;
            cout<<"Received toll from the bus: "<<bustoll[i]<<"Taka"<<endl;
        }
    }
    else
    {
        cout<<"No Bus entered today"<<endl;
    }
    cout<<endl<<"Individual Bike report:"<<endl;
    if(bikecount>0)
    {
        cout<<endl<<"Today entered bikes:"<<endl;
        for(i=0;i<bikecount;i++)
        {
            cout<<endl<<"Biker name: "<<bikername[i]<<endl;
            cout<<"Bike code: "<<bikecode[i]<<endl;
            cout<<"Received toll from the bike: "<<biketoll[i]<<"Taka"<<endl;
        }
    }
    else
    {
        cout<<"No Bike entered today"<<endl;
    }
    cout<<endl<<"Individual Car report:"<<endl;
    if(carcount>0)
    {
        cout<<endl<<"Today entered cars:"<<endl;
        for(i=0;i<carcount;i++)
        {
            cout<<endl<<"Car driver name: "<<cardrivername[i]<<endl;
            cout<<"Car code: "<<carcode[i]<<endl;
            cout<<"Received toll from the car: "<<cartoll[i]<<"Taka"<<endl;
        }
    }
    else
    {
        cout<<"No Car entered today"<<endl;
    }
    cout<<endl<<"Individual pickup report:"<<endl;
    if(pickupcount>0)
    {
        cout<<endl<<"Today entered pickups:"<<endl;
        for(i=0;i<pickupcount;i++)
        {
            cout<<endl<<"Pickup driver name: "<<pickupdrivername[i]<<endl;
            cout<<"Pickup code: "<<pickupcode[i]<<endl;
            cout<<"Received toll from the pickup: "<<pickuptoll[i]<<"Taka"<<endl;
        }
    }
    else
    {
        cout<<"No Pickup entered today"<<endl;
    }
    cout<<endl<<"Individual Truck report:"<<endl;
    if(allowedtruckcount>0)
    {
        cout<<endl<<"Today entered trucks:"<<endl;
        for(i=0;i<allowedtruckcount;i++)
        {
            cout<<endl<<"Truck driver name: "<<truckdrivername[i]<<endl;
            cout<<"Truck code: "<<truckcode[i]<<endl;
            cout<<"Truck's weight: "<<allowedweight[i]<<"Ton"<<endl;
            cout<<"Received toll from the truck: "<<trucktoll[i]<<"Taka"<<endl;
        }
    }
    else
    {
        cout<<"No Truck entered today"<<endl;
    }
    cout<<endl<<"Individual Banned Truck report:"<<endl;
    if(bannedtruckcount>0)
    {
        cout<<endl<<"Today banned trucks:"<<endl;
        for(i=0;i<bannedtruckcount;i++)
        {
            cout<<endl<<"Truck code: "<<bannedtruckcode[i]<<endl;
            cout<<"Truck's weight: "<<bannedweight[i]<<"Ton"<<endl;
            cout<<"Received fine from the truck: "<<fine[i]<<"Taka"<<endl;
        }
    }
    else
    {
        cout<<"No Banned Truck found today"<<endl;
    }
    cout<<"\n\n\n";
    showdate();
    cout<<"\n\nBus report:"<<endl;
    if(buscount==0)
    {
        cout<<"No bus entered today"<<endl;
    }
    else
    {
        cout<<"Total entered Busses: "<<buscount<<endl;
        for(i=0;i<buscount;i++)
        {
            totalbustoll=totalbustoll+bustoll[i];
        }
        cout<<"Total toll collected from Busses: "<<totalbustoll<<endl;
    }
    cout<<endl<<"Bike report:"<<endl;
    if(bikecount==0)
    {
        cout<<"No bike entered today"<<endl;
    }
    else
    {
        cout<<"Total entered Bikes: "<<bikecount<<endl;
        for(i=0;i<bikecount;i++)
        {
            totalbiketoll=totalbiketoll+biketoll[i];
        }
        cout<<"Total toll collected from Bikes: "<<totalbiketoll<<endl;
    }
    cout<<endl<<"Car report:"<<endl;
    if(carcount==0)
    {
        cout<<"No car entered today"<<endl;
    }
    else
    {
        cout<<"Total entered Cars: "<<carcount<<endl;
        for(i=0;i<carcount;i++)
        {
            totalcartoll=totalcartoll+cartoll[i];
        }
        cout<<"Total toll collected from Cars: "<<totalcartoll<<endl;
    }
    cout<<endl<<"Pickup report:"<<endl;
    if(pickupcount==0)
    {
        cout<<"No pickup entered today"<<endl;
    }
    else
    {
        cout<<"Total entered pickups: "<<pickupcount<<endl;
        for(i=0;i<pickupcount;i++)
        {
            totalpickuptoll=totalpickuptoll+pickuptoll[i];
        }
        cout<<"Total toll collected from Pickups: "<<totalpickuptoll<<endl;
    }
    cout<<endl<<"Truck report:"<<endl;
    if(allowedtruckcount==0)
    {
        cout<<"No truck entered today"<<endl;
    }
    else
    {
        cout<<"Total entered trucks: "<<allowedtruckcount<<endl;
        for(i=0;i<allowedtruckcount;i++)
        {
            totaltrucktoll=totaltrucktoll+trucktoll[i];
        }
        cout<<"Total toll collected from Trucks: "<<totaltrucktoll<<endl;
    }
    cout<<endl<<"Banned Truck report:"<<endl;
    if(bannedtruckcount==0)
    {
        cout<<"No banned truck found today"<<endl;
    }
    else
    {
        cout<<"Total banned trucks: "<<bannedtruckcount<<endl;
        for(i=0;i<bannedtruckcount;i++)
        {
            totalfine=totalfine+fine[i];
        }
        cout<<"Total fine collected: "<<totalfine<<endl;
    }
    cout<<endl<<"Total Vehicles report:"<<endl;
    if(totalvehicle==0)
    {
        cout<<"No vehicle entered today"<<endl;
    }
    else
    {
        cout<<"Total entered vehicles: "<<totalvehicle<<endl;
    }
}

void tollmanagesys::totalcollection()
{
    int i;
    totalbiketoll=totalbustoll=totalcartoll=totalpickuptoll=totaltrucktoll=totalfine=totaltoll=0;
    if(buscount>0)
    {
        for(i=0;i<buscount;i++)
        {
            totalbustoll=totalbustoll+bustoll[i];
        }
    }
    if(bikecount>0)
    {
        for(i=0;i<bikecount;i++)
        {
            totalbiketoll=totalbiketoll+biketoll[i];
        }
    }
    if(carcount>0)
    {
        for(i=0;i<carcount;i++)
        {
            totalcartoll=totalcartoll+cartoll[i];
        }
    }
    if(pickupcount>0)
    {
        for(i=0;i<pickupcount;i++)
        {
            totalpickuptoll=totalpickuptoll+pickuptoll[i];
        }
    }
    if(allowedtruckcount>0)
    {
        for(i=0;i<allowedtruckcount;i++)
        {
            totaltrucktoll=totaltrucktoll+trucktoll[i];
        }
    }
    if(bannedtruckcount>0)
    {
        for(i=0;i<bannedtruckcount;i++)
        {
            totalfine=totalfine+fine[i];
        }
    }
    totaltoll=totalbustoll+totalbiketoll+totalcartoll+totalpickuptoll+totaltrucktoll+totalfine;
    cout<<endl<<"Total toll collection of today is: "<<totaltoll<<endl;
}

void tollmanagesys::tollsave()
{
    ofstream tollout("toll amounts of vehicles.txt");
    tollout<<buslongamnt<<endl;
    tollout<<buslocalamnt<<endl;
    tollout<<bikeamnt<<endl;
    tollout<<caramnt<<endl;
    tollout<<pickupamnt<<endl;
    tollout<<truckamnt<<endl;
    tollout<<fineamnt;
    tollout.close();
}

void tollmanagesys::tollgetfile()
{
    ifstream tollget("toll amounts of vehicles.txt");
    tollget>>buslongamnt;
    tollget>>buslocalamnt;
    tollget>>bikeamnt;
    tollget>>caramnt;
    tollget>>pickupamnt;
    tollget>>truckamnt;
    tollget>>fineamnt;
    tollget.close();
}

int main()
{
    int check,check2;
    tollmanagesys padma;
    do
    {
        cout<<endl<<"Bridge Toll Collection System"<<endl;
        padma.dateentry();
        //padma.defaultsettoll();
        padma.tollgetfile();
        jump:
        cout<<endl<<"Enter 1 for Toll collection";
        cout<<endl<<"Enter 2 for see the report";
        cout<<endl<<"Enter 3 for checking the toll amounts";
        cout<<endl<<"Enter 4 for changing the toll amounts";
        cout<<endl<<"Enter 5 for today's total toll collections";
        cout<<endl<<"Enter 0 to exit the program";
        cout<<endl<<"Enter your option: ";
        cin>>check;
        switch(check)
        {
        case 1:
            do
            {
            cout<<endl<<"TOLL COLLECTION"<<endl;
            cout<<"Enter 1 for Bus"<<endl;
            cout<<"Enter 2 for Bike"<<endl;
            cout<<"Enter 3 for Car"<<endl;
            cout<<"Enter 4 for Pickup"<<endl;
            cout<<"Enter 5 for Truck"<<endl;
            cout<<"Enter 0 for quit Toll collection"<<endl;
            cout<<"Enter your option: ";
            cin>>check2;
            switch(check2)
            {
            case 1:
                padma.bus();
                break;
            case 2:
                padma.bike();
                break;
            case 3:
                padma.car();
                break;
            case 4:
                padma.pickup();
                break;
            case 5:
                padma.truck();
                break;
            case 0:
                goto jump;
            }
            }
            while(check2!=0);

        case 2:
                padma.showreport();
                cout<<endl;
                goto jump;
                break;

        case 3:
                padma.showtoll();
                cout<<endl;
                goto jump;
        case 4:
                padma.gettoll();
                cout<<endl;
                goto jump;
        case 5:
                padma.totalcollection();
                cout<<endl;
                goto jump;
        case 0:
            return 0;
        }
    }
    while(1);
    return 0;
}
