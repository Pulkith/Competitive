PS1='\w$ '

#also use CF-Tool, Jarvis, and Bitwise CLIs

#Quick CD to Working Directories
function cdcp {
    cd ~/Desktop/Competitive/
}
function cdcf {
    cd ~/Desktop/Competitive/CodeForces/
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
    printf "${bold}DM-Compilation: ${normal}${bold}${GREEN}Execution Successful${normal}${NC}\n"
}

#compile with options and run while debug
function cpr {
        if [[ "$1" == *.cpp ]]
        then
            compilation_successs
            printf "\n"
            g++ -DLOCAL=1 -O2 -Wall -Wshadow -Wuninitialized -Wfloat-equal -Wshift-overflow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=undefined -std=c++17 -o a.out $1 && ./a.out && rm a.out
            execution_success
        else
            expected_cpp_file
        fi

}

#alias method
function compr {
    cpr $1
}

#speed compile without options & run
function cprs {
        RED='\033[0;31m'
        NC='\033[0m' # No Color
        if [[ "$1" == *.cpp ]]
        then
            compilation_successs
            printf "\n"
            g++ -std=c++17 -o a.out $1 && ./a.out && rm a.out
            execution_success
        else
            expected_cpp_file
        fi
}

#compile with options
function comp {
        RED='\033[0;31m'
        GREEN='\033[0;32m'
        NC='\033[0m' # No Color
        if [[ "$1" == *.cpp ]]
        then
            time g++ -DLOCAL=1 -O2 -Wall -Wshadow -Wuninitialized -Wfloat-equal -Wshift-overflow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=undefined -std=c++17 $1
            compilation_successs
        else
            expected_cpp_file
        fi 
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
function output_error {
    RED='\033[1;31m'
    NC='\033[0m' # No Color
    bold=$(tput bold)
    normal=$(tput sgr0)
    printf "${bold}DM-Compilation: ${normal}${bold}${RED}Error: ${normal}${NC}${1}\n"
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
    #open new file
    subl $file.$ext
    printf "${bold}DM-Compilation: ${normal}${bold}${GREEN}Successfully Generated File: ${normal}${NC}${file}.${ext}\n"


}


#g++ -DLOCAL=1 -O2 -Wall -Wshadow -Wuninitialized -Wfloat-equal -Wshift-overflow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=undefined -std=c++17 -o a.out '${file}' && ./a.out
