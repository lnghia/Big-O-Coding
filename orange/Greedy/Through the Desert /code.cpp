#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<double> pathBetweenGasStations;
    string query = "";
    double stone = 0;
    double consumptionLevel = 0;
    double leaks = 0;
    double consumedFuel = 0;
    double lastStone = 0;
    int i = 0;
    string event = "";

    cout.precision(3);

    while(getline(cin, event)){
        stone = 0;
        i = 0;

        while(i < event.size() && event[i] >= '0' && event[i] <= '9'){
            stone = stone * 10 + (event[i++] - '0');
        }
        ++i;
        query = "";
        while(i < event.size() && !(event[i] >= '0' && event[i] <= '9')){
            query += event[i++];
        }

        consumedFuel += (stone - lastStone) * (consumptionLevel/100 + leaks);

        if(query == "Fuel consumption "){
            consumptionLevel = 0;
            while(i < event.size()){
                consumptionLevel = consumptionLevel * 10 + (event[i++] - '0');
            }
        }
        else if(query == "Leak"){
            ++leaks;
        }
        else if(query == "Gas station"){
            pathBetweenGasStations.push_back(consumedFuel);
            consumedFuel = 0;
        }
        else if(query == "Mechanic"){
            leaks = 0;
        }
        else if(query == "Goal"){
            double ans = consumedFuel;

            for(auto& n : pathBetweenGasStations){
                ans = max(ans, n);
            }
            cout << fixed << ans << '\n';

            stone = 0;
            lastStone = 0;
            consumedFuel = 0;
            leaks = 0;
            consumptionLevel = 0;
            if(pathBetweenGasStations.size()) pathBetweenGasStations.clear();

            continue;
        }
        lastStone = stone;

        if(!consumptionLevel) break;        
    }

    return 0;
}