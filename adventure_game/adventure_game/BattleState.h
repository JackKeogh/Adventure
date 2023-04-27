#pragma once


#ifndef BATTLESTATE_H
#define BATTLESTATE_H

enum class BattleState
{
	No_Battle,
	Opening_Wait,
	Opening_Display,
	Open_Animation_Enemy,
	Open_Animation_Player,
	Select_Action,
	Calculate_Speed, // Who goes first?
	Execute_Action_Player,
	Calculate_Action_Player,
	Execute_Action_Enemy,
	Calculate_Action_Enemy,
	Calculate_Exp,
};


#endif // !BATTLESTATE_H
