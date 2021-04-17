a measurement (process variable) to be controlled at a desired (set point) by continuously adjusting a (control output). 

process_variable_PV = gyro_revel_result
control_output = servo_signal
setpoint_SP = gyro_level_0
max_signal = 2000
min_signal = 1000
total_signal = max_signal - min_signal

command_rate = current_signal - previous_signal

p = 0.01

if pitch < 0

elsif pitch > 0

else
	# do nothing
end

else:
	# do nothing
desired_position = 00
output_signal = 1500
total_error = 0
prev_error = 0
prev_time = 0
error_diff = 0
while not is_level
	current_pos = get_roll_position()

	error = desired_position - current_pos
	cur_time = get_current_time()
	total_error = total_error + error
	duration = cur_time - prev_time
	error_diff = prev_error - error / duration

	output_signal = p * prev_error + total_error * i + d * error_diff

	output(output_signal)

	is_level = error < error_threshold
end