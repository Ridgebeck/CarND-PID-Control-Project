#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;

	p_error = 0;
	i_error = 0;
	d_error = 0;

	/*
	// Twiddle parameters
    twiddle = false;
    dp = {0.1*Kp, 0.1*Kd, 0.1*Ki};
    step = 1;
    param_index = 2;  // this will wrap back to 0 after the first twiddle loop
    n_settle_steps = 100;
    n_eval_steps = 2000;
    total_error = 0;
    best_error = std::numeric_limits<double>::max();
    tried_adding = false; 
    tried_subtracting = false;
    */
}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;

}

double PID::TotalError() {

	return -Kp * p_error - Ki * i_error - Kd * d_error;
}

