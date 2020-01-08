#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string> grid) 
{
    int i,j;int row=grid.size();int col=grid[0].size();int flag;
    if(n%4==0 || n%4==2)
        {
            for(i=0;i<row;i++)
                for(j=0;j<col;j++)
                    grid[i][j]='o';
            return grid;
        }
    else if(n%4==1)
        return grid;
    else
        {
            while(n/2)
            {
            vector <string> grid2;
            for(i=0;i<row;i++)
                for(j=0;j<col;j++)
                    grid2[i][j]=0;
            for(i=0;i<row;i++)
                for(j=0;j<col;j++)
                {
                    if(grid2[i][j]==1)
                        continue;
                    flag=0;
                    if(grid[i][j]=='O')
                        flag=1;
                    grid[i][j]='O';
                    if(flag==1)
                        {
                            if(i!=row-1)
                                {grid[i+1][j]='.';grid2[i+1][j]=1;}
                            if(i!=0)
                                {grid[i-1][j]='.';grid2[i-1][j]=1;}
                            if(j!=col-1)
                                {grid[i][j+1]='.';grid2[i][j+1]=1;}
                            if(j!=0)
                                {grid[i][j-1]='.';grid2[i][j-1]=1;}
                        grid[i][j]='.';grid2[i][j]=1;
                        }
                }
            n=n/2;
            }
        return grid;
        }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
