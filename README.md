# Baba Is You - Remake
## All rights belong to [Baba is you](https://store.steampowered.com/app/736260/Baba_Is_You/)

Written in C++ using SFML, we created this game as a final project of object oriented programming course.

## How to play
The game has rules, which appear on board. 
One of those rules indicates the win condition.
Also, one of those rules indicates who you, the player, represents.

The goal is for you to collide with the object that is the win condition, as the rule state.
Rules consist of 3 blocks of words. Those words can be pushed and make the rule invalid.
Word blocks can also be pushed to form another rule, different rule than before, which changes how the game behaves.

Whenever there is no rule stating who "you" is, the player essentially does not exist. 
Whenever this is no rule stating what "win" is, there is no win condition, and proceeding to next level is not possible.

The valid rules are:
	* Noun - is - Noun: indicates transformation of all objects of one type to the other
	* Noun - is - Attribute: gives all objects which the noun indicates the attribute
	* You - is - Win (does not appear in original game)

Whenever noun is defeat, when "you" collide with it, the "you" object that collided is destroyed
Whenever noun is sink, when something else is collided with it, both objects are destroyed
Whenever noun is stop, nothing can pass through it.
Whenever noun is push, it can be pushed upon movement (words are always pushed)


Arrows move "you"
Tab - shows mini-menu while in video
Z - undo your previous action
R - restart the board

##Load Levels
while in game after each level the game save its progress and can be accessesed from menu in option load leve(the levels are save in strings and not loaded 
from the file again).

## Compile and run

The levels of the game are pre-written into external file which the program reads. 
The text file containing the levels must meet the following form:
	* The levels must not exceed 17X30
	* No \n in between 2 consequent levels

Legend:
```
A - Algae
B - Baba
F - Flag
G - Skull
K - Wall
M - Water
R - Rock
V - Flower

a - Algea word
b - Baba Word
f - Flag Word
g - Skull Word
k - Wall Word
m - Water Word
r - Rock Word
v - Flower Word

i - Is

y - You Word
d - Defeat Word
p - Push Word
s - Stop Word
w - Win Word
l - Sink Word
```

# Main design ideas

The objects of the game consist of two types - words and non-words. While words have their own strategy and
basic ideas, the non-words object are straight forward - they are object with certain propertes, which might
vary and change according to the rules present. Since each instantion of same type of non-word must have
the same properties, we use an ordered set of properties, sorted by priority, and act according
to the highest priority of the object.

The properties were built using strategy design pattern. each property has its own handle-Collision and movement
functions.

Each BaseObject has DataHolder as a member, which holds stack which records previous operations that
were done on that object. 

The supported operations are movement, transformation, remove and no-operation. Using command-pattern design,
The operations are able to restore the previous board state using undo function which acts on all objects
present in current level. Each operation has execute function, and an undo function, which both of 
essentially cancel each other.

RuleHandler is a class responsible for handling all aspects of rules. The board searches for triples
of objects on the board - the the RuleHandler filters the rules out of them using MultiMethod table.

The generation of objects is done using Factory design-pattern

# List of files:
	* animation handling
	Animation.h
	AnimationData.h
	Direction.h
	BaseObject.h - abstract class
	Property.h - Abstract stratrgy, to dynamically change properties of objects
	PropertyDefault.h - does nothing
	PropertyDefeat.h - kills you if collided
	PropertyPush.h - moves the object collided with
	PropertySink.h - removes both object of collision
	PropertyStop.h - undo the movement that caused this collision to occur
	PropertyWin.h - if you hit it, move to next level
	ProperttYou.h - moves the object when clicking buttons
	Board.h - main source of interactions between objects, sends to rulehandle potential rules, finds collisions
	DataHolder.h - holds the stack of each object
	FileHandler.h - maintains from which levels are uploaded
	RuleHandler.h - maintains rules, fileters rules form triples on board, sets rules into affect, removes old ones from affect
	Command.h
	Controls.h
	ExitGame.h
	LoadLevel.h
	LvlLoadCommand.h
	NewGame.h
	Restart.h
	Resume.h
	REturnToMenu,h
	MaimMenu.h
	Menu.h -
			All the menu classes are derived from Menu.h, all of them have the same structure based on 'command' design-pattern.
			each one of the menu's has to request in the constructor for elements needed in the commands(might be a screen or controller..). 
	Menu2.h
	MenuControls.h
	MenuLevels.h
	Header.h -
				makes it easy to create a sentence of animenated letters(an object which gets sstream and creates an animeted word)	.
	BaseOperation.h - Abstract, for polymorphism on stack, has execute and undo, both cancel each other
	NoOperation.h - does nothing, undo does nothing
	OperationMove.h - moves to direction, undo moves to opposite
	OperationRemove.h - removes object from map, undo adds object to map
	OperationTransform.h - changes one object into another, templated
	
	All of those objects are preactically the same, they have different static set of attributes
	Algae.h 
	Baba.h
	Flag.h
	Flower.h
	Rock.h
	Skull.h
	Wall.h
	Water.h
	
	*Words*
	each word has an "equipment" and is charging nouns when a rule is detected with the relevant property
	AlgaeWord.h
	Attribute.h
	BabaWord.h
	Conjunction.h
	DefeatWord.h
	FlagWord.h
	FlowerWord.h
	Is.h - The only conjunction, is connecting to blocks into a rule if valid
	Noun.h
	Predicate.h - asbttract, basically non-conjunction, noun and attribute inherit form it
	PushWord.h 
	RockWord.h
	SinkWord.h
	SkullWord.h
	StopWord.h
	WallWord.h
	WaterWord.h
	WinWord.h
	YouWord.h

# Main Data Structures

We used a vector to hold all the characters in the map, where all the interactions between object is occuring.
alongside it, there is a vector of DataHolder, each has a member point to a BaseObject on the map

The BaseObject vector is where all the interactions happen,
The DataHolder vector is where all the recording of operations happen.

Since the map can be mutated, there is a need for a more general data structure that will hold ALL objects
of game regardless of position on board, in order to keep track operations happening to it
and making undo buttons valid for full restoration of board in case it is needed.
The DataHolder vector does just that - upon each movement, ALL stacks record NoOperation defaultly.
When an operation occurs to a certain BaseObject, the NoOperation is overwritten and replaced with the 
correct operation. This method makes sure that at each iteration of main loop, the undo button restores
the board to its previous state fully.

Each object in game has set of attributes attached to it - and they are dynamically changed.
Since many properties are valid on one BaseObejct - the interaction of the object with another object 
might be inconsistent arbitrary. So, we assigned for each property a priority, and each object has the 
highest priority of all the properties he holds. This makes for a consistent game.


# Known Algorithms

## Rule checking algorithm

For finding triples, the naive way is to iterate on all possible triples and add a triple that is found
to a vector. 

We first sorted the array based on x valus, and then used stable-sort on y values of position of objects.
The result was a vector of objects which is sorted by BOTH x values and y values, with a priority to sort 
based on x values. This way the runtime of the triple-nested loop is shorter, since there is no
need to iterate on ALL possible triples, but to stop when detecting an element from which
the previous ones that were found cannot possibly be part of a triple with one in front,
since the array is sorted the way it is.

After a vector of triples is found, it is compared to existing rule vector:
If a rule deteced on board appears in rule set, it adds no new information, and is discarded.
If a rule on the rule set is not deteced on the rules-on-board, it means that it is no longer valid,
and is deleted and removed from game.

After both of those actions is done, what is left out of the rules-on-board are the new rules that
need to be validated, and what left of the game rule set is what did not change from previous time.
So merging them will result in an updated vector of current valid rules

## Printing algorithm
Since drawing animations on board can be a problem when there are two objects in one spot - there 
is a need to determine which one should be drawn. The default way to do it is by priority, but it is a bit
tricky to compute in a consistent manner. So, we implemented an lru-approximation algorithm which determines
which objects were moved the most. A 100 length bitset is set for each object. After each movement,
The bitset of each object is rotated to the right. If the object moved, we set MSB to 1. The number of set bits
is the number of times the object was moved in the last 100 turns, and thus provides for a sufficient 
way to determine which objects were moved and gives them the priority upon map-draw.

# Knwon Bugs

* Trying to push a rule that says "noun is push" where all elements are on the same tile as that noun
will throw an exception
