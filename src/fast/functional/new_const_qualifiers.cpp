constinit int j{}; // implicitly static BUT NOT CONST! (constinit is not const)
//consteval int k{}; // variables cannot be declared consteval

auto inc() {
	constinit static int i{};
	return i++;
}

consteval auto hello() {
	return 42;
}

constinit auto lambda = [](auto val) {
    return j += val;
};