// g++ 14_excep_spec.cpp -o 14_excep_spec -std=c++11 && ./14_excep_spec

// pro

// provide excellent documentation on the kinds of exceptions a function
// is expected to throw

// for situations in which violating an exception
// specification is so dire as to justify immediate program termination,
// they offer that behavior by default.
// detect inconsistent use during compilation

// con

// unexpected calling terminate, abort, leads to resource leaks

// easy to break
// partly checked by compilers and they are easy to violate inadvertently.
// language not reject functions that might violate spec
// meaning calling funcs that might throw something else

// Furthermore, they can prevent high-level exception handlers from
// dealing with unexpected exceptions,

extern void f1()
{
    throw "error";
}; // might throw anything
void f2() throw(int);

void f2() throw(int)
{
    f1(); // legal even though f1 might throw
    // something besides an int
}

// therfore, avoid putting exception spec on templates that take type args

// a poorly designed template wrt exception specifications

// template <class T>
// bool operator==(const T &lhs, const T &rhs) throw()
// {
//     return &lhs == &rhs;
// }

// declare to throw no exceptions. But
// that’s not necessarily true, because it’s possible that operator& (the
// address-of operator) has been overloaded for some types

// here is no way to know anything about the exceptions thrown by a
// template’s type parameters.
// template and exception specifications don’t mix well

// omit
// exception specifications on functions making calls to functions that
// themselves lack exception specifications

// Function pointer type for a window system callback
// when a window system event occurs
// typedef void (*CallBackPtr)(int eventXLocation,
//                             int eventYLocation,
//                             void *dataToPassBack);

// typedef void (*CallBackPtr)(int eventXLocation,
//                             int eventYLocation,
//                             void *dataToPassBack) throw();

// Given this typedef, it is now an error to register a callback function
// that fails to guarantee it throws nothing

// Window system class for holding onto callback
// functions registered by window system clients
// class CallBack
// {
// public:
//     CallBack(CallBackPtr fPtr, void *dataToPassBack)
//         : func(fPtr), data(dataToPassBack) {}
//     void makeCallBack(int eventXLocation,
//                       int eventYLocation) const throw();

// private:
//     CallBackPtr func; // function to call when
//     // callback is made
//     void *data; // data to pass to callback
// };              // function
// To implement the callback, we call the registered func-
// tion with event’s coordinates and the registered data
// void CallBack::makeCallBack(int eventXLocation,
//                             int eventYLocation) const throw()
// {
//     func(eventXLocation, eventYLocation, data);
// }

// a callback function without an exception specification
// void callBackFcn1(int eventXLocation, int eventYLocation,
//                   void *dataToPassBack);
// void *callBackData;
// ... CallBack c1(callBackFcn1, callBackData);
// error! callBackFcn1
// might throw an exception
// a callback function with an exception specification
// void callBackFcn2(int eventXLocation,
//                   int eventYLocation,
//                   void *dataToPassBack) throw();
// CallBack c2(callBackFcn2, callBackData);
// okay, callBackFcn2 has a
// conforming ex. spec.

// a third technique you can use to avoid calls to unexpected is to handle
// exceptions “the system” may throw

//  prevention is hard and cure is easy

// class UnexpectedException
// {
// }; // all unexpected exception
// objects will be replaced
// by objects of this type
// void convertUnexpected()         // function to call if
// {                                // an unexpected exception
//     throw UnexpectedException(); // is thrown
// }
// and make it happen by replacing the default unexpected function
// with convertUnexpected:
// set_unexpected(convertUnexpected);

//  Provided the exception specification that was violated includes UnexpectedException, exception propagation will then continue as if the exception
// specification had always been satisfied. (If the exception specification
// does not include UnexpectedException, terminate will be called,
// just as if you had never replaced unexpected.)

// standard type bad_exception
// void convertUnexpected() // function to call if
// {                        // an unexpected exception
//     throw;               // is thrown; just rethrow
// } // the current exception
// set_unexpected(convertUnexpected);
// install convertUnexpected
// as the unexpected
// replacement

// unexpected being invoked even when a
// higher-level caller is prepared to cope with the exception that’s arisen.

// class Session
// {       // for modeling online
// public: // sessions
//     ~Session();
//     ... private : static void logDestruction(Session *objAddr) throw();
// };

// Session::~Session()
// {
//     try
//     {
//         logDestruction(this);
//     }
//     catch (...)
//     {
//     }
// }

int main()
{
    f2();
}
