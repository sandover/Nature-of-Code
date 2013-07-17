/* (c)  oblong industries */


#include "Greenhouse.h"

/**

 A port to Greenhouse of examples from The Nature of Code by Daniel Shiffman

 Example 1-7: Motion 101

 In this version, we move the Sketch object itself, instead of moving the
 circle inside the Skech.

 **/

struct Mover  :  public Sketch
{ Vect velocity;

  Mover ()
    { //  center of the sketch is at the center of the window
      SlapOnFeld ();

      // speed randomized
      velocity = Vect (Random (-2, 2), Random (-2, 2), 0);

      //  offset within the window by a random amount
      IncTranslation (Vect (Random (-Feld () -> Width ()/2, Feld () -> Width ()/2),
                            Random (Feld () -> Height ()/2, -Feld () -> Height ()/2),
                            0));

      DrawEllipse (Vect (0, 0, 0), 8, 8);
    }

  void checkEdges ()
    { //  remember: 0,0 is the center of the sketch
      if (Loc ().x > Inside (Feld (), Vect (0.5, 0, 0)) . x)
        IncTranslation (Vect (-Feld () -> Width (), 0, 0));
      else if (Loc ().x < Inside (Feld (), Vect (-0.5, 0, 0)) . x)
        IncTranslation (Vect (Feld () -> Width (), 0, 0));

      if (Loc ().y > Inside (Feld (), Vect (0, 0.5, 0)) . y)
        IncTranslation (Vect (0, -Feld () -> Height (), 0));
      else if (Loc ().y < Inside (Feld (), Vect (0, -0.5, 0)) . y)
        IncTranslation (Vect (0, Feld () -> Height (), 0));
    }

  void Travail ()
    { IncTranslation (velocity);
      checkEdges ();
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