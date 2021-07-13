# Git Copy -XLocal=0
import requests
from bs4 import BeautifulSoup
import os
import sys

def output_DM(text):
	print("\033[97m" + "[DM-Compilation]: " + "\033[0m" + text)

def output_error(error_text):
	output_DM("\033[91m" + error_text + "\033[0m")
def output_suc(success_text):
	output_DM("\033[92m" + success_text + "\033[0m")

def parse(contest_id, contest_prob):

	if(len(str(contest_id)) < 1 or not str(contest_id).isnumeric()):
		output_error("Invalid Contest ID")
		sys.exit(1);
	if(len(str(contest_prob)) < 1 or not str(contest_prob).isalnum() or len(str(contest_prob)) > 2):
		output_error("Invalid Contest Problem")
		sys.exit(1);

	c_type = "Contest"
	c_url = "contest"

	if(len(str(contest_id)) > 5):
		c_type = "Gym"
		c_url = "gym"

	URL = "https://codeforces.com/"+c_url+"/"+str(contest_id)+"/problem/"+contest_prob
	page = requests.get(URL)

	soup = BeautifulSoup(page.content, "html.parser")

	input_t = soup.find_all("div", {"class": "input"})
	output_t = soup.find_all("div", {"class": "output"})

	input_data = []
	output_data = []

	for test in input_t:
		io = test.find_all("pre")
		for item in io:
			item = str(item).replace('<pre>', '')
			item = str(item).replace('</pre>', '')
			item = str(item).replace('<br/>', '\n')
			input_data.append(item);
	for test in output_t:
		io = test.find_all("pre")
		for item in io:
			item = str(item).replace('<pre>', '')
			item = str(item).replace('</pre>', '')
			item = str(item).replace('<br/>', '\n')
			output_data.append(item);



	if len(input_data) == 0:
		output_error("No Samples Detected")
		sys.exit(1)

	cwd = os.getcwd()

	counter = 0;
	for _ in range(1, 101):
		counter += 1;
		for fname in os.listdir(cwd):
			if(fname == ("in" + str(counter) + ".txt") or fname == ("ans" + str(counter) + ".txt")):
				break
		else:
			break

	if counter == 101:
		output_error("Too Many I/O Files");
		sys.exit(1)
	if len(input_data) != len(output_data):
		output_error("Unbalanced I/O")
		sys.exit(1)

	for i in range(counter, counter + len(input_data)):
		input_file_name = "in" + str(i) + ".txt"
		output_file_name = "ans" + str(i) + ".txt"

		with open(input_file_name, 'w') as fp:
			fp.write(input_data[i - counter])
		with open(output_file_name, 'w') as fp:
			fp.write(output_data[i - counter])

	output_suc("Successfully Parsed [Problem "+str(contest_prob)+"] from ["+c_type+" "+str(contest_id)+"] with "+str(len(input_data))+" samples.")


if __name__ == '__main__':
	if len(sys.argv) >= 3:
		parse(sys.argv[1], sys.argv[2])
	else:
		if(len(sys.argv) == 1):
			output_error("Contest ID Expected");
		else:
			output_error("Problem ID Expected")
