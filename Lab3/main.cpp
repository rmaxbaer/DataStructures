#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <sstream>
#include <fstream>
#include <iterator>
#include <map>
#include <list>


using namespace std;
int main(int argc, char *argv[]){
    
    
    vector<string> tokens;
    set <string> unique;
    string next_line;  // Each data line
    string filename = argv[1];
    ifstream in(filename);
    
    //This is used for Part 3 and Part 5
    list<string> lst;
    
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
	          tokens.push_back(nopunct);
		        unique.insert(nopunct);
		        lst.push_back(nopunct); // Part 2 calls for a vector; we could use a vector or a list; Note in Part 5 tells us to experiment with other types
		    // cout << token<<endl;
	    }
    }
    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;
    ofstream setfile(filename + "_set.txt");
    for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it){
        
        //cout << ' ' << *it;
        setfile << ' ' << *it;
    }
    cout << endl;
    

    //PART 3
    /*
    map<string, string> wordmap;
    string last="";
    
    for (list<string>::iterator it=lst.begin(); it!=lst.end(); it++) {
      wordmap[last]=*it;
      last = *it;
    }
    
    ofstream mapfile(filename + "_map.txt");
    for(map<string, string>:: iterator it = wordmap.begin(); it != wordmap.end(); ++it){
        mapfile << it->first << ", " << it->second << endl;
    }
    */
    //-----------------------------------------
    
    //PART 4
    /*
    
    string state = "";
    for(int i = 0; i < 100; i++){
        cout << wordmap[state] << " ";
        state = wordmap[state];
    }
    cout << endl;
    */
    //-----------------------------------------
    
    //PART 5
    /*
    
    map<string, vector<string>> wordmap;
    string state = "";
    
    for(list<string>::iterator it=lst.begin(); it !=lst.end(); it++) {
      wordmap[state].push_back(*it);
      state = *it;
      
    }
    
    srand(time(NULL)); // this line initializes the random number generated
                   // so you dont get the same thing every time
    state = "";
    for (int i = 0; i < 100; i++) {
      int ind = rand() % wordmap[state].size();
      cout << wordmap[state][ind] << " ";
      state = wordmap[state][ind];
    }
    cout << endl;
    */
    //-----------------------------------------

    // PART 6
    map<list<string>, vector<string>> wordmap;
    int M = 2;
    list<string> state;
    
    for (int i = 0; i < M; i++) {
       state.push_back("");
    }
                            
    for (list<string>::iterator it=lst.begin(); it!=lst.end(); it++) {
       wordmap[state].push_back(*it);
       state.push_back(*it);
       state.pop_front();
    }

    state.clear();
    for (int i = 0; i < M; i++) {
        state.push_back("");
    }
    for (int i = 0; i < 100; i++) {
       int ind = rand() % wordmap[state].size();
       cout << wordmap[state][ind]<<" ";
       state.push_back(wordmap[state][ind]);
       state.pop_front();
  }
}