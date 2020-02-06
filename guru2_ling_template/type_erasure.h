#pragma once

/**
 * Bridge Interface
 * reponsible for ownership and manipulation of the underlying function object
 * FunctionPtr的动多态基础
 */
template <typename R, typename... Args>
class FunctorBridge
{
public:
	virtual ~FunctorBridge() {}
	virtual FunctorBridge* clone() const = 0;
	virtual R invoke(Args... args) const = 0;
};

/**
 * FunctionPtr(std::function<>)
 */
// primary template
template <typename Signature>
class FunctionPtr;

template <typename R, typename... Args>
class FunctionPtr<R(Args...)>
{
private:
	FunctorBridge<R, Args...>* bridge;

public:
	FunctionPtr() : bridge(nullptr) {}
	FunctionPtr(FunctionPtr const& other) : bridge(nullptr)
	{
		if (other.bridge) {
			bridge = other.bridge->clone();
		}
	}

	FunctionPtr(FunctionPtr& other) : FunctionPtr(static_cast<FunctionPtr const&>(other)) {}

	FunctionPtr(FunctionPtr&& other) : bridge(other.bridge) {
		other.bridge = nullptr;
	}

	// construction from arbitrary function objects(which signature is R(Args...))
	template<typename F> FunctionPtr(F&& f);

	FunctionPtr& operator = (FunctionPtr const& other) {
		FunctionPtr tmp(other);
		swap(*this, tmp);
		return *this;
	}

	FunctionPtr& operator = (FunctionPtr&& other) {
		delete bridge;
		bridge = other.bridge;
		other.bridge = nullptr;
		return *this;
	}

	// construction and assignment from arbitrary function objects
	template<typename F> FunctionPtr& operator = (F&& f) {
		FunctionPtr tmp(std::forward<F>(f));
		swap(*this, tmp);
		return *this;
	}

	~FunctionPtr() {
		delete bridge;
	}

	friend void swap(FunctionPtr& fp1, FunctionPtr& fp2) {
		std::swap(fp1.bridge, fp2.bridge);
	}

	explicit operator bool() const {
		return bridge == nullptr;
	}

	// invocation
	R operator()(Args... args) const;
};

/**
 * Type Erasure
 * any type of Functor represent for (R(Args...))
 */
template <typename Functor, typename R, typename... Args>
class SpecificFunctorBridge : public FunctorBridge<R, Args...> {
	Functor functor;

public:
	template<typename FunctorFwd> 
	SpecificFunctorBridge(FunctorFwd&& functor) : functor(std::forward<FunctorFwd>(functor)) {}

	virtual SpecificFunctorBridge* clone() const override {
		return new SpecificFunctorBridge(functor);
	}

	virtual R invoke(Args... args) const override {
		return functor(std::forward<Args>(args)...);
	}
};

template<typename R, typename ...Args>
template<typename F>
inline FunctionPtr<R(Args...)>::FunctionPtr(F && f) : bridge(nullptr)
{
	using Functor = std::decay_t<F>;
	using Bridge = SpecificFunctorBridge<Functor, R, Args...>;
	bridge = new Bridge(std::forward<F>(f));
}

template<typename R, typename ...Args>
inline R FunctionPtr<R(Args...)>::operator()(Args ...args) const
{
	return bridge->invoke(std::forward<Args>(args)...);
}
