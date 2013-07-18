/* (c)  oblong industries */


#include "Greenhouse.h"

/**

 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman

 Example 1-3: Vector subtraction

 **/


struct PointingTracker  :  public Sketch
{ Vect mouse;

  void PointingMove (PointingEvent *e)
    { // pointer location in absolute coords
      mouse = Intersection (e);

      //  subtract the Sketch's center to get coordinates that are
      //  local to the Sketch
      mouse = mouse - Loc ();
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
