/* (c)  oblong industries */


#include "Greenhouse.h"

/**

 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman

 Example 1-2: Bouncing Ball, with Vectors! Loc () and PhysLoc ()
 Using a Box for now to keep drawing simple.

 **/

struct MovingCircle  :  public Sketch
{ // initial positions and speeds reduced (compared to the Processing values)
  Vect location = Vect (10, 10, 0);
  Vect velocity = Vect(1.5, .75, 0);

  void DrawSelf ()
    { // update position and detect bounds
      location += velocity;

      if (location.x > Feld () -> Width () / 2  ||
          location.x < -(Feld () -> Width () / 2))
        velocity.x = velocity.x * -1;
      if (location.y >  Feld () -> Height () / 2  ||
          location.y < -(Feld () -> Height () / 2))
        velocity.y = velocity.y * -1;

      Clear ();
      DrawEllipse (location, 16, 16);
    }
};


void Setup ()
{ // color the background
  SetFeldsColor (Color ("#A8BBBA"));

  MovingCircle *c = new MovingCircle ();
  c -> SlapOnFeld ();
}
