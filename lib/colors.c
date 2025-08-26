#include "../include/colors.h"
const Color darkGrey = {26, 31, 45, 255};
const Color green = {42, 225, 21, 255};
const Color red = {230, 20, 23, 255};
const Color orange = {220, 119, 19, 255};
const Color yellow = {239, 238, 5, 255};
const Color purple = {170, 2, 249, 255};
const Color cyan = {25, 207, 210, 255};
const Color blue = {13, 69, 218, 255};
const Color *getColors(void) {
  static Color colours[8]; // i think this is troll but, whatever
  static int initialized = 0;

  if (!initialized) {
    colours[0] = darkGrey;
    colours[1] = green;
    colours[2] = red;
    colours[3] = orange;
    colours[4] = yellow;
    colours[5] = purple;
    colours[6] = cyan;
    colours[7] = blue;
    initialized = 1;
  }

  return colours;
}
