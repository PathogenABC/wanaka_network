/*
 * Value.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef VALUE_H_
#define VALUE_H_

#include <vector>
#include <map>

namespace wanaka {

class Value;

typedef std::vector<Value> ValueArray;
typedef std::map<std::string, Value> ValueDict;

class Value {
public:
	static const Value Null;

	enum Type {
		NONE = 0, BYTE, INTEGER, FLOAT, DOUBLE, BOOLEAN, STRING, VECTOR, MAP
	};

	Value();
	explicit Value(unsigned char v);
	explicit Value(int v);
	explicit Value(float v);
	explicit Value(double v);
	explicit Value(bool v);
	explicit Value(const char* v);
	explicit Value(const std::string& v);

	explicit Value(const ValueArray& v);
	explicit Value(ValueArray&& v);

	explicit Value(const ValueDict& v);
	explicit Value(ValueDict&& v);

	Value(const Value& other);
	Value(Value&& other);
	~Value();

	// assignment operator
			Value& operator= (const Value& other);
			Value& operator= (Value&& other);

			Value& operator= (unsigned char v);
			Value& operator= (int v);
			Value& operator= (float v);
			Value& operator= (double v);
			Value& operator= (bool v);
			Value& operator= (const char* v);
			Value& operator= (const std::string& v);

			Value& operator= (const ValueArray& v);
			Value& operator= (ValueArray&& v);

			Value& operator= (const ValueDict& v);
			Value& operator= (ValueDict&& v);

			// equal operator
			bool operator!= (const Value& v);
			bool operator!= (const Value& v) const;
			bool operator== (const Value& v);
			bool operator== (const Value& v) const;

			unsigned char asByte() const;
			int asInt() const;
			float asFloat() const;
			double asDouble() const;
			bool asBool() const;
			std::string asString() const;

			ValueArray& asValueArray();
			const ValueArray& asValueArray() const;

			ValueDict& asValueDict();
			const ValueDict& asValueDict() const;

			inline bool isNull() const {return _type == NONE;}
			inline Type getType() const {return _type;};

			std::string getDescription();

		private:
			void clear();
			void reset(Type type);

			union {
				unsigned char byteVal;
				int intVal;
				float floatVal;
				double doubleVal;
				bool boolVal;

				std::string* strVal;
				ValueArray* vectorVal;
				ValueDict* mapVal;
			}_field;

			Type _type;
		};

		} /* namespace wanaka */
#endif /* VALUE_H_ */
