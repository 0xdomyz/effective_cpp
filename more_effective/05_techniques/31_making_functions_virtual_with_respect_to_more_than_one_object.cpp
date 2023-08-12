// g++ 31_making_functions_virtual_with_respect_to_more_than_one_object.cpp -o 31_making_functions_virtual_with_respect_to_more_than_one_object && ./31_making_functions_virtual_with_respect_to_more_than_one_object

// As the ships, stations, and asteroids whiz around in your artificial
// world, they naturally run the risk of colliding with one another. Let’s
// assume the rules for such collisions are as follows:
//
// - If a ship and a station collide at low velocity, the ship docks at the
// station. Otherwise the ship and the station sustain damage that’s
// proportional to the speed at which they collide.
// - If a ship and a ship or a station and a station collide, both participants in the
// collision sustain damage that’s proportional to the
// speed at which they hit.
// - If a small asteroid collides with a ship or a station, the asteroid is
// destroyed. If it’s a big asteroid, the ship or the station is destroyed.
// - If an asteroid collides with another asteroid, both break into
// pieces and scatter little baby asteroids in all directions.

// What you need is a kind of function whose behavior is somehow virtual
// on the types of more than one object.

// virtual function call is termed a “message dispatch.

// A call that’s virtual on two parameters is implemented through
// a “double dispatch.”

// a function acting virtual on several parameters — is called multiple dispatch.

// Using Virtual Functions and RTTI
// ######################################

// Virtual functions implement a single dispatch

// virtual function emulation via chains of if-thenelses. In this harsh world, we first
// discover the real type of otherObject, then we test it against all th

// each collide function must be aware of each of its sibling classe

// if a new type of
// object — a new class — is added to the game, we must update each
// RTTI-based if-then-else chain in the program that might encounter
// the new object type

// yields programs that are essentially unmaintainable.
// Enhancement of such programs eventually becomes unthinkable

// Using Virtual Functions Only
// ######################################

// The collide function is declared virtual in GameObject and is redefined in each
// derived class. In addition, collide is
// overloaded in each class, one overloading for each derived class in the
// hierarchy

// to implement double-dispatching as two single dispatches

// the first virtual call is to the collide
// function taking a GameObject& parameter
// call is therefore to the collide function taking a SpaceShip&, not the
// collide function taking a GameObject&

// Emulating Virtual Function Tables
// ######################################

// Initializing Emulated Virtual Function Tables
// ######################################

// Using Non-Member Collision-Processing Functions
// ######################################

// Inheritance and Emulated Virtual Function Tables
// ######################################

// Initializing Emulated Virtual Function Tables (Reprise)
// ######################################
