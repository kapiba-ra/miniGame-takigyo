#pragma once

//GAME_OBJECT�́A�Q�[�����̖��O�������̑S�Ă̊��N���X�B
//game()�͌p������S�ẴI�u�W�F�N�g�ŌĂяo�����Ƃ��ł���B
//�h���N���X�ł͈ȉ��̂悤�Ɏg����̂ŕ֗��B
//game()->container()->(�N���X��)Data.(�A�N�Z�X�������f�[�^);

class GAME_OBJECT
{
public:
	GAME_OBJECT(class GAME* game);
	virtual ~GAME_OBJECT();
//GAME�N���X�̃|�C���^"Game"�̏����ݒ�ƃQ�b�^�[�֐�"game()"�B
private:
	class GAME* Game = 0;
public:
	class GAME* game() { return Game; }
};