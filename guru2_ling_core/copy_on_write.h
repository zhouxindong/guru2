#pragma once

#include<algorithm>

/**
 * 1. 第一个版本，简单，但是也许性能有损
 */
class String
{
public:
	String() : buf_(nullptr), len_(0), used_(0) {}
	~String() {}
	String(const String& other) :
		buf_(new char[other.len_]),
		len_(other.len_),
		used_(other.used_)
	{
		std::copy(other.buf_, other.buf_ + used_, buf_);
	}

	void Append(char c) {
		Reserve(used_ + 1);
		buf_[used_++] = c;
	}

private:
	char* buf_;
	size_t len_;
	size_t used_;

private:
	void Reserve(size_t n)
	{
		if (len_ < n)
		{
			size_t newLen = std::max((size_t)(len_ * 1.5), n);
			char* newbuf = new char[newLen];
			std::copy(buf_, buf_ + used_, newbuf);

			delete[] buf_;
			buf_ = newbuf;
			len_ = newLen;
		}
	}
};

/**
 * 2. 第二个版本: 写时复制
 */
class StringBuf2
{
public:
	StringBuf2() : buf(0), len(0), used(0), refs(1) {}
	~StringBuf2() { delete[] buf; }

	void Reserve(size_t n)
	{
		if (len < n)
		{
			size_t newlen = std::max(size_t(len*1.5), n);
			char* newbuf = new char[newlen];
			std::copy(buf, buf + used, newbuf);

			delete[] buf;
			buf = newbuf;
			len = newlen;
		}
	}

	char* buf;
	size_t len;
	size_t used;
	unsigned refs;

	StringBuf2(const StringBuf2&) = delete;
	StringBuf2& operator=(const StringBuf2&) = delete;
};

class String2
{
public:
	String2() : data_(new StringBuf2) {}
	~String2() {
		if (--data_->refs < 1)
		{
			delete data_;
		}
	}

	String2(const String2& other) : data_(other.data_)
	{
		++data_->refs; // 此时为浅拷贝，仅在修改时才分离实体，进行深拷贝
	}

	void Append(char c)
	{
		AboutToModify(data_->used + 1);
		data_->buf[data_->used++] = c;
	}

	size_t Length() const
	{
		return data_->used;
	}

	char& operator[] (size_t);

	const char operator[] (size_t) const;

private:
	StringBuf2* data_;

	void AboutToModify(size_t n)
	{
		if (data_->refs > 1)
		{
			StringBuf2* newbuf = new StringBuf2;
			newbuf->Reserve(std::max(data_->len, n));
			std::copy(data_->buf, data_->buf + data_->used, newbuf->buf);
			newbuf->used = data_->used;

			--data_->refs;
			data_ = newbuf;
		}
		else
		{
			data_->Reserve(n);
		}
	}
};