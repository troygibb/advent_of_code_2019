
#include <iostream>
#include <fstream>
#include <string>
#include <math.h> /* floor */

using namespace std;

/*
At the first Go / No Go poll, every Elf is Go until the Fuel Counter-Upper.
They haven't determined the amount of fuel required yet.

Fuel required to launch a given module is based on its mass. Specifically, to
find the fuel required for a module, take its mass, divide by three, round
down, and subtract 2.

For example:

For a mass of 12, divide by 3 and round down to get 4, then subtract 2 to get
2. For a mass of 14, dividing by 3 and rounding down still yields 4, so the
fuel required is also 2. For a mass of 1969, the fuel required is 654. For a
mass of 100756, the fuel required is 33583. The Fuel Counter-Upper needs to
know the total fuel requirement. To find it, individually calculate the fuel
needed for the mass of each module (your puzzle input), then add together all
the fuel values.

What is the sum of the fuel requirements for all of the modules on your
spacecraft?

*/

int main()
{
  string line;
  float sum = 0.0;
  ifstream myfile("./day_1_input.txt");
  if (myfile.is_open())
  {
    while (getline(myfile, line))
    {
      float new_mass = stof(line);
      while (new_mass > 0)
      {
        float zero = 0.0;
        new_mass = max(floor(new_mass / 3) - 2, zero);
        sum += new_mass;
        cout << "finished";
      }
    }
    myfile.close();
  }

  else
    cout << "Unable to open file";

  cout << fixed << sum;
  return 0;
}
