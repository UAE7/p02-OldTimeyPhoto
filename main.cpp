#include <iostream>
#include "bitmap.h"
#include <string>
#include <vector>
using namespace std;
 int main ()
  {
  Bitmap image;
  vector <vector <Pixel> > bmp;
  Pixel rgb;
  string fileName;
  bool validBmpFile = false;

  while(!validBmpFile)
  {
  cout << "Enter a file name for converting to old timely image (greyscale): ";
  cin >> fileName;

  image.open(fileName);

  validBmpFile = image.isImage();
  }

  if(validBmpFile)
  {

  bmp = image.toPixelMatrix();

  for(int i = 0; i < bmp.size(); i++)
  {

  vector <Pixel> temp = bmp.at(i);

  for(int j = 0; j < temp.size(); j++)
  {

  rgb = temp.at(j);

  int avg = (int)(rgb.red + rgb.green + rgb.blue) / 3;
  rgb.red = rgb.green = rgb.blue = avg;

  bmp[i][j] = rgb;

  }
  }

  image.fromPixelMatrix(bmp);

  cout << "Saving " << fileName << " as oldtimely.bmp.";
  image.save("oldtimely.bmp");

  }

  return 0;
          }
