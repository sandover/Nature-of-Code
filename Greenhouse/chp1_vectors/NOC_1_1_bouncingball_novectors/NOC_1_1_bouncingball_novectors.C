/* (c)  oblong industries */


#include "Greenhouse.h"

/**

 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman

 Example 1-1: Bouncing Ball, no vectors
 Using a Box for now to keep drawing simple.

**/


struct MovingCircle  :  public Sketch
{ // initial positions and speeds reduced (compared to the Processing values)
  float64 x = 10.0;
  float64 y = 10.0;
  float64 xspeed = 1.5;
  float64 yspeed = .75;

  void DrawSelf ()
    { // update position and detect bounds
      x += xspeed;
      y += yspeed;

      if (x > Feld () -> Width () / 2  ||
          x < -(Feld () -> Width () / 2))
        xspeed = xspeed * -1;
      if (y >  Feld () -> Height () / 2  ||
          y < -(Feld () -> Height () / 2))
        yspeed = yspeed * -1;

      Clear ();
      DrawEllipse (Vect (x, y, 0), 16, 16);
    }
};


void Setup ()
{ // color the background
  SetFeldsColor (Color ("#A8BBBA"));

  MovingCircle *c = new MovingCircle ();
  c -> SlapOnFeld ();
}
