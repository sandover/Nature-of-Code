/* (c)  oblong industries */


#include "Greenhouse.h"

/**

 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman

 Example 1-5: Vector magnitude

 **/


struct PointingTracker  :  public Sketch
{
  Vect mouse;
  float64 h = 3.0; // bar height

  void PointingMove (PointingEvent *e)
    { // pointer location in absolute coords
      mouse = Intersection (e, Loc ());

      // pointer location in sketch-local coords
      mouse = WrangleLoc (mouse);
    }

  void DrawSelf ()
    { Clear ();
      DrawLine (Vect (0, 0, 0), mouse . Norm () * 50);
    }
};


void Setup ()
{ SetFeldsColor (Color ("#A8BBBA"));
  PointingTracker * p = new PointingTracker ();
  p -> SlapOnFeld ();
}
