#include "GAME_OBJECT.h"

//受け取ったポインタをコピーしプライベートなポインタへ
GAME_OBJECT::GAME_OBJECT(class GAME* game){
	Game = game; 
}
GAME_OBJECT::~GAME_OBJECT(){
}
