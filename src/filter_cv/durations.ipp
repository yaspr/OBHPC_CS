double append_durations(std::vector<double> *durations, double duration) {
	static size_t i = 0;

	if (durations->size() < 100) {
		durations->push_back(duration);
	} else {
		durations->operator[](i) = duration;
		i = (i + 1) % durations->size();
	}

	double acc = 0.0;
	for (size_t i = 0; i < durations->size(); i++) {
		acc += durations->operator[](i);
	}
	return acc / ((double)durations->size());
}


