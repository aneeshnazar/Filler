# Filler

The goal of the filler project is to create an "enemy" AI in C, capable of playing the game of filler.

The game pits two players against one another on a rectangular board. Players recieve randomly generated pieces, and must place said pieces on the board.
The rules for placement are simple:
1) The new piece has to fit within the bounds of the board.
2) The new piece cannot overlap the other players' pieces.
3) The new piece has to overlap the player's pieces, but only once.

The game ends when the players can no longer place pieces. The player who places the last piece wins. As such, the player who outlasts their opponent will win, so endurance was my end goal.
My algorithm is very resilient by design - as long as it can find a placement, it will place a piece, and if it can't, it checks for negative-placement (pieces are often sent to the player with a lot of padding, 
so it's possible to place a piece at negative coordinates, and it should still be valid as long as the "solid" part is still on-the-board).

This algorithm will reliably win 4/5 times against most players. It has the best results on large maps, but these maps can cause the game to run for a long time.
