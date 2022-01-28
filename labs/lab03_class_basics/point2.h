class Point2{
  public:
    Point2 (float _x=0, float _y=0){
      x = _x;
      y = _y;
    }
    float getX(){
      return x;
    }
    float getY(){
      return y;
    }
    float DistanceBetween (Point2 input1);
    int Quadrant ();
    void Print();

  private:
    float x;
    float y;


};
