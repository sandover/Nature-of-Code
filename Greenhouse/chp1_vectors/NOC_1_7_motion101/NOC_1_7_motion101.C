/* (c)  oblong industries */


#include "Greenhouse.h"

/**

 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman

 Example 1-7: Motion 101

 **/

struct Mover  :  public Sketch
{ Vect velocity;
  Vect location;

  Mover ()
    { //  center of the sketch is at the center of the window
      SlapOnFeld ();

      // speed & location randomized
      velocity = Vect (Random (-2, 2), Random (-2, 2), 0);

      //  remember: 0,0 is the center of the sketch
      location = Vect (Random (-Feld () -> Width ()/2, Feld () -> Width ()/2),
                       Random (Feld () -> Height ()/2, -Feld () -> Height ()/2),
                       0);
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
    { location += velocity;
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