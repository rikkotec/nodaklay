/**
 * package: nodaklay
 * version:  0.0.1
 * author:  Richard B. Winters <a href="mailto:rik@mmogp.com">rik At MassivelyModified</a>
 * copyright: 2013-2014 Massively Modified, Inc.
 * license: Apache, Version 2.0 <http://www.apache.org/licenses/LICENSE-2.0>
 */


// INCLUDES
#include <v8.h>
#include <node.h>
#include <iostream>
#include <string>
#include "resource.h"
#include "pottr.h"

using namespace v8;


// PROTOTYPES
Persistent<Function> Pottr::constructor;	// Default constructor prototype


/**
 * Overloaded Constructor
 *
 * @return void
 *
 * @since 0.0.1
 */
Pottr::Pottr( Local<String> output, Persistent<Integer> type, Handle<Boolean> prepared ) : _output( output->ToString() ), _type( type ), _prepared( prepared )
{
}


/**
 * Destructor
 *
 * @return void
 *
 * @since 0.0.1
 */
Pottr::~Pottr()
{
}


/**
 * Initializes the Pottr object and exports it to v8 to be wrapped for Node.js
 *
 * @param Handle<Object>	exports		Defines a reference to an exports object (Syntactically taken)
 *
 * @return void
 *
 * @since 0.0.1
 */
void Pottr::Init( Handle<Object> exports )
{
	// Prepare constructor template
	Local<FunctionTemplate> tpl = FunctionTemplate::New( New );
	tpl->SetClassName( String::NewSymbol( "Pottr" ) );
	tpl->InstanceTemplate()->SetInternalFieldCount( 3 );

	// Prepare the accessors for our dynamic variables which are not static
	//tpl->InstanceTemplate().SetAccessor( String::New( "host" ), GetHost, SetHost );

	// Prototype(s) of our methods for v8
	tpl->PrototypeTemplate()->Set( String::NewSymbol( "Turn" ), FunctionTemplate::New( Turn )->GetFunction() );
	tpl->PrototypeTemplate()->Set( String::NewSymbol( "Shape" ), FunctionTemplate::New( Shape )->GetFunction() );
	tpl->PrototypeTemplate()->Set( String::NewSymbol( "Decorate" ), FunctionTemplate::New( Decorate )->GetFunction() );

	constructor = Persistent<Function>::New( tpl->GetFunction() );
	exports->Set( String::NewSymbol( "Pottr" ), constructor );
}


/**
 * Returns a new instance of the Pottr object
 *
 * @param const Arguments&		Arguments passed during invocation
 *
 * @return		Driver		New instance of a Driver object
 *
 * @since 0.0.1
 */
Handle<Value> Pottr::New( const Arguments& args )
{
	HandleScope scope;

	if( args.IsConstructCall() )
	{
		// Invoked as constructor: 'new nodaklay()'
		Pottr* pttr = new Pottr( String::New( "" ), Persistent<Integer>::New( Integer::New( 0 ) ), Handle<Boolean>( v8::False() ) );
		pttr->Wrap( args.This() );

		return args.This();
	}
	else
	{
		// Invoked as plain function 'nodaklay()', turn it into a construct call
		const int argc = 3;

		Local<Value> argv[argc] = { String::New( "" ), Integer::New( 0 ), Local<Boolean>::New( v8::False() ) };

		return scope.Close( constructor->NewInstance( argc, argv ) );
	}
}


/**
 * Parses a Layout and/or View file containing Kwaeri Markup Language (.KML)
 *
 * @param const Arguments&		Arguments passed during invocation
 *
 * @return String		The current query string
 *
 * @since 0.0.1
 */
Handle<Value> Pottr::Turn( const Arguments& args )
{
	// Always declare the HandleScope
	HandleScope scope;

	// Unwrap the object
	Pottr* pttr = ObjectWrap::Unwrap<Pottr>( args.This() );

	// Fetch our arguments and define default behavior for incorrect arguments or no arguments
	if( args[0]->IsUndefined() )
	{
		return scope.Close( String::New( "You must specify a layout or view file for the parser to process." ) );
	}

	return scope.Close( String::New( "We have successfully Turned, Shaped, and Decorated the view" ) );
}


/**
 * Parses a Layout and/or View file containing Kwaeri Markup Language (.KML)
 *
 * @param const Arguments&		Arguments passed during invocation
 *
 * @return String		The current query string
 *
 * @since 0.0.1
 */
Handle<Value> Pottr::Shape( const Arguments& args )
{
	// Always declare the HandleScope
	HandleScope scope;

	// Unwrap the object
	Pottr* pttr = ObjectWrap::Unwrap<Pottr>( args.This() );

	// Fetch our arguments and define default behavior for incorrect arguments or no arguments
	if( args[0]->IsUndefined() )
	{
		return scope.Close( String::New( "You must specify a layout or view file for the parser to process." ) );
	}

	return scope.Close( String::New( "We have successfully Turned, Shaped, and Decorated the view" ) );
}


/**
 * Parses a Layout and/or View file containing Kwaeri Markup Language (.KML)
 *
 * @param const Arguments&		Arguments passed during invocation
 *
 * @return String		The current query string
 *
 * @since 0.0.1
 */
Handle<Value> Pottr::Decorate( const Arguments& args )
{
	// Always declare the HandleScope
	HandleScope scope;

	// Unwrap the object
	Pottr* pttr = ObjectWrap::Unwrap<Pottr>( args.This() );

	// Fetch our arguments and define default behavior for incorrect arguments or no arguments
	if( args[0]->IsUndefined() )
	{
		return scope.Close( String::New( "You must specify a layout or view file for the parser to process." ) );
	}

	return scope.Close( String::New( "We have successfully Turned, Shaped, and Decorated the view" ) );
}

