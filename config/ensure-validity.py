# Git Copy -XLocal=0
import requests
from bs4 import BeautifulSoup
import os
import sys
import json

def output_DM(text):
	print("\033[97m" + "[DM-Compilation]: " + "\033[0m" + text)

def output_error(error_text):
	output_DM("\033[91m" + error_text + "\033[0m")
def output_suc(success_text):
	output_DM("\033[92m" + success_text + "\033[0m")

def parse(contest_id, contest_prob = "AL"):

	if(len(str(contest_id)) < 1 or not str(contest_id).isnumeric()):
		output_error("Invalid Contest ID")
		sys.exit(999);
	if(len(str(contest_prob)) < 1 or not str(contest_prob).isalnum() or len(str(contest_prob)) > 2):
		output_error("Invalid Contest Problem")
		sys.exit(999);

	c_type = "Contest"
	c_url = "contest"

	if(len(str(contest_id)) > 5):
		c_type = "Gym"
		c_url = "gym"

	URL = "https://codeforces.com/"+c_url+"/"+str(contest_id)+"/problem/"+contest_prob

	URL = "";
	if(c_url == "gym"):
		URL = "https://codeforces.com/api/contest.standings?gym=true&contestId="+str(contest_id)+"&from=1&count=1"
	else:	
		URL = "https://codeforces.com/api/contest.standings?contestId="+str(contest_id)+"&from=1&count=1"

	response = requests.get(URL)

	data = response.json();


	if(data["status"] != "OK"):
		output_error("Could not find Contest")
		sys.exit(999);

	result = data["result"];
	problems = result["problems"]

	problem_index = []

	for problem in problems:
		problem_index.append(problem["index"].lower())

	if (contest_prob != "AL"):
		if(not (contest_prob in problem_index)):
			output_error("Could not find Problem")
			sys.exit(999)
		else:
			with open("/Users/despicablemonkey/Desktop/DM-Compilation/problems.txt", 'w') as fp:
				fp.write(str(contest_prob)+"\n")
			sys.exit(100)
	else:
		with open("/Users/despicablemonkey/Desktop/DM-Compilation/problems.txt", 'w') as fp:
				for problem in problem_index[::-1]:
					fp.write(str(problem)+"\n")
		sys.exit(len(problem_index))


if __name__ == '__main__':
	if len(sys.argv) >= 3:
		parse(sys.argv[1], sys.argv[2])
	elif len(sys.argv) >= 2:
		parse(sys.argv[1])
	else:
		if(len(sys.argv) == 1):
			output_error("Contest ID Expected");
