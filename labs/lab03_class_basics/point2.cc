#include "point2.h"
#include <iostream>
#include <math.h>

using namespace std;

float Point2::DistanceBetween(Point2 input1) {
  float distance;
  distance = sqrt( pow ((this->x - input1.getX()), 2) + pow(this->y - input1.getY(),2) );
  return distance;

}

int Point2::Quadrant(){
  int result;
  if(this->x == 0 || this->y == 0){
  if (this->x == 0 && this->y == 0){
    result = 0;
  }else if (this->x > 0 && this->y == 0){
    result = 1;
  }else if (this->x == 0 && this->y > 0){
    result = 2;
  }else if (this->x < 0 && this->y == 0 ){
    result = 3;
  }else{
    result = 4;
  }
}else{
  if(this->x > 0 && this->y > 0){
    result = 1;
  }else if(this->x < 0 && this->y > 0){
    result = 2;
  }else if(this->x < 0 && this->y < 0){
    result = 3;
  }else{
    result = 4;
  }
}
  return result;

}

void Point2::Print(){
  cout << this->x << "," << this->y;
}
