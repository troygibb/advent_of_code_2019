#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<vector<string>> str_map;

vector<vector<string>> get_input()
{
  vector<vector<string>> wires;
  ifstream fileInput("./day_3_input.txt");
  string line;
  if (fileInput.is_open())
  {
    int idx = 0;
    while (getline(fileInput, line))
    {
      vector<string> wire;
      stringstream ss(line);
      while (getline(ss, line, ','))
      {
        wire.push_back(line);
      }
      wires.push_back(wire);
    }
  }
  return wires;
}

extern str_map create_wire_map(str_map map, vector<string> directions)
{
  map[0][0] = 'o';
  int current_x = 0;
  int current_y = 0;
  for (int i = 0; i < directions.size(); i += 1)
  {
    string curr = directions[i];
    char direction = curr.at(0);
    int num_steps = stoi(curr.substr(1, curr.size()));
    int iterator = direction == 'U' || direction == 'R' ? 1 : -1;
    for (int step = 0; step < num_steps; step +=iterator)
    {
    }
  }
  return map;
}

// int main()
// {
// vector<vector<string>> file_input = get_input();
// return 0;
// }