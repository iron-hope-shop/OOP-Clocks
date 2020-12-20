/* 
* Chada Tech main file
* @author Brad Jackson
* @description Loops through printing time and user menu.
*/
#include "gettime.h"
using namespace std;

const int NUM_SECONDS = 1;

int main()
{
  int i;
  int option = 0, addedHours = 0, addedMinutes = 0, addedSeconds = 0;
  char answer = 'n';

  while (true)
  {
    // delay for 1 seconds
    for (i = 0; i < NUM_SECONDS; i++)
    {
      usleep(1000 * 1000);
    }
    // clear terminal and print, works on *nix (I am using OSX)
    system("clear");
    cout << "12-Hour Clock" << endl
         << TwelveHour(addedHours, addedMinutes, addedSeconds) << endl
         << endl;
    cout << "24-Hour Clock " << endl
         << TwentyFourHour(addedHours, addedMinutes, addedSeconds) << endl
         << endl;
    cout << "Open menu (Y/N)?" << endl;
    cin >> answer;
    // print menu if user chooses to
    if (answer == 'y' || answer == 'y')
    {
      cout << "1 -- Add One Hour" << endl;
      cout << "2 -- Add One Minute" << endl;
      cout << "3 -- Add One Second" << endl;
      cout << "4 -- Exit Program" << endl;
      cin >> option;
      // options 1-3 increment added values by one
      if (option == 1)
      {
        addedHours += 1;
        // used to avoid printing menu again
        answer = 'n';
      }
      else if (option == 2)
      {
        addedMinutes += 1;
        answer = 'n';
      }
      else if (option == 3)
      {
        addedSeconds += 1;
        answer = 'n';
      }
      else if (option == 4)
      {
        // exits entire program
        break;
      }
    }
  }
  return 0;
}
