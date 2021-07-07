# Git Copy -XLocal=0
PS1='\w$ '

#also use CF-Tool, Jarvis, and Bitwise CLIs

#Quick CD to Working Directories
function cdcp {
    cd ~/Desktop/Competitive/
}
function cdcf {
    cd ~/Desktop/Competitive/CodeForces/
}

function replace_text {

    if [ -z "$1" ]
        then
            output_error "Internal Error: Could Not Replace Placeholders"
            return
    fi

    month_replace='\$%M%\$'
    day_replace='\$%D%\$'
    year_replace='\$%Y%\$'
    author_replace='\$%U%\$'
    hour_replace='\$%h%\$'
    minute_replace='\$%m%\$'
    second_replace='\$%s%\$'

    month_data="$(date '+%m')"
    day_data="$(date '+%d')"
    year_data="$(date '+%Y')"
    author_data="DespicableMonkey"
    hour_data="$(date '+%H')"
    minute_data="$(date '+%M')"
    second_data="$(date '+%S')"

    sed -i '' -e "s/$month_replace/$month_data/g" $1
    sed -i '' -e "s/$day_replace/$day_data/g" $1
    sed -i '' -e "s/$year_replace/$year_data/g" $1
    sed -i '' -e "s/$author_replace/$author_data/g" $1
    sed -i '' -e "s/$hour_replace/$hour_data/g" $1
    sed -i '' -e "s/$minute_replace/$minute_data/g" $1
    sed -i '' -e "s/$second_replace/$second_data/g" $1
}

#Helper methods for output
function expected_cpp_file {
    RED='\033[1;31m'
    NC='\033[0m' # No Color
    bold=$(tput bold)
    normal=$(tput sgr0)
    printf "${bold}[DM-Compilation]: ${normal}${bold}${RED}Error: ${normal}${NC}Expected c++ File\n"
}
function compilation_successs {
    GREEN='\033[1;32m'
    NC='\033[0m' # No Color
    bold=$(tput bold)
    normal=$(tput sgr0)
    printf "${bold}[DM-Compilation]: ${normal}${bold}${GREEN}Compilation Successful${normal}${NC}\n"
}

function execution_success {
    GREEN='\033[1;32m'
    NC='\033[0m' # No Color
    bold=$(tput bold)
    normal=$(tput sgr0)
    printf "${bold}[DM-Compilation]: ${normal}${bold}${GREEN}Execution Sucessfully Completed${normal}${NC}\n"
}

function compiling {
    GREEN='\033[1;32m'
    NC='\033[0m' # No Color
    bold=$(tput bold)
    normal=$(tput sgr0)
    if [[ "$2" == "DEBUG" ]]
    then
        printf "${bold}[DEBUG] [DM-Compilation]: ${normal}Compiling $1...\n"
    else
        printf "${bold}[DM-Compilation]: ${normal}Compiling $1...\n"
    fi

    if [[ "$3" == "SPACE" ]]
    then
        printf "\n"
    fi
}
function output_error {
    RED='\033[1;31m'
    NC='\033[0m' # No Color
    bold=$(tput bold)
    normal=$(tput sgr0)
    printf "${bold}[DM-Compilation]: ${normal}${bold}${RED}Error: ${normal}${NC}${1}\n"
}

#compile with options and run while debug

function get_extended_file {
    file="$1"
    if [[ "${1}" == *.* ]]
    then
        res="${1%%.*}"
        file="${res}"
    fi
    echo "${file}.cpp"
}
function compile_run_file {
    if [ -z "$1" ]
            then
                output_error "Internal Error: Could Not Find File"
                return
    fi

    if [ -z "$2" ]
            then
                output_error "Internal Error: Could Not Determine Compilation Arguments"
                return
    fi

    file=$(get_extended_file "${1}")

    if [ ! -f $file ]; then
        expected_cpp_file
        return
    fi


    if [[ "$2" == "compile_and_debug" ]]
    then
        compiling "$file" "DEBUG" "SPACE"
        g++ -DLOCAL=1 -O2 -Wall -Wshadow -Wuninitialized -Wfloat-equal -Wno-unused-variable -Wshift-overflow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=undefined -std=c++17 -o a $file && ./a
        execution_success
    elif [[ "$2" == "compile_and_run" ]]
    then
        compiling "$file" "NORMAL" "SPACE"
        g++ -std=c++17 -o a.out $file && ./a.out && rm a.out
        execution_success
    elif [[ "$2" == "compile" ]]
    then
        compiling "$file" "DEBUG" "NO-SPACE"
        time g++ -DLOCAL=1 -O2 -Wall -Wshadow -Wuninitialized -Wfloat-equal -Wno-unused-variable -Wshift-overflow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=undefined -std=c++17 $file
        compilation_successs
    elif [[ "$2" == "compile_output" ]]
    then
        compiling "$file" "DEBUG" "NO-SPACE"
        g++ -DLOCAL=1 -O2 -Wall -Wshadow -Wuninitialized -Wfloat-equal -Wno-unused-variable -Wshift-overflow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=undefined -std=c++17 -o a $file
        compilation_successs
    else
        output_error "Internal Error: Could Not Determine Compilation Configuration"
        return
    fi

}
function cpr {
        if [ -z "$1" ]
            then
                expected_cpp_file
                return
        fi

        compile_run_file $1 "compile_and_debug"

}
#alias method
function compr {
    cpr $1
}

#speed compile without options & run
function cprs {
        if [ -z "$1" ]
            then
                expected_cpp_file
                return
        fi

        compile_run_file $1 "compile_and_run"
}

#compile with options
function comp {
        if [ -z "$1" ]
            then
                expected_cpp_file
                return
        fi

        compile_run_file $1 "compile"
}

function cpro {
    if [ -z "$1" ]
        then
            expected_cpp_file
            return
    fi

    compile_run_file $1 "compile_output"
}

function compo {
    if [ -z "$1" ]
        then
            expected_cpp_file
            return
    fi

   cpro $1
}

#gen input/output files
function genio {
    name="in"
    nameend="ans"
    ext="txt"

    i=1
    if [[ -e $name$i.$ext || -L $name$i.$ext ]] ; then
        while [[ -e $name$i.$ext || -L $name$i.$ext ]] ; do
            let i++
        done
    fi

    name1="in${i}".$ext
    name2="ans${i}".$ext

    touch -- $name1
    touch -- $name2

    subl $name1
    subl $name2

    GREEN='\033[1;32m'
    NC='\033[0m' # No Color
    bold=$(tput bold)
    normal=$(tput sgr0)
    printf "${bold}[DM-Compilation]: ${normal}${bold}${GREEN}Successfully Generated IO Files: ${normal}${NC}${name1} & ${name2}\n"

}

#gen file from template with name $1
function gen {
    if [ -z "$1" ]
        then
            output_error "File Name Expected"
            return
    fi
    file="$1";

    #Remove/change extension
    if [[ "${1}" == *.* ]]
    then
        res="${1%%.*}"
        file="${res}"
    fi

    ext="cpp"

    #Ensure file does not already exist
    if [[ -e $file.$ext || -L $file.$ext ]]
    then
        output_error "File Already Exists"
        return
    fi

    #Text Markup
    GREEN='\033[1;32m'
    NC='\033[0m' # No Color
    bold=$(tput bold)
    normal=$(tput sgr0)

    #template location, copy template to new file
    cat ~/Desktop/Competitive/template.cpp >> $file.$ext
    replace_text $file.$ext
    subl $file.$ext
    printf "${bold}[DM-Compilation]: ${normal}${bold}${GREEN}Successfully Generated File: ${normal}${NC}${file}.${ext}\n"


}

#parse a question with CF-Tool and open in sublime
#currently problem and contest must be seperated
#and full contests cannot be parsed
# $1 = contest ID $2 = problem letter
function parse {
    if [ -z "$1" ]
        then
            output_error "Contest ID Expected"
            return
    fi

    problem_tmp=""

    if [ -z "$2" ]
        then
            problem_tmp="all"
    else
        problem_tmp=$2
    fi

    problem=$(echo "$problem_tmp" | tr '[:upper:]' '[:lower:]')
    if [[ $problem == "all" ]]
    then
        python3 /Users/despicablemonkey/Desktop/DM-Compilation/ensure-validity.py $1
    else
        python3 /Users/despicablemonkey/Desktop/DM-Compilation/ensure-validity.py $1 $problem
    fi

    result=$?

    if [[ $result -eq 100 ]]; then
        parse_helper $1 $problem
    elif [[ $result -lt 100 ]]; then
        file="/Users/despicablemonkey/Desktop/DM-Compilation/problems.txt"
        while read problemID; do
            parse_helper $1 $problemID
        done <$file
    fi


}

function parse_helper {
   if [ -z "$1" ]
       then
           output_error "Internal Error: Contest ID not Found"
           return
   fi
   if [ -z "$2" ]
       then
           output_error "Internal Error: Contest Problem not Found"
           return
   fi 

   cur_prob=$2;

   cdcf

   contestlen=${#1}
   type="Contest";

   if [[ contestlen -gt 5 ]]
       then
           cd Gym
           type="Gym"
   fi

   if [ ! -d $1 ]; then
       mkdir $1
   fi
   cd $1

   if [ ! -d $cur_prob ]; then
       mkdir $cur_prob;
   fi
   cd $cur_prob


   filename="";

   if [[ -e $cur_prob.cpp || -L $cur_prob.cpp ]] ; then
       counter=1
        # while [[ -e $cur_prob$counter.cpp || -L $cur_prob$counter.cpp ]] ; do
        #     let counter++
        # done
        # touch $cur_prob$counter.cpp
        # filename=$cur_prob$counter
        # cat ~/Desktop/Competitive/template.cpp >> $filename.cpp
        # replace_text $filename.cpp
        touch $cur_prob.cpp
        filename=$cur_prob
   else
        touch $cur_prob.cpp
        filename=$cur_prob
        cat ~/Desktop/Competitive/template.cpp >> $filename.cpp
        replace_text $filename.cpp
   fi
   
   subl $filename.cpp

   GREEN='\033[1;32m'
   NC='\033[0m' # No Color
   bold=$(tput bold)
   normal=$(tput sgr0)

   #parse samples
   python3 /Users/despicablemonkey/Desktop/DM-Compilation/parse.py $1 $cur_prob

   # printf "${bold}DM-Compilation: ${normal}${bold}${GREEN}Successfully Generated ${type} $1 Problem $2${normal}\n"



}


#g++ -DLOCAL=1 -O2 -Wall -Wshadow -Wuninitialized -Wfloat-equal -Wshift-overflow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=undefined -std=c++17 -o a.out '${file}' && ./a.out