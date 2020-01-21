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
** usage: name -> get_name|set_name (_name)
** readonly means no setter
** _INIT means use initialized value
*/
#pragma region auto_property

#define _DEF_PROPERTY_INIT(type, name, value) type name##_{ value };
#define _DEF_PROPERTY(type, name) type name##_;

#define _GET_PROPERTY(type, name) type name() const {return name##_;}
#define _GET_PROPERTY_CONSTREF(type, name) const type & name() const {return name##_;}
#define _GET_PROPERTY_REF(type, name) type & name() const {return name##_;}

#define _SET_PROPERTY(type, name) void set_##name(const type & value){name##_ = value;}

#define _PROPERTY(type, name) \
private:\
	_DEF_PROPERTY(type, name) \
public:\
	_GET_PROPERTY_CONSTREF(type, name) \
	_SET_PROPERTY(type, name)

#define _PROPERTY_INIT(type, name, value) \
private:\
	_DEF_PROPERTY_INIT(type, name, value) \
public:\
	_GET_PROPERTY_CONSTREF(type, name) \
	_SET_PROPERTY(type, name)

#define _PROPERTY_READONLY(type, name) \
private:\
	_DEF_PROPERTY(type, name) \
public:\
	_GET_PROPERTY_CONSTREF(type, name)

#define _PROPERTY_READONLY_INIT(type, name, value) \
private:\
	_DEF_PROPERTY_INIT(type, name, value) \
public:\
	_GET_PROPERTY_CONSTREF(type, name)

#pragma endregion

#endif // _GURU2_GVALS2_H_