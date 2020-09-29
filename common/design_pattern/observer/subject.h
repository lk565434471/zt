#pragma once

#include "common.h"
#include "design_pattern/noncopyable/noncopyable.h"

namespace common {
namespace design_pattern {

template <typename Function>
class Subject
	: private NonCopyable
{
public:

	Subject() {}

	~Subject() {}

public:

	uint32 attach(Function &&func) {
		return this->assgin(func);
	}

	uint32 attach(const Function &func) {
		return this->assgin(func);
	}

	void detach(uint32 id) {
		auto it = this->observers_.find(id);

		if (it == this->observers_.end()) {
			return;
		}

		this->observers_.erase(it);
	}

	template <typename ...Arguments>
	void notify(Arguments &&...args) {
		for (auto it = this->observers_.begin(); it != this->observers_.end(); ++it) {
			it->second(std::forward<Arguments>(args)...);
		}
	}

private:

	template <typename Interface>
	uint32 assgin(Interface &&interface) {
		uint32 id = ++Subject<Function>::observer_id_;
		this->observers_.emplace(id, std::forward<Interface>(interface));

		return id;
	}

private:

	static uint32 observer_id_;

	std::map<uint32, Function> observers_;
};

template <typename Function>
uint32 Subject<Function>::observer_id_ = 0;

} // namespace design_pattern
} // namespace common