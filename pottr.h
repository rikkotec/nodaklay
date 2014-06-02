/**
 * package: nodaklay
 * version:  0.0.1
 * author:  Richard B. Winters <a href="mailto:rik@mmogp.com">rik At MassivelyModified</a>
 * copyright: 2013-2014 Massively Modified, Inc.
 * license: Apache, Version 2.0 <http://www.apache.org/licenses/LICENSE-2.0>
 */


#ifndef POTTR_H
#define POTTR_H


// INCLUDES
#include <v8.h>
#include <node.h>


/**
 * NodaKlay Layout Facility
 *
 * Allows one to work with a simple yet powerful layout rendering system using JavaScript in Node.js.  Works using the NodaKlay C++
 * Parser for Speed and Efficiency.
 *
 * @since 0.0.1
 */
class Pottr : public node::ObjectWrap
{
	public:
		static void Init( v8::Handle<v8::Object> exports );

	private:
		explicit Pottr( v8::Local<v8::String> output = v8::String::New( "" ), v8::Persistent<v8::Integer> type = v8::Persistent<v8::Integer>::New( v8::Integer::New( 0 ) ), v8::Handle<v8::Boolean> prepared = v8::Handle<v8::Boolean>( v8::False() ) );
		~Pottr();

		static v8::Persistent<v8::Function> constructor;
		static v8::Handle<v8::Value> New( const v8::Arguments& args );
		static v8::Handle<v8::Value> Turn( const v8::Arguments& args );
		static v8::Handle<v8::Value> Shape( const v8::Arguments& args );
		static v8::Handle<v8::Value> Decorate( const v8::Arguments& args );

	public:
		v8::Handle<v8::String> _output;
		v8::Persistent<v8::Integer> _type;
		v8::Handle<v8::Boolean> _prepared;
};

#endif
