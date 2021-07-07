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
    printf "${bold}DM-Compilation: ${normal}${bold}${RED}Error: ${normal}${NC}Expected c++ File\n"
}
function compilation_successs {
    GREEN='\033[1;32m'
    NC='\033[0m' # No Color
    bold=$(tput bold)
    normal=$(tput sgr0)
    printf "${bold}DM-Compilation: ${normal}${bold}${GREEN}Compilation Successful${normal}${NC}\n"
}

function execution_success {
    GREEN='\033[1;32m'
    NC='\033[0m' # No Color
    bold=$(tput bold)
    normal=$(tput sgr0)
    printf "${bold}DM-Compilation: ${normal}${bold}${GREEN}Execution Sucessfully Completed${normal}${NC}\n"
}

function compiling {
    GREEN='\033[1;32m'
    NC='\033[0m' # No Color
    bold=$(tput bold)
    normal=$(tput sgr0)
    if [[ "$2" == "DEBUG" ]]
    then
        printf "${bold}[DEBUG] DM-Compilation: ${normal}Compiling $1...\n"
    else
        printf "${bold}DM-Compilation: ${normal}Compiling $1...\n"
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
    printf "${bold}DM-Compilation: ${normal}${bold}${RED}Error: ${normal}${NC}${1}\n"
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
    printf "${bold}DM-Compilation: ${normal}${bold}${GREEN}Successfully Generated IO Files: ${normal}${NC}${name1} & ${name2}\n"

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
    printf "${bold}DM-Compilation: ${normal}${bold}${GREEN}Successfully Generated File: ${normal}${NC}${file}.${ext}\n"


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
    if [ -z "$2" ]
        then
            output_error "Contest Problem Expected"
            return
    fi

    problem=$(echo "$2" | tr '[:upper:]' '[:lower:]')
    cdcf

    cf parse $1 $problem

    contestlen=${#1}
    type="Contest";

    if [[ contestlen -gt 5 ]]
        then
            cd Gym
            type="Gym"
    fi

    subl $1/$problem/$problem.cpp
    cd $1/$problem

    GREEN='\033[1;32m'
    NC='\033[0m' # No Color
    bold=$(tput bold)
    normal=$(tput sgr0)

    printf "${bold}DM-Compilation: ${normal}${bold}${GREEN}Successfully Generated ${type} $1 Problem $2${normal}\n"

}


#g++ -DLOCAL=1 -O2 -Wall -Wshadow -Wuninitialized -Wfloat-equal -Wshift-overflow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=undefined -std=c++17 -o a.out '${file}' && ./a.out