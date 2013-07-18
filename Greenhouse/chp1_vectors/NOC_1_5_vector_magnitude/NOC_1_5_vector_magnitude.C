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

  PointingTracker ()
    { SetFillColor (Color (1, 1, 1));
    }


  void PointingMove (PointingEvent *e)
    { // pointer location in absolute coords, converted to sketch-local coords
      mouse = WrangleLoc (Intersection (e));
    }

  void DrawSelf ()
    { Clear ();
      DrawLine (Vect (0, 0, 0), mouse);
      DrawRect (WrangleLoc (Inside (Feld (), Vect (-0.5, 0.5, 0))) +
                Feld () -> Over () * mouse . Mag () / 2,
                mouse . Mag (),
                10);
    }
};


void Setup ()
{ SetFeldsColor (Color ("#A8BBBA"));
  PointingTracker * p = new PointingTracker ();
  p -> SlapOnFeld ();
}
