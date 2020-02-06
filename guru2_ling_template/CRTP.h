#pragma once
template <typename Derivd>
class CuriousBase {
};

class Curious : public CuriousBase<Curious> {
};

template <typename T>
class CuriousTemplate : public CuriousBase<CuriousTemplate<T>> {
};

/**
 * ͨ��ģ������������ഫ�ݸ�����࣬��������������ƾͿ��Զ���������Ĳ���
 * ͨ��ʹ�ó���: ��ֻ�ܶ���Ϊ��Ա������ʵ��ģ�黯(���캯���������������±����������������������Ĳ���)
 */

/**
 * ʾ��1: ��ʵ��������(��CRTP�޷�����ͬ��������)
 */
template <typename CountedType>
class ObjectCounter {
private:
	inline static std::size_t count = 0;

protected:
	ObjectCounter() {
		++count;
	}

	ObjectCounter(ObjectCounter<CountedType> const&) {
		++count;
	}

	ObjectCounter(ObjectCounter<CountedType>&&) {
		++count;
	}

	~ObjectCounter() {
		--count;
	}

public:
	static std::size_t live() {
		return count;
	}
};

template <typename CharT>
class MyString : public ObjectCounter<MyString<CharT>> {
};

// MyString<char>::live()

/**
 * ʾ��2: ����ĳ����������ز���ʵ��
 */
template <typename Derived>
class EqualityComparable {
public:
	friend bool operator != (Derived const& x1, Derived const& x2) {
		return !(x1 == x2);
	}
};

class X : public EqualityComparable<X>
{
public:
	friend bool operator == (X const& x1, X const& x2) {
		return true;
	}
};

/**
 * Facades
 */
template <
	typename Derived,
	typename Value,
	typename Category,
	typename Reference = Value&,
	typename Distance = std::ptrdiff_t>
class IteratorFacade 
{	
public:
	using value_type = typename std::remove_const<Value>::type;
	using reference = Reference;
	using pointer = Value*;
	using difference_type = Distance;
	using iterator_category = Category;

	// input iterator interface
	reference operator *() const {}
	pointer operator ->() const {}
	Derived& operator ++() {}
	Derived operator ++(int) {}
	friend bool operator == (IteratorFacade const& lhs, IteratorFacade const& rhs) {}

	// bidirectional iterator interface
	Derived& operator --()  {}
	Derived operator --(int) {}

	// utility
	Derived& asDerived() {
		return *static_cast<Derived*>(this);
	}

	Derived const& asDerived() const {
		return *static_cast<Derived const*>(this);
	}
};