#include "GAME.h"
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	GAME game;
	game.run();
	return 0;
}

//�E�N���X��private�ȃ����o�͊�{�I�ɑ啶���n�܂�ɂ��Ă��܂��B
//�E�e�f�[�^�̎��̂�private�ɂ��Ă���O������A�N�Z�X�ł��Ȃ��悤�ɂ��Ă��܂��B
//�Egetter�֐��͊�{�w�b�_�Œ�`���邱�ƂŃC�����C���W�J�����҂��Ă��܂��B
//�ECONTAINER�N���X�Ɋe�N���X�̃f�[�^���܂Ƃ߂邱�Ƃŕێ琫�̊m�ۂ����݂Ă��܂��B
//�Ebackground�ɂ��Ă͑��̃N���X�ɗe�ՂɃA�N�Z�X�ł��Ȃ��Ă����ɖ��Ȃ����Ȃƍl���A
//	�Ɨ����Ē�`���Ă݂܂����B

//�Z�p�I�Ȗ������̉ۑ�F
//�@�������}�W�b�N�i���o�[���c���Ă��܂��܂���(PLAYER_BULLETS.cpp�A�w�i�F�̐ݒ蓙)�B
//�A�t���[�����[�g60���O��ɂȂ��Ă���̂Ŋ��ɂ���Ă͓������ς���Ă��܂��܂��B
//�BITEM��������Ƃ��ɒe����������֐���PLAYER_BULLETS�N���X�ɐݒ肵�Ă��܂��B
//  �F�X���������ɁA�����Container(�f�[�^�Q)�̏��𒼐ڏ��������Č�Ŗ߂��Ƃ����������Ă���A
//	���܂�D�܂����Ȃ����@������Ă��܂��B���̃X�}�[�g�ȕ��@��͍����ł��B