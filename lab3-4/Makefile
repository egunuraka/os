n1_1:
	gcc processes/new_process.c -o n1_1.out
n1_2:
	gcc processes/new_process_system.c -o n1_2.out
n1_3:
	gcc processes/new_process_file.c -o n1_3.out
n1_4:
	gcc processes/new_process_file2.c -o n1_4.out

n2:
	gcc processes/new_process_once.c -o n2_1.out

n3_1:
	gcc processes/new_process_for5.c -o n3_1.out
n3_2:
	gcc processes/new_process_for100.c -o n3_2.out

n4:
	gcc processes/new_process_for1000.c -o n4.out

n5:
	gcc processes/child_process.c -o child.out
	gcc processes/parent_process.c -o parent.out

n9_1:
	gcc processes/parent_wait.c -o parent.out
	gcc processes/child_process.c -o child1.out
	gcc processes/child_process_sleep10.c -o child2.out
	gcc processes/child_process_sleep15.c -o child3.out
n9_2:
	gcc processes/parent_wait2.c -o parent.out
	gcc processes/child_process.c -o child1.out
	gcc processes/child_process_sleep10.c -o child2.out
	gcc processes/child_process_sleep15.c -o child3.out

n10_1:
	gcc processes/parent_sheduler.c -o parent.out
	gcc processes/child_sheduler2.c -o child1.out
	gcc processes/child_sheduler2.c -o child2.out
n10_3:
	gcc processes/parent_sheduler_rr.c -o parent.c
	gcc processes/child_sheduler2.c -o child1.out
	gcc processes/child_sheduler2.c -o child2.out
n10_4:
	gcc processes/child_sheduler2.c -o child1.out
	gcc processes/child_sheduler2.c -o child2.out
	gcc processes/parent_sheduler_diff.c -o parent.c
n11_1:
	gcc processes/parent_quant_other.c -o parent.out
	gcc processes/child_quant.c -o child.out
n11_2:
	gcc processes/parent_quant_rr.c -o parent.out
	gcc processes/child_quant.c -o child.out
n11_3:
	gcc processes/parent_quant_fifo.c -o parent.out
	gcc processes/child_quant.c -o child.out

n12_1:
	gcc processes/parent_file_rr.c -o parent.out
	gcc processes/child_file.c -o child.out
	echo "lb 3-4 os" > infile.txt
n12_2:
	gcc processes/parent_file_fifo.c -o parent.out
	gcc processes/child_file.c -o child.out
	echo "lb 3-4 os" > infile.txt

n13:
	gcc related/child1.c -o child1.out
	gcc related/child2.c -o child2.out
	gcc related/child3.c -o child3.out
	gcc related/parent.c -o parent.out

n13_sig:
	gcc signals/child1.c -o child1.out
	gcc signals/child2.c -o child2.out
	gcc signals/child3.c -o child3.out
	gcc signals/parent.c -o parent.out
n13_sig2:
	gcc signals/child1_timer.c -o child1.out
	gcc signals/child2_timer.c -o child2.out
	gcc signals/parent_timer.c -o parent.out

n15:
	gcc signals/nice_ranges.c -o nice.out

n16:
	gcc signals/nohup.c -o nohup_run.out

n18:
	gcc threads/thread.c -o thread.out

n20:
	gcc threads/thread_sigusr.c -o thread.out

n21:
	gcc threads/thread_soft_kill.c -o thread.out

n22_1:
	gcc threads/ctrl_once.c -o ./thread.out

n22_2:
	gcc threads/ctrl_c_twice.c -o ./thread.out

n24_1:
	gcc threads/t24_rr.c -o thread.out
n24_2:
	gcc threads/t24_fifo.c -o thread.out
n24_3:
	gcc threads/t24_fifo_eq.c -o thread.out
clean:
	rm -f *.out parent child file *.txt
