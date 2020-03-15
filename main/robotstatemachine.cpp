/***************************************************************************
 *                 THIS IS GENERATED CODE -- DO NOT MODIFY                 *
 ***************************************************************************/
#include "robotstatemachine.h"
#include <limits.h>
#include <string.h>

static void RobotStateMachine_transitionTo(struct RobotStateMachine_struct *machine, enum RobotStates_enum state, clock_t current_tick_count);
static void RobotStateMachine_transitionFrom(struct RobotStateMachine_struct *machine, enum RobotStates_enum state, clock_t current_tick_count);
static void RobotStateMachine_transitionTo(struct RobotStateMachine_struct *machine, enum RobotStates_enum state, clock_t current_tick_count)
{
	machine->busy_ = true;
	machine->transition_pending_ = false;
	machine->state_= state;
	switch (state)
	{
	case ROBOTSTATE_INITIAL :
		RobotStateMachine_transitionFrom(machine, state, current_tick_count);
		RobotStateMachine_transitionTo(machine, ROBOTSTATE_NOT_MOVING, current_tick_count);
		break;
	case ROBOTSTATE_GOING_FORWARD :
		machine->forward_callback_(machine, machine->user_);
		break;
	case ROBOTSTATE_GOING_BACKWARD :
		machine->backward_callback_(machine, machine->user_);
		break;
	case ROBOTSTATE_TURNING_LEFT :
		machine->left_callback_(machine, machine->user_);
		break;
	case ROBOTSTATE_TURNING_RIGHT :
		machine->right_callback_(machine, machine->user_);
		break;
	case ROBOTSTATE_NOT_MOVING :
		machine->stop_callback_(machine, machine->user_);
		break;
	case ROBOTSTATE_DANCE_0 :
		machine->loop_counter_[machine->loop_level_++] = 0;
		machine->transition_pending_ = true;
		machine->next_state_ = ROBOTSTATE_DANCE_1;
		break;
	case ROBOTSTATE_DANCE_1 :
		machine->forward_callback_(machine, machine->user_);
		machine->deadline_set_ = true;
		machine->deadline_ = current_tick_count + ((1000 / 1000) * machine->clock_freq_) + ((1000 % 1000) * (machine->clock_freq_ / 1000)) ;
		break;
	case ROBOTSTATE_DANCE_2 :
		machine->backward_callback_(machine, machine->user_);
		machine->deadline_set_ = true;
		machine->deadline_ = current_tick_count + ((1000 / 1000) * machine->clock_freq_) + ((1000 % 1000) * (machine->clock_freq_ / 1000)) ;
		break;
	case ROBOTSTATE_DANCE_3 :
		machine->left_callback_(machine, machine->user_);
		machine->deadline_set_ = true;
		machine->deadline_ = current_tick_count + ((500 / 1000) * machine->clock_freq_) + ((500 % 1000) * (machine->clock_freq_ / 1000)) ;
		break;
	case ROBOTSTATE_DANCE_4 :
		machine->right_callback_(machine, machine->user_);
		machine->deadline_set_ = true;
		machine->deadline_ = current_tick_count + ((500 / 1000) * machine->clock_freq_) + ((500 % 1000) * (machine->clock_freq_ / 1000)) ;
		break;
	case ROBOTSTATE_DANCE_5 :
		machine->transition_pending_ = true;
		if (++machine->loop_counter_[machine->loop_level_ - 1] < 5)
		{
			machine->next_state_ = ROBOTSTATE_DANCE_1;
		}
		else
		{
			machine->next_state_ = ROBOTSTATE_DANCE_6;
			machine->loop_level_--;
		}
		break;
	case ROBOTSTATE_DANCE_6 :
		machine->forward_callback_(machine, machine->user_);
		machine->deadline_set_ = true;
		machine->deadline_ = current_tick_count + ((500 / 1000) * machine->clock_freq_) + ((500 % 1000) * (machine->clock_freq_ / 1000)) ;
		break;
	case ROBOTSTATE_DANCE_7 :
		machine->backward_callback_(machine, machine->user_);
		machine->deadline_set_ = true;
		machine->deadline_ = current_tick_count + ((500 / 1000) * machine->clock_freq_) + ((500 % 1000) * (machine->clock_freq_ / 1000)) ;
		break;
	case ROBOTSTATE_DANCE_8 :
		machine->left_callback_(machine, machine->user_);
		machine->deadline_set_ = true;
		machine->deadline_ = current_tick_count + ((5000 / 1000) * machine->clock_freq_) + ((5000 % 1000) * (machine->clock_freq_ / 1000)) ;
		break;
	case ROBOTSTATE_DANCE_9 :
		machine->right_callback_(machine, machine->user_);
		machine->deadline_set_ = true;
		machine->deadline_ = current_tick_count + ((5000 / 1000) * machine->clock_freq_) + ((5000 % 1000) * (machine->clock_freq_ / 1000)) ;
		break;
	case ROBOTSTATE_DANCE_10 :
		machine->transition_pending_ = true;
		machine->next_state_ = ROBOTSTATE_NOT_MOVING;
	}
	machine->busy_ = false;
}
static void RobotStateMachine_transitionFrom(struct RobotStateMachine_struct *machine, enum RobotStates_enum state, clock_t current_tick_count)
{
	machine->busy_ = true;
	switch (state)
	{
	case ROBOTSTATE_INITIAL :
		break;
	case ROBOTSTATE_GOING_FORWARD :
		break;
	case ROBOTSTATE_GOING_BACKWARD :
		break;
	case ROBOTSTATE_TURNING_LEFT :
		break;
	case ROBOTSTATE_TURNING_RIGHT :
		break;
	case ROBOTSTATE_NOT_MOVING :
		break;
	default:
		break;
	}
	machine->busy_ = false;
}
static void RobotStateMachine_timeout(struct RobotStateMachine_struct *machine, clock_t current_tick_count)
{
	machine->deadline_set_ = false;
	switch (machine->state_)
	{
	case ROBOTSTATE_DANCE_1 :
		RobotStateMachine_transitionFrom(machine, machine->state_, current_tick_count);
		RobotStateMachine_transitionTo(machine, ROBOTSTATE_DANCE_2, current_tick_count);
		break;
	case ROBOTSTATE_DANCE_2 :
		RobotStateMachine_transitionFrom(machine, machine->state_, current_tick_count);
		RobotStateMachine_transitionTo(machine, ROBOTSTATE_DANCE_3, current_tick_count);
		break;
	case ROBOTSTATE_DANCE_3 :
		RobotStateMachine_transitionFrom(machine, machine->state_, current_tick_count);
		RobotStateMachine_transitionTo(machine, ROBOTSTATE_DANCE_4, current_tick_count);
		break;
	case ROBOTSTATE_DANCE_4 :
		RobotStateMachine_transitionFrom(machine, machine->state_, current_tick_count);
		RobotStateMachine_transitionTo(machine, ROBOTSTATE_DANCE_5, current_tick_count);
		break;
	case ROBOTSTATE_DANCE_6 :
		RobotStateMachine_transitionFrom(machine, machine->state_, current_tick_count);
		RobotStateMachine_transitionTo(machine, ROBOTSTATE_DANCE_7, current_tick_count);
		break;
	case ROBOTSTATE_DANCE_7 :
		RobotStateMachine_transitionFrom(machine, machine->state_, current_tick_count);
		RobotStateMachine_transitionTo(machine, ROBOTSTATE_DANCE_8, current_tick_count);
		break;
	case ROBOTSTATE_DANCE_8 :
		RobotStateMachine_transitionFrom(machine, machine->state_, current_tick_count);
		RobotStateMachine_transitionTo(machine, ROBOTSTATE_DANCE_9, current_tick_count);
		break;
	case ROBOTSTATE_DANCE_9 :
		RobotStateMachine_transitionFrom(machine, machine->state_, current_tick_count);
		RobotStateMachine_transitionTo(machine, ROBOTSTATE_DANCE_10, current_tick_count);
		break;
	default :
		break;
	}
}
int RobotStateMachine_init(
	  struct RobotStateMachine_struct *machine
	, void *user_data
	, RobotStateMachineCallback backward
	, RobotStateMachineCallback forward
	, RobotStateMachineCallback left
	, RobotStateMachineCallback right
	, RobotStateMachineCallback stop
	, clock_t clock_freq
	)
{
	memset(machine, 0, sizeof(*machine));
	machine->user_ = user_data;
	machine->backward_callback_ = backward;
	machine->forward_callback_ = forward;
	machine->left_callback_ = left;
	machine->right_callback_ = right;
	machine->stop_callback_ = stop;
	machine->clock_freq_ = clock_freq;
	return 0;
}
void RobotStateMachine_fini(struct RobotStateMachine_struct *machine)
{
	machine->started_ = false;
}
clock_t RobotStateMachine_update(struct RobotStateMachine_struct *machine, clock_t current_tick_count)
{
	machine->latest_update_ = current_tick_count;
	if (!machine->started_)
	{
		RobotStateMachine_transitionTo(machine, ROBOTSTATE_INITIAL, current_tick_count);
		machine->started_ = true;
	}
	else
	{ /* already started -- no need to transition to initial state */ }
	if (machine->transition_pending_)
	{
		RobotStateMachine_transitionFrom(machine, machine->state_, current_tick_count);
		RobotStateMachine_transitionTo(machine, machine->next_state_, current_tick_count);
	}
	else
	{ /* no pending transitions */ }
	if (machine->deadline_set_ && (machine->deadline_ <= current_tick_count))
	{
		RobotStateMachine_timeout(machine, current_tick_count);
	}
	else
	{ /* no deadline set, nothing to time out on */ }
	if (machine->event_pending_)
	{
		machine->event_pending_ = false;
		switch (machine->pending_event_)
		{
		case ROBOTSTATEMACHINEEVENT_BUTTON3 :
			RobotStateMachine_onButton3(machine, current_tick_count);
			break;
		case ROBOTSTATEMACHINEEVENT_BUTTONDOWN :
			RobotStateMachine_onButtonDown(machine, current_tick_count);
			break;
		case ROBOTSTATEMACHINEEVENT_BUTTONLEFT :
			RobotStateMachine_onButtonLeft(machine, current_tick_count);
			break;
		case ROBOTSTATEMACHINEEVENT_BUTTONOK :
			RobotStateMachine_onButtonOK(machine, current_tick_count);
			break;
		case ROBOTSTATEMACHINEEVENT_BUTTONRIGHT :
			RobotStateMachine_onButtonRight(machine, current_tick_count);
			break;
		case ROBOTSTATEMACHINEEVENT_BUTTONUP :
			RobotStateMachine_onButtonUp(machine, current_tick_count);
			break;
		}
	}
	else
	{ /* no events pending */ }
	if (machine->event_pending_)
	{
		return 0;
	}
	else if (machine->transition_pending_)
	{
		return 0;
	}
	else if (machine->deadline_set_)
	{
		return (machine->deadline_ > current_tick_count) ? machine->deadline_ - current_tick_count : 0;
	}
	else
	{
		return UINT_MAX;
	}
}
void RobotStateMachine_onButton3(struct RobotStateMachine_struct *machine, clock_t current_tick_count)
{
	if (!machine->busy_)
	{
		switch (machine->state_)
		{
		case ROBOTSTATE_INITIAL :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_INITIAL, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_DANCE_0, current_tick_count);
			break;
		case ROBOTSTATE_GOING_FORWARD :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_GOING_FORWARD, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_DANCE_0, current_tick_count);
			break;
		case ROBOTSTATE_GOING_BACKWARD :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_GOING_BACKWARD, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_DANCE_0, current_tick_count);
			break;
		case ROBOTSTATE_TURNING_LEFT :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_TURNING_LEFT, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_DANCE_0, current_tick_count);
			break;
		case ROBOTSTATE_TURNING_RIGHT :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_TURNING_RIGHT, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_DANCE_0, current_tick_count);
			break;
		case ROBOTSTATE_NOT_MOVING :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_NOT_MOVING, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_DANCE_0, current_tick_count);
			break;
		default :
			RobotStateMachine_transitionFrom(machine, machine->state_, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_DANCE_0, current_tick_count);
		}
	}
	else
	{
		machine->pending_event_ = ROBOTSTATEMACHINEEVENT_BUTTON3;
		machine->event_pending_ = true;
	}
}
void RobotStateMachine_onButtonDown(struct RobotStateMachine_struct *machine, clock_t current_tick_count)
{
	if (!machine->busy_)
	{
		switch (machine->state_)
		{
		case ROBOTSTATE_INITIAL :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_INITIAL, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_GOING_BACKWARD, current_tick_count);
			break;
		case ROBOTSTATE_GOING_FORWARD :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_GOING_FORWARD, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_GOING_BACKWARD, current_tick_count);
			break;
		case ROBOTSTATE_GOING_BACKWARD :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_GOING_BACKWARD, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_GOING_BACKWARD, current_tick_count);
			break;
		case ROBOTSTATE_TURNING_LEFT :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_TURNING_LEFT, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_GOING_BACKWARD, current_tick_count);
			break;
		case ROBOTSTATE_TURNING_RIGHT :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_TURNING_RIGHT, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_GOING_BACKWARD, current_tick_count);
			break;
		case ROBOTSTATE_NOT_MOVING :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_NOT_MOVING, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_GOING_BACKWARD, current_tick_count);
			break;
		default :
			RobotStateMachine_transitionFrom(machine, machine->state_, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_GOING_BACKWARD, current_tick_count);
		}
	}
	else
	{
		machine->pending_event_ = ROBOTSTATEMACHINEEVENT_BUTTONDOWN;
		machine->event_pending_ = true;
	}
}
void RobotStateMachine_onButtonLeft(struct RobotStateMachine_struct *machine, clock_t current_tick_count)
{
	if (!machine->busy_)
	{
		switch (machine->state_)
		{
		case ROBOTSTATE_INITIAL :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_INITIAL, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_TURNING_LEFT, current_tick_count);
			break;
		case ROBOTSTATE_GOING_FORWARD :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_GOING_FORWARD, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_TURNING_LEFT, current_tick_count);
			break;
		case ROBOTSTATE_GOING_BACKWARD :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_GOING_BACKWARD, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_TURNING_LEFT, current_tick_count);
			break;
		case ROBOTSTATE_TURNING_LEFT :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_TURNING_LEFT, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_TURNING_LEFT, current_tick_count);
			break;
		case ROBOTSTATE_TURNING_RIGHT :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_TURNING_RIGHT, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_TURNING_LEFT, current_tick_count);
			break;
		case ROBOTSTATE_NOT_MOVING :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_NOT_MOVING, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_TURNING_LEFT, current_tick_count);
			break;
		default :
			RobotStateMachine_transitionFrom(machine, machine->state_, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_TURNING_LEFT, current_tick_count);
		}
	}
	else
	{
		machine->pending_event_ = ROBOTSTATEMACHINEEVENT_BUTTONLEFT;
		machine->event_pending_ = true;
	}
}
void RobotStateMachine_onButtonOK(struct RobotStateMachine_struct *machine, clock_t current_tick_count)
{
	if (!machine->busy_)
	{
		switch (machine->state_)
		{
		case ROBOTSTATE_INITIAL :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_INITIAL, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_NOT_MOVING, current_tick_count);
			break;
		case ROBOTSTATE_GOING_FORWARD :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_GOING_FORWARD, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_NOT_MOVING, current_tick_count);
			break;
		case ROBOTSTATE_GOING_BACKWARD :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_GOING_BACKWARD, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_NOT_MOVING, current_tick_count);
			break;
		case ROBOTSTATE_TURNING_LEFT :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_TURNING_LEFT, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_NOT_MOVING, current_tick_count);
			break;
		case ROBOTSTATE_TURNING_RIGHT :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_TURNING_RIGHT, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_NOT_MOVING, current_tick_count);
			break;
		case ROBOTSTATE_NOT_MOVING :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_NOT_MOVING, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_NOT_MOVING, current_tick_count);
			break;
		default :
			RobotStateMachine_transitionFrom(machine, machine->state_, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_NOT_MOVING, current_tick_count);
		}
	}
	else
	{
		machine->pending_event_ = ROBOTSTATEMACHINEEVENT_BUTTONOK;
		machine->event_pending_ = true;
	}
}
void RobotStateMachine_onButtonRight(struct RobotStateMachine_struct *machine, clock_t current_tick_count)
{
	if (!machine->busy_)
	{
		switch (machine->state_)
		{
		case ROBOTSTATE_INITIAL :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_INITIAL, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_TURNING_RIGHT, current_tick_count);
			break;
		case ROBOTSTATE_GOING_FORWARD :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_GOING_FORWARD, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_TURNING_RIGHT, current_tick_count);
			break;
		case ROBOTSTATE_GOING_BACKWARD :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_GOING_BACKWARD, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_TURNING_RIGHT, current_tick_count);
			break;
		case ROBOTSTATE_TURNING_LEFT :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_TURNING_LEFT, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_TURNING_RIGHT, current_tick_count);
			break;
		case ROBOTSTATE_TURNING_RIGHT :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_TURNING_RIGHT, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_TURNING_RIGHT, current_tick_count);
			break;
		case ROBOTSTATE_NOT_MOVING :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_NOT_MOVING, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_TURNING_RIGHT, current_tick_count);
			break;
		default :
			RobotStateMachine_transitionFrom(machine, machine->state_, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_TURNING_RIGHT, current_tick_count);
		}
	}
	else
	{
		machine->pending_event_ = ROBOTSTATEMACHINEEVENT_BUTTONRIGHT;
		machine->event_pending_ = true;
	}
}
void RobotStateMachine_onButtonUp(struct RobotStateMachine_struct *machine, clock_t current_tick_count)
{
	if (!machine->busy_)
	{
		switch (machine->state_)
		{
		case ROBOTSTATE_INITIAL :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_INITIAL, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_GOING_FORWARD, current_tick_count);
			break;
		case ROBOTSTATE_GOING_FORWARD :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_GOING_FORWARD, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_GOING_FORWARD, current_tick_count);
			break;
		case ROBOTSTATE_GOING_BACKWARD :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_GOING_BACKWARD, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_GOING_FORWARD, current_tick_count);
			break;
		case ROBOTSTATE_TURNING_LEFT :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_TURNING_LEFT, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_GOING_FORWARD, current_tick_count);
			break;
		case ROBOTSTATE_TURNING_RIGHT :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_TURNING_RIGHT, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_GOING_FORWARD, current_tick_count);
			break;
		case ROBOTSTATE_NOT_MOVING :
			RobotStateMachine_transitionFrom(machine, ROBOTSTATE_NOT_MOVING, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_GOING_FORWARD, current_tick_count);
			break;
		default :
			RobotStateMachine_transitionFrom(machine, machine->state_, current_tick_count);
			RobotStateMachine_transitionTo(machine, ROBOTSTATE_GOING_FORWARD, current_tick_count);
		}
	}
	else
	{
		machine->pending_event_ = ROBOTSTATEMACHINEEVENT_BUTTONUP;
		machine->event_pending_ = true;
	}
}
