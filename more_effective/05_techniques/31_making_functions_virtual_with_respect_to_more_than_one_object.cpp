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

// each
// class must know about its siblings. As new classes are added, the code
// must be updated

// each class definition must be amended to include a new virtual function

// started with an off-the-shelf class library comprising a video game application
// framework, you might not have write access to the GameObject class or the framework
//  classes derived from it

// In practice, libraries in wide use are modified
// only rarely, because the cost of recompiling everything using those libraries is too great

// The long and short of it is if you need to implement double-dispatching
// in your program, your best recourse is to modify your design to eliminate the need.
//
// Failing that, the virtual function approach is safer than
// the RTTI strategy, but it constrains the extensibility of your system to
// match that of your ability to edit header files.
//
// The RTTI approach, on
// the other hand, makes no recompilation demands, but, if implemented
// as shown above, it generally leads to software that is unmaintainable.

// Emulating Virtual Function Tables
// ######################################

//  compilers typically implement virtual functions by creating an
// array of function pointers (the vtbl) and then indexing into that array
// when a virtual function is called.

// more efficient, less code, isolate RTTI to the place where array is initialized

// GameObject class contains only one function for processing collisions,

//  each kind of interaction is encapsulated in a separate function, though in this case
//   the functions have different names instead of sharing the name collide

// associative array that, given a class name, yields
// the appropriate member function pointer.
// could add an intervening function, lookup, that takes a GameObject

// Provided we’ve kept the contents of our associative array in sync with
// the class hierarchy under GameObject, lookup must always find a
// valid function pointer for the object we pass it

// could use new and
// delete to create and destroy the array manually, but that would be
// error-prone: how could we guarantee the array wasn’t used before we
// got around to initializing it? A better solution is to have compilers automate
// the process, and we can do that by making the associative
// array static in lookup

// Initializing Emulated Virtual Function Tables
// ######################################

// What we need now is a way to put the member function pointers into
// collisionMap only once — when collisionMap is created. That’s
// easy enough to accomplish; we just write a private static member function
// called initializeCollisionMap to create and initialize our map,
// then we initialize collisionMap with initializeCollisionMap’s return value

// can turn collisionMap into a smart pointer (see Item 28) that automatically deletes
// what it points to when the pointer itself is destroyed

//  a HitMap is
// declared to hold pointers to member functions that all take the same
// Implementing Multiple Dispatch 241
// type of argument, namely GameObject. But hitSpaceShip takes a
// SpaceShip, hitSpaceStation takes a SpaceStation, and, hitAsteroid takes an Asteroid.
// Even though SpaceShip, SpaceStation,
// and Asteroid can all be implicitly converted to GameObject, there is
// no such conversion for pointers to functions taking these argument
// types.

// reinterpret_cast could be considered, but won't do if have A-B-C-D inherence stucture
// what if you’ve lied to your compilers and told them your function
// expects a GameObject when it really expects a SpaceShip or a
// SpaceStation? Then they’ll pass the wrong address when you call the
// function

// change the types of the functions so they all take GameObject arguments
// so we must give them different names.
// resort to a dynamic_cast (see Item 2) at the top of each function
// throw a bad_cast exception if the cast fails

// Using Non-Member Collision-Processing Functions
// ######################################

// still have to modify class definitions if a new type of GameObject is
// added to the game, and that means everybody has to recompile, even
// people who don’t care about the new type of object.

//  recompilation problem would go away if our associative array contained pointers to
//   non-member functions

// be better to design things so that collisions between objects of types A and B are
//  handled by neither A nor B
// but instead in some neutral location outside both classes?

// unnamed namespace to contain the functions used
// to implement processCollision

// First, HitFunctionPtr is now a typedef for a pointer to a non-member function.
//
// Second, the exception class CollisionWithUnknownObject has been
// renamed UnknownCollision and modified to take two objects instead
// of one.
//
// Finally, lookup must now take two type names and perform
// both parts of the double-dispatch. This means our collision map must
// now hold three pieces of information: two types names and a HitFunctionPtr

// using the
// standard pair template, which lets us bundle the two type names together as a single objec

// If new subclasses of GameObject
// are added to our hierarchy, existing classes need not recompile (unless
// they wish to use the new classes).
//
// The addition of new classes to the hierarchy requires only well-defined and localized
// changes to our system: the addition of one or more map insertions in
// initializeCollisionMap and the declarations of the new collisionprocessing
// functions

// Inheritance and Emulated Virtual Function Tables
// ######################################

// the concrete classes CommercialShip and MilitaryShip inherit from the newly abstract
// class SpaceShip

// lookup would be asked to find a
// function corresponding to the type names “MilitaryShip” and “Asteroid,” and no
// such function would be found in collisionMa

// only practical recourse is
// to fall back on the double-virtual-function-call mechanism

// Initializing Emulated Virtual Function Tables (Reprise)
// ######################################

// our design is entirely static

// a class that offers member functions allowing us to modify the contents of the
// map dynamically

// add entries to the map, remove them from it
// look up the collision-processing function
// limit the number of CollisionMap objects to one
// Finally, it allows us to simplify the addition of symmetric collisions

// Care must be taken to ensure that these map entries are added to the
// map before any collisions occur
//
// One way to do this would be to have constructors in GameObject
// subclasses check to make sure the appropriate mappings had been
// added each time an object was created.
//
// An alternative would be to create a RegisterCollisionFunction class
// use global objects of this type to automatically register the functions they need
// objects are created before main is invoked
