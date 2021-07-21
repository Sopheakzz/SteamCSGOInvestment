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
    void item_info (string name); 
    void clearstats () ;
	void todayprice () ; 
    string return_name ();
	
private:
    string name ;
	string itemURL;
	double initial_price = 0; 
	double today_price = 0; 
	double profit = 0 ;
	double profitpercentage = 0 ; 
	int amount = 0 ; 
	double pricetotal = 0 ; 
};
class InvestmentStorage {
public :
	 void deposititem (Item a) ; 
	 void checkitemstats (string itemname);
	 void totalworth ();
	 void listallitems ();
private: 
    vector <Item> Database ; 
	double networth = 0 ; 
    
	
};

int main (){

    return 0 ;
};

void Item::get_info (string itemname , double initprice , int quanity){
	name = itemname ; 
	initprice = initial_price ; 
	amount = quanity ;
	string urltmp ; 
	string nametmp ; 
	CURLcode res;
	string readBuffer;
	stringstream ss; 
	string tmp;
	const char * tmp2  = name.c_str() ; 
	CURL *curl = curl_easy_init();
if(curl) {
	char *output = curl_easy_escape(curl,tmp2,0);
	urltmp = url ; 
	nametmp = output ; 
	urltmp.insert(65 , nametmp) ;
	itemURL = urltmp ;
    curl_free(output) ;
};
if (curl) {  
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_URL, itemURL.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
     };

	if (readBuffer.size() > 0) {
		for (int i = 33; i < 45; i++)
			if (isdigit(readBuffer[i]) || readBuffer[i] == 46)
				tmp += readBuffer[i];
	}
	ss << tmp;
	ss >> today_price; 
    
};

void Item::clearstats(){
     string name = "";
	string itemURL = "";
	double initial_price = 0; 
	double today_price = 0; 
	double profit = 0 ;
	double profitpercentage = 0 ; 
	int amount = 0 ; 
	double pricetotal = 0 ; 
};
void InvestmentStorage::deposititem (Item a){
	Database.push_back(a) ; 
}
void InvestmentStorage::checkitemstats(string itemname) {
    for (int i = 0  ; i < Database.size() ; i++){
		 if (Database[i].return_name == itemname){

		 }
	}
}

string Item::return_name (){
	return name; 	
}; 
void Item::get_info (string name){
	cout << " Name : " << name <<endl  ; 
	cout << " "
}