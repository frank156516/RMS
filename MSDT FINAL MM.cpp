//**************Headder directories*****************

#include<conio.h>
#include<stdio.h>
#include<string>
#include<iostream>
#include<assert.h>
using namespace std;
const MAX_DISHES=100;

/*This programme is a RESTAURENT MANAGEMENT SYSTEM which manages all the operations of a real time
  restaurent. It handles all oprations like placing order , calculating the total bill , etc.
  It also keeps track of the costomers.
  It gives access to modify the menu.
  The customers can see the dishes they orders and they can modify their order.
  All this is implemented according to the protocal learnt in MODERN SOFTWARE DEVELOPEMENT TECHNIQUES.
  This Programme is written by Gautam, Count , Casandra.
*/

class Introduction //Class for Displaying to the user interface.
{
	public:

	void MainIntroduction()
	{
		cout<<"THIS IS A RESTAURENT MANAGEMENT SYSTEM";
	}

	void MenuIntroduction()
	{
		cout<<"\n***********************MENU**************************\n";
	}

	void DisplayOptions()
	{
		cout<<"\nEnter one option\n";
		cout<<"\n1.Display Menu \n2.Edit Menu \n3.Take Order \n4.Order Summary \n5.Total Price \n6.Exit";

	}



};


class dish  //Dishes in the Menu are handled here.
{

	string Name;
	int Price;
	bool Availabality;

	public:

		void Modify() //Modify the Dishes in the Menu.
		{
			cout<<"\n Enter the name of the new dish:";
			cin>>Name;
			cout<<"\n Enter the price of the new dish:";
			cin>>Price;

		}

		void Get()
		{
		    cout<<"\n Enter the dish name:";
		    cin>>Name;
		    cout<<"\n Enter the dish price:";
		    cin>>Price;
		}

		void Availability(bool temp)
		{
		    Availabality = temp;
		}

		void Display()
		{
		    cout<<"\n Name : "<<Name<<"  Price : "<<Price;
		}

		char Name()
		{
		    return(Name);
		}

		int Price()
		{
		    return(Price);
		}


};


class menu:public Introduction  //Main Menu class dealing with the dishes in the menu.
{
	int NumbofDishes;
	dish Menu[MAX_DISHES];
	int repeat = 0;
    int Option;
    int MenuLength = 0;
    int MenuCount = 0;

	public:

    void GetMenu()
    {
        bool Temp = true;
        int option;
        while(Temp)
        {
            cout<<"\n 1.Add Dish";
            cout<<"\n 2.Exit";
            cin>>option;
            switch(option)
            {
            case 1:
                Menu[MenuLength].Get();
                MenuLength += 1;
                break;
            case 2:
                Temp = false;
                break;
            default:
                cout<<"\n Invalid Choice \n Please Enter a Valid Option";
                break;
            }
        }
    }


	void ModifyMenu() //Edit items on the menu.
	{
		cout<<"\n Enter the dish no to modify";
		cin>>DishNumber;
		Menu[DishNumber].Modify();

	}

	void AddDish()
	{
	   cout<<"\n Enter the dish Details";
	   MenuLength += 1;
	   Menu[MenuLength].Get();
	}


	void DisplayMenu()  // Prints the dishes in the menu class.
	{
		MainIntroduction();
		for(int i = 0;i < MenuLength; i++)
        {
            cout<<i+1<<"."<<Menu[MenuLength].Name<<"    "<<Menu[MenuLength].Price<<endl;
        }

	}
};

class Order:private menu  // This class deals with the orders make by the customers.
{
	int QuantityOfDish;
	int OrderDishNo[100][2]; // array to store the dishes ordered.
	int NoOfDishes;        // the number of dishes the customer orderes.
	int Ordersize;         // Used in the for loop as a counter.

	public:

	void TakeOrder() // saves the Dish no. of the dishes the customres order.
	{
	    bool temp;
	    int temp1;
		while(temp)
        {
            Ordersize += 1;
            cout<<"\n Enter the Dish number ";
            cin>>temp1;
            OrderDishNo[Ordersize-1][0] = temp1;
            cout<<"\n Enter the Dish Quantity ";
            cin>>temp2;
            OrderDishNo[Ordersize-1][1] = temp1;
        }
	}



	void OrderSummary()  //Prints the dishes the customer ordered.
	{
		cout<<"\n Your Order :";
		for(int i = 0;i<Ordersize;i++)
		{
			cout<<OrderDishNo[i][1]<<" of "<<menu[OrderDishNo[i-1][0]].Name<<endl;
		}

	}
};


class Bill:private Order // genarates a bill with totalprice,taxes,bill amoumt.
{

    int OrderAmount = 0;
    float Taxes;
    float TotalAmount;


	public:


		void BillAmount()  // Calculates the total price of the dishes ordered.
		{
		    for(int i = 0;i<Ordersize;i++)
		    OrderAmount += menu[OrderDishNo[i-1][0]].Price * OrderDishNo[i][1];
		}


		void Taxes()  // Calculates the taxes for the BillAmount.
		{
		    Taxes = (float)OrderAmount * 14.5;
		}


		void TotalPrice()  //  Calculates the total price after suming with the Taxes.
		{
		    TotalPrice = (float)OrderAmount + Taxes;
		}



};


int main()
{
	int RepeatMainOptions=1;
	int MainDisplayOption;
	Introduction Intro1;
	Bill MainBill;
	menu Mainmenu;
	Order MainOrder;
	Intro1.MainIntroduction();
	Intro1.DisplayOptions();
    cin>>MainDisplayOption;

    do
    {


    switch(MainDisplayOption)
    {
    	case 1:

    		Mainmenu.DisplayMenu();
    		break;

    	case 2:

    		Mainmenu.ModifyMenu();
    		break;

    	case 3:
    		MainOrder.TakeOrder();
    		break;

    	case 4:
    		MainOrder.OrderSummary();
    		break;

    	case 5:
    		MainBill.TotalPrice();
    		break;

    	case 6:

    		RepeatMainOptions=0;
    		break;


    	default:

    		assert (MainDisplayOption>)


	};

    }while(RepeatMainOptions);

	getch();

}
