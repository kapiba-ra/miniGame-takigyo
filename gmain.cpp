#include "GAME.h"
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	GAME game;
	game.run();
	return 0;
}

//�T�v
//�E�Ǘ��p��GAME�N���X��p�ӂ���AGAME_OBJECT�N���X�̔h���N���X�Ƃ���SCENE��L�����N�^�̃N���X��
//	����Ă����Ƃ�����{�I�ȃN���X�̍\���́A���̕��̃\�[�X�R�[�h���Q�l�ɂ��܂����B
//�E�N���X��private�ȃ����o�̖��O�͑啶���n�܂�ɂ��Ă��܂��B
//�E�e�f�[�^�̎��̂͊�{private�ɂ��Ă���O������A�N�Z�X�ł��Ȃ��悤�ɂ��Ă��܂��B
//�ECONTAINER�N���X�Ɋe�N���X�̃f�[�^���܂Ƃ߂邱�Ƃŕێ琫�̊m�ۂ����݂Ă��܂��B
//�Egetter�֐��͊�{�w�b�_�Œ�`���邱�ƂŃC�����C���W�J�����҂��Ă��܂��B

//�Z�p�I�Ȗ������̉ۑ�(���o����͈͂�)�F
//�@�������}�W�b�N�i���o�[���c���Ă��܂��܂���(PLAYER_BULLETS.cpp�A�w�i�F�̐ݒ蓙)�B
//�A�t���[�����[�g60���O��ɂȂ��Ă���̂Ŋ��ɂ���Ă͓������ς���Ă��܂��܂��B
//�BITEM��������Ƃ��ɒe����������֐���PLAYER_BULLETS�N���X�ɐݒ肵�Ă��܂��B
//  �F�X���������ɁA�����Container(�f�[�^�Q)�̏��𒼐ڏ��������Č�Ŗ߂��Ƃ����������Ă���A
//	���܂�D�܂����Ȃ����@������Ă��܂��B���̃X�}�[�g�ȕ��@��͍����ł��B
//