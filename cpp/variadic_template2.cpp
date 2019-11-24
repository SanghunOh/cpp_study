#include	<iostream>
#include	<cstring>
#include	<string>


size_t GetStringSize(const char* s){
	return strlen(s);
}

size_t GetStringSize(std::string s){
	return s.size();
}

template <typename T, typename... Ts>
size_t GetStringSize(const T& s, const Ts... strs){
	return GetStringSize(s) + GetStringSize(strs...);
}

void AppendToString(std::string* concat_str){
	return;
}

/*template <typename T, typename... Ts>
void AppendToString(const T& concat_str, Ts... strs){
	concat_str->append(s);
	AppendToString(concat_str, strs...);
}
*/
template <typename T, typename... Ts>
void AppendToString(std::string* concat_str, const T&s, Ts... strs){
	concat_str->append(s);
	AppendToString(concat_str, strs...);
}

template <typename T>
std::string StrCat(const T& s){
	return std::string(s);
}

template <typename T, typename... Ts>
std::string StrCat(const T& s, Ts... strs){
	size_t total_size = GetStringSize(s, strs...);

	std::string concat_str;
	concat_str.reserve(total_size);

	concat_str = s;
	AppendToString(&concat_str, strs...);
	
	return concat_str;
}


int main(){
	std::cout << StrCat("this asdfasdf", " ", "is", " ", std::string("a"), " ", std::string("sentence"));
}
