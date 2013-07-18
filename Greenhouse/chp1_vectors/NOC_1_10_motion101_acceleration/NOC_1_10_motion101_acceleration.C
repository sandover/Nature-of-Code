/* (c)  oblong industries */


#include "Greenhouse.h"

/**

 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman

 Example 1-10: Motion 101 Acceleration
 A "Mover" object stores velocity, and acceleration as vectors
 The motion is controlled by affecting the acceleration (in this case towards the mouse)

 **/


Vect Limit (Vect v, float64 max)
{ if (v . Mag () > max)
    return v *= max / v . Mag ();
  else
    return v;
}


struct Mover  :  public Sketch
{ Vect velocity;
  Vect location;
  Vect acceleration;
  Vect pointer_loc;
  float64 topspeed = 10;

  Mover ()
    { //  center of the sketch is at the center of the window
      SlapOnFeld ();

      //  remember: 0,0 is the center of the sketch
      location = Vect (Random (-Feld () -> Width ()/2, Feld () -> Width ()/2),
                       Random (Feld () -> Height ()/2, -Feld () -> Height ()/2),
                       0);
    }

  void PointingMove (PointingEvent *e)
    { // pointer location in absolute coords, converted to sketch-local coords
      pointer_loc = WrangleLoc (Intersection (e));
    }

  void checkEdges ()
    { //  remember: 0,0 is the center of the sketch
      if (location.x > Feld () -> Width ()/2)
        location.x = -Feld () -> Width ()/2;
      else if (location.x < -Feld () -> Width ()/2)
        location.x = Feld () -> Width ()/2;

      if (location.y > Feld () -> Height ()/2)
        location.y = -Feld () -> Height ()/2;
      else if (location.y < -Feld () -> Height ()/2)
        location.y = Feld () -> Height ()/2;
    }

  void Travail ()
    { acceleration = pointer_loc - location;
      acceleration = acceleration . Norm () / 100.0;

      velocity += acceleration;
      velocity = Limit (velocity, topspeed);
      location += velocity;
      checkEdges ();
    }


  void DrawSelf ()
    { Clear ();
      DrawEllipse (location, 8, 8);
    }
};


void Setup ()
{ // color the background
  SetFeldsColor (Color ("#A8BBBA"));
  // generate a new random seed for unique results each time
  SeedRandomizer ();
  // add the Mover
  new Mover ();
}