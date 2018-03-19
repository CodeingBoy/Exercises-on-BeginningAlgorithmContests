// Example 5-6 Team Queue
// UVa 540
// Language: C++

#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main(){
    int kase = 1;

    while(true){
        int team_count;
        cin >> team_count;
        if(team_count == 0){
            break;
        }

        map<int, int> member_dict;
        /* vector<int> teams[team_count]; */
        for(int i = 0;i < team_count;i++){
            int team_id = i;
            /* vector<int> &team = teams[i]; */

            int member_count;
            cin >> member_count;

            while(member_count--){
                int member_id;
                cin >> member_id;
                /* team.push_back(member_id); */
                member_dict[member_id] = team_id;
            }
        }

        queue<int> queues;
        queue<int> member_queues[team_count];
        bool queued[team_count] = {false};

        cout << "Scenario #" << kase << endl;
        while(true){
            string command;
            cin >> command;
            if(command[0] == 'S'){
                break;
            }

            char c = command[0];
            switch(c){
                case 'E':
                    {
                        int member_id;
                        cin >> member_id;

                        int team_id = member_dict[member_id];
                        if(!queued[team_id]){
                            queues.push(team_id);
                            queued[team_id] = true;
                        }
                        member_queues[team_id].push(member_id);

                        break;
                    }
                case 'D':
                    {
#ifdef DEBUG
                        cout << "Dequeue" << endl;
#endif
                        int first_team = queues.front();
                        while(member_queues[first_team].empty()){
                            queues.pop();
                            queued[first_team] = false;
                            first_team = queues.front();
                        }
                        int member = member_queues[first_team].front();
                        member_queues[first_team].pop();

                        cout << member << endl;

                        break;
                    }
            }
        }

        kase++;
        cout << endl;
    }



    return 0;
}
