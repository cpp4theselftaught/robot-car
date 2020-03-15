/***************************************************************************
 *                 THIS IS GENERATED CODE -- DO NOT MODIFY                 *
 ***************************************************************************/
#ifndef generated_robot_h
#define generated_robot_h

#include <stdbool.h>
#include <time.h>

enum RobotStates_enum {
	  ROBOTSTATE_DANCE_0
	, ROBOTSTATE_DANCE_1
	, ROBOTSTATE_DANCE_10
	, ROBOTSTATE_DANCE_2
	, ROBOTSTATE_DANCE_3
	, ROBOTSTATE_DANCE_4
	, ROBOTSTATE_DANCE_5
	, ROBOTSTATE_DANCE_6
	, ROBOTSTATE_DANCE_7
	, ROBOTSTATE_DANCE_8
	, ROBOTSTATE_DANCE_9
	, ROBOTSTATE_GOING_BACKWARD
	, ROBOTSTATE_GOING_FORWARD
	, ROBOTSTATE_INITIAL
	, ROBOTSTATE_NOT_MOVING
	, ROBOTSTATE_TURNING_LEFT
	, ROBOTSTATE_TURNING_RIGHT
	};
enum RobotStateMachineEvents_enum {
	  ROBOTSTATEMACHINEEVENT_BUTTON3
	, ROBOTSTATEMACHINEEVENT_BUTTONDOWN
	, ROBOTSTATEMACHINEEVENT_BUTTONLEFT
	, ROBOTSTATEMACHINEEVENT_BUTTONOK
	, ROBOTSTATEMACHINEEVENT_BUTTONRIGHT
	, ROBOTSTATEMACHINEEVENT_BUTTONUP
	};

struct RobotStateMachine_struct;
typedef void (*RobotStateMachineCallback)(struct RobotStateMachine_struct*, void*);

struct RobotStateMachine_struct
{
	bool started_;
	bool deadline_set_;
	bool busy_;
	bool event_pending_;
	bool transition_pending_;
	clock_t deadline_;
	enum RobotStates_enum state_;
	enum RobotStates_enum next_state_;
	void *user_;
	clock_t latest_update_;
	enum RobotStateMachineEvents_enum pending_event_;
	unsigned int loop_counter_[4];
	unsigned int loop_level_;
	clock_t clock_freq_;
	RobotStateMachineCallback backward_callback_;
	RobotStateMachineCallback forward_callback_;
	RobotStateMachineCallback left_callback_;
	RobotStateMachineCallback right_callback_;
	RobotStateMachineCallback stop_callback_;
};

int RobotStateMachine_init(
	  struct RobotStateMachine_struct *machine
	, void *user_data
	, RobotStateMachineCallback backward
	, RobotStateMachineCallback forward
	, RobotStateMachineCallback left
	, RobotStateMachineCallback right
	, RobotStateMachineCallback stop
	, clock_t clock_freq
	);
void RobotStateMachine_fini(struct RobotStateMachine_struct *machine);
clock_t RobotStateMachine_update(struct RobotStateMachine_struct *machine, clock_t current_tick_count);
void RobotStateMachine_onButton3(struct RobotStateMachine_struct *machine, clock_t current_tick_count);
void RobotStateMachine_onButtonDown(struct RobotStateMachine_struct *machine, clock_t current_tick_count);
void RobotStateMachine_onButtonLeft(struct RobotStateMachine_struct *machine, clock_t current_tick_count);
void RobotStateMachine_onButtonOK(struct RobotStateMachine_struct *machine, clock_t current_tick_count);
void RobotStateMachine_onButtonRight(struct RobotStateMachine_struct *machine, clock_t current_tick_count);
void RobotStateMachine_onButtonUp(struct RobotStateMachine_struct *machine, clock_t current_tick_count);

#endif
