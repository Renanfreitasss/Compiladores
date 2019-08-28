#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main () {
  string line;
  vector <string> listaS;
  
  ifstream myfile ("example.txt"); // ifstream = padrão ios:in
  if (myfile.is_open())
  {
    while (! myfile.eof() ) //enquanto end of file for false continua
    {
      getline (myfile,line);
	  	string var_local = ""; 
    	for (int i=0; line[i]!='\0';i++){
    		if (line[i] != ';' && line[i]!= '{'){
    			var_local += line[i];
			}else {
				if(line[i] == ';'){
					var_local += ';';
					listaS.push_back(var_local);
					var_local = "";
				}
				if(line[i]=='{'){
					var_local += '{';
					listaS.push_back(var_local);
					var_local ="";
				}
								
			}
		}
      
    }
    myfile.close();
    	
    for (int i=0; i<listaS.size();i++){
    	cout<<listaS[i]<<endl;
	}
  }

  else cout << "Unable to open file"; 

  return 0;
}
