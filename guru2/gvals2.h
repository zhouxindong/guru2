#pragma once
#ifndef _GURU2_GVALS2_H_
#define _GURU2_GVALS2_H_

#define _GURU2_BEGIN namespace guru2 {
#define _GURU2_END   }
#define _GURU2  ::guru2::

#define _STD_BEGIN namespace std {
#define _STD_END   }
#define _STD ::std::

/*
** defined class data member
** generated data set|get function automatic
** usage: name -> name|set_name (name_)
** readonly means no setter
** _INIT means use initialized value
*/
#pragma region auto_property

#define DEF_PROPERTY_INIT(type, name, value) type name##_{ value };
#define DEF_PROPERTY(type, name) type name##_;

#define GET_PROPERTY(type, name) type name() const {return name##_;}
#define GET_PROPERTY_CONSTREF(type, name) const type & name() const {return name##_;}
#define GET_PROPERTY_REF(type, name) type & name() const {return name##_;}

#define SET_PROPERTY(type, name) void set_##name(const type & value){name##_ = value;}

#define PROPERTY(type, name) \
private:\
	DEF_PROPERTY(type, name) \
public:\
	GET_PROPERTY_CONSTREF(type, name) \
	SET_PROPERTY(type, name)

#define PROPERTY_INIT(type, name, value) \
private:\
	DEF_PROPERTY_INIT(type, name, value) \
public:\
	GET_PROPERTY_CONSTREF(type, name) \
	SET_PROPERTY(type, name)

#define PROPERTY_READONLY(type, name) \
private:\
	DEF_PROPERTY(type, name) \
public:\
	GET_PROPERTY_CONSTREF(type, name)

#define PROPERTY_READONLY_INIT(type, name, value) \
private:\
	DEF_PROPERTY_INIT(type, name, value) \
public:\
	GET_PROPERTY_CONSTREF(type, name)

#pragma endregion

#endif // _GURU2_GVALS2_H_