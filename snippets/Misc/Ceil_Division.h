template<class T, class U> T cdiv(T a, U b) { 
	return a/b+((a^b)>0&&a%b); 
} // divide a by b rounded up