# COMP4300 Lab 3 - test reg_file (15 ns read delay)
# Each operation: set controls with clock = 0, then raise clock for 50 ns.
vsim -voptargs=+acc work.reg_file
add wave -radix binary      /reg_file/clock
add wave -radix binary      /reg_file/readnotwrite
add wave -radix unsigned    /reg_file/reg_number
add wave -radix hexadecimal /reg_file/data_in
add wave -radix hexadecimal /reg_file/data_out

force clock 0
run 20ns

# ---------------- WRITES (readnotwrite = 0) ----------------
# write R0 = 11111111
force readnotwrite 0
force reg_number 00000
force data_in 16#11111111
force clock 1
run 50ns
force clock 0
run 20ns

# write R5 = AAAAAAAA
force reg_number 00101
force data_in 16#AAAAAAAA
force clock 1
run 50ns
force clock 0
run 20ns

# write R31 = 12345678
force reg_number 11111
force data_in 16#12345678
force clock 1
run 50ns
force clock 0
run 20ns

# ---------------- READS (readnotwrite = 1, data_in ignored) ----------------
force readnotwrite 1
force data_in 16#FFFFFFFF

# read R5 -> data_out AAAAAAAA (15 ns after clock rises)
force reg_number 00101
force clock 1
run 50ns
force clock 0
run 20ns

# read R0 -> data_out 11111111
force reg_number 00000
force clock 1
run 50ns
force clock 0
run 20ns

# read R31 -> data_out 12345678
force reg_number 11111
force clock 1
run 50ns
force clock 0
run 20ns

# read R7 (never written) -> data_out 00000000
force reg_number 00111
force clock 1
run 50ns
force clock 0
run 20ns

# ---------------- OVERWRITE then READ ----------------
# write R5 = 55555555 (replaces AAAAAAAA)
force readnotwrite 0
force reg_number 00101
force data_in 16#55555555
force clock 1
run 50ns
force clock 0
run 20ns

# read R5 -> data_out 55555555
force readnotwrite 1
force data_in 16#FFFFFFFF
force clock 1
run 50ns
force clock 0
run 20ns

wave zoom full
