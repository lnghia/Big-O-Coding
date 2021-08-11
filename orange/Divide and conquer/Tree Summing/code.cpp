#include <bits/stdc++.h>

using namespace std;

int main(){
  	ios::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
  
    stack<int> vals;
    int k;
    string line = "", tmp = "", str_ans = "", tree = "";
    int ans = 0;
    int null_count = 0;
    int sum = 0;
  	bool open = 0;
  	bool temp = 0;
  	bool isNegative = 0;

    while(getline(cin, line)){
        int ind = 0;
      
      	if(line == "") continue;

      	if(!temp){
        		if((((line[ind] >= '0' && line[ind] <= '9') || line[ind] == '-') && vals.empty())){
            		k = 0;
              	isNegative = (line[ind] == '-');
            }
          	ind += isNegative;
        		while((((line[ind] >= '0' && line[ind] <= '9') || line[ind] == '-') && vals.empty())){
            		k = k * 10 + (line[ind] - '0');
            		++ind;

            		ans = 0;
            		null_count = 0;
            		sum = 0;
          			str_ans = "";
          			open = 0;
          			temp = 1;
        		}
          	if(isNegative){
            		isNegative = 0;
              	k *= -1;
            }
        }
      	
      	//cout << k << '\n';

        for(int i = ind; i < line.length(); ++i){
          	if(!isNegative) isNegative = (line[i] == '-');
          
            if(line[i] == '('){
                open = 1;
            }
            else if(line[i] >= '0' && line[i] <= '9'){
                int num = 0;
                int j = i;

                null_count = 0;
                while(line[j] >= '0' && line[j] <= '9' && j < line.length()){
                    num = num * 10 + (line[j] - '0');
                    ++j;
                }
              
              	if(isNegative){
                		num *= -1;
                  	isNegative = 0;
                }
              
              	//cout << num << '\n';

                if(open){
                    vals.push(num);
                    sum += num;
                }
                i = j - 1;

                open = 0;
            }
            else if(line[i] == ')'){
                if(open){
                    ++null_count;
                    if(null_count > 1){
                        ans += (sum == k);
                    }
                    open = 0;
                }
                else{
                    sum -= vals.top();
                    vals.pop();
                }
              	temp = !vals.empty();
            }
        }

      	if(vals.empty() && !temp){
         		cout << ((ans) ? "yes" : "no") << '\n';
        }
    }

    return 0;
}