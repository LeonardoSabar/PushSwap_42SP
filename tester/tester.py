#!/usr/bin/env python3

import random
import subprocess
import sys

# n_values = [7]
n_values = [3, 5, 100]
# n_values = range(30)
# n_values = [x for x in range(3, 101) if x == 3 or x == 5 or x % 10 == 0]
range_start = -500
range_end = 500

for n in n_values:
	outputs = []
	max_sequence = []
	min_sequence = []
	print(f"For n = {n}:", flush=True)
	# print(f"\n\nFor n = {n}:\n", file=sys.stderr, flush=True)

	for _ in range(100):
		print(".", end="", flush=True)
		numbers = random.sample(range(range_start, range_end + 1), n)
		numbers_string = ' '.join(map(str, numbers))

		output = subprocess.check_output("./push_swap " + numbers_string, shell=True)
		output = output.decode()

		checker = subprocess.check_output(f'./push_swap {numbers_string} | ./checker_linux {numbers_string}', shell=True)
		checker = checker.decode()

		if (checker == "KO\n"):
			print(f"ko sequence: {numbers_string}")
			exit()

		num_newlines = output.count('\n')
		outputs.append(num_newlines)

		if num_newlines == max(outputs):
			max_sequence = numbers
		if num_newlines == min(outputs):
			min_sequence = numbers

	averages = sum(outputs) / len(outputs)
	maximum = max(outputs)
	minimum = min(outputs)

	print("Average:", averages)
	print("Maximum:", maximum)
	print("Minimum:", minimum)
	print()
	print("Maximum Sequence:", *max_sequence)
	print()
	print("Minimum Sequence:", *min_sequence)
	print()
	print(flush=True)
