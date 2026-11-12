# Polymorphism notes

Answer in your own words. Use the words **static dispatch** and **dynamic dispatch**.

## 1. The non-virtual destructor

What did the sanitizer report when `~Game` was not virtual? Explain which destructor ran and which did not.
When ~Game was not virtual, the sanitizer reported undefined behavior or a resource leak because deleting a derived game object through a base class pointer uses static dispatch to determine which destructor to call. As a result, only the base class Game destructor ran, while the derived class destructor did not run at all, leaving derived resources uncleared.

## 2. Game is abstract

In two sentences, explain why `Game g;` no longer compiles.
Declaring Game g; attempts to directly instantiate an abstract base class that contains pure virtual functions. Because the compiler cannot resolve these pure virtual functions via static dispatch or runtime dynamic dispatch for an incomplete base type, it rejects the instantiation.

## 3. override

What does `override` protect you from? Give an example of a mistake it catches.
The override keyword protects you from accidentally defining a new function instead of overriding a base class virtual function due to a signature mismatch. For example, if you misspell a method name or change a parameter type, override causes a compile-time error instead of silently falling back to static dispatch on the base method.

## 4. Last week versus this week

Repeat the Week 12 experiment: `Game *g = &hangman; g->play();`. What printed last week, and what prints now? Name the kind of dispatch that happened each time.
ast week, calling g->play() on a base pointer invoked the base class version using static dispatch determined at compile time. This week, because play() is virtual, calling g->play() invokes Hangman::play() at runtime using dynamic dispatch via the vtable.
