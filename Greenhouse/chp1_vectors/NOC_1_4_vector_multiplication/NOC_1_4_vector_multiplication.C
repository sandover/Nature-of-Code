/* (c)  oblong industries */


#include "Greenhouse.h"

/**

 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman

 Example 1-4: Vector multiplication

 **/


struct PointingTracker  :  public Sketch
{ Vect mouse;

  void PointingMove (PointingEvent *e)
    { // pointer location
      mouse = Intersection (e, Loc ());

      // subtract the window's center
      mouse = mouse - Loc ();

      mouse *= 0.5;
    }

  void DrawSelf ()
    { Clear ();
      DrawLine (Vect (0, 0, 0), mouse);
    }
};

void Setup ()
{ SetFeldsColor (Color ("#A8BBBA"));
  PointingTracker * p = new PointingTracker ();
  p -> SlapOnFeld ();
}
