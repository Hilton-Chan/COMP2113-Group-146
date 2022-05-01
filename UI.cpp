#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;
string upper_left_corner = "\u2554";
string upper_right_corner = "\u2557";
string bottom_left_corner = "\u255A";
string bottom_right_corner = "\u255D";
string horizontal = "\u2550";
string vertical = "\u2551";

string BLACK = "\u25CB";
string WHITE = "\u25CF";

void printTitle(){
  cout << upper_left_corner << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << upper_right_corner << "\n";
  cout << vertical << " OTHELLO " << BLACK << WHITE << vertical << "\n";
  cout << bottom_left_corner << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << horizontal << bottom_right_corner << "\n";
}