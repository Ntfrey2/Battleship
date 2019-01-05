# Project Proposal
 For my final project I will atempt to create the game Battleships. There will be no AI aspect. Instead it will switch turns between players the two players. There will be a home page where the users will have the option to select between three buttons. One button will lead to a directions page where the user can read how the game is played in this version. There will be a button on the page to go back, as well. The second button on the homepage is to play the game. The third is to exit the game, which will shut the game down.

  When they click on the play button, the ships will be placed randomly on each of the player's boards. The first player will see a empty map with 64 blank squares and coordinates on the top and left side. There will also be two buttons. One to exit, which will take them to the home screen. The other will say "see fleet" which will show there ships and the locations the other player has attacked. It will also have a back button to return to the coordinate map. On the coordinate map. They will click on one of the squares and it will mark red for hit and white for miss. Once they press the square the board will be saved and the opponets fleet map will be marked as well. Then there will be a two second delay, where the screen will go black saying "switching players" with a countdown from 5. The second player will have the same interface. Except the fleet will be their own and so will the coordinate map.

  Once a player has won, the game will end and all the boards will be reset. The screen will change to a white background saying one of the players won. Under the text will be a button to leave and they will be taken back to the homepage.
  
Frameworks:

ofxBaseGui: GUI setup http://openframeworks.cc/documentation/ofxGui/ofxBaseGui/

ofxButton: Creates button and has mouse clicks http://openframeworks.cc/documentation/ofxGui/ofxButton/

ofRectangle: Create the grid http://openframeworks.cc/documentation/types/ofRectangle/#show_ofRectangle

ofImage: Background images http://openframeworks.cc/documentation/graphics/ofImage/

May not need:

ofxMSAinteractiveObjects: Mouse clicks for squares https://github.com/Flightphase/ofxMSAInteractiveObject/tree/master
