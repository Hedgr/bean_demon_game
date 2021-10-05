#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>

using namespace std;

int money = 0;

int bean_demons = 0;

int D_class = 0;

int vehichle_player = 1;

string version = "0.93";

int show_debug = 1;

string action = "";

string buy_thing = "";

bool first_time_main = true;

//============================= UPGRADES ===================================
int truck_level = 0;


int display_version(string x, int debug) {
    if (debug == 1)
    {
        cout << "[display_version] called\n";
    }
    cout << "version "  << version << "\n";
    first_time_main = false;
    return 0;
}

int display_starting_instructions(int debug) {
    if (debug == 1)
    {
        cout << "[display_starting_instructions] called\n";
    }
    cout << "type in 'abduct' to abduct something\ntype in 'sell' to sell the stuff you have abducted\n";
    cout << "type in 'shop' to buy upgrades\ntype in 'help' to see this again\n(also you can type in 1 for 'abduct', 2 for 'sell', 3 for 'shop' ";
    cout << "and 4 for 'help')\n";
    return 0;
}

int get_next_action(int debug)   {
    if (debug == 1)
    {
        cout << "[get_next_action] called\n";
    }
    cin >> action;
    return 0;
}

int shop(int debug) {
    if (debug == 1)
    {
        cout << "[shop] called\n";
    }
    cout << "type in the number next to the upgrade text (if there is a number) to upgrade it\n";
    if (truck_level == 5)
    {
        cout << "your truck is upgraded to the max level\n";
    }
    else
    {
        if (truck_level == 0)
        {
            cout << "1. your truck has not been leveled up";
        }
        else
        {
            cout << "1. your truck is level" << truck_level;
        }
    }
    switch (truck_level)
    {
    case 4: cout << "   level up for 10000$\n";
    case 3: cout << "   level up for 5500$\n";
    case 2: cout << "   level up for 2000$\n";
    case 1: cout << "   level up for 750$\n";
    }
    do
    {
        cin >> buy_thing;
    } while (buy_thing != "1");

    return 0;
}

int sell_stuff(int debug) {
    if (debug == 1)
    {
        cout << "[sell_stuff] called\n";
    }
    money = (money + (bean_demons * 10));
    cout << "you now have " << money << " money\n";
    return 0;
}

int kidnap_bean_demons(int level, int debug) {
    if (debug == 1)
    {
        cout << "[kidnap_bean_demons] called\n";
    }
    bean_demons = (bean_demons + (level + truck_level));
    cout << "you now have " << bean_demons << " bean demons\n";
    return 0;
}

int do_next_action(string action, int debug) {
    if (debug == 1)
    {
        cout << "[do_next_action] called\n";
    }
    if (action == "abduct" || action == "1")
    {
        string x = "";
        cout << "what do you want to abduct: (type in the number)\n1. bean demons\n";
        do {
            cin >> x;
        } while (x != "1");
        stringstream y;
        y << x;
        int z = 0;
        y >> z;
        switch (z)
        {
        case 1: kidnap_bean_demons(vehichle_player, show_debug);
        }
    }
    if (action == "sell" || action == "2")
    {
        sell_stuff(show_debug);
    }
    
    return 0;
}

int main()
{
    if (show_debug == 1)
    {
        cout << "[main] called\n";
    }
    do {
        if (first_time_main == true) {
            display_version(version, show_debug);
        }
        display_starting_instructions(show_debug);
        get_next_action(show_debug);
        do_next_action(action, show_debug);
    } while (true);
    return 0;
}
