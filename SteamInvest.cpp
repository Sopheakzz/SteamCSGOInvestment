#include <iostream>
#include <curl/curl.h>
#include <vector>
#include <string> 
#include <sstream> 
#include <iomanip>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std; 

string url = "http://steamcommunity.com/market/priceoverview/?market_hash_name=&appid=730&currency=1";

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

class Item {
    public : 
    void get_info (string itemname , double initprice , int quanity ) ;
    
       
    private:
    string name;
	string itemURL;
	double initial_price = 0; 
	double today_price = 0; 
	double profit = 0 ;
	int amount = 0 ; 
}

int main (){
    cout 
    return 0 ;
}

 
