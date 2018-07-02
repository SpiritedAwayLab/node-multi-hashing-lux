#include <node.h>
#include <node_buffer.h>
#include <v8.h>
#include <stdint.h>
#include <nan.h>
#include <stdio.h>

extern "C" {
   
    #include "phi2.h"
}

#define THROW_ERROR_EXCEPTION(x) NanThrowError(x)
#define THROW_ERROR_EXCEPTION_WITH_STATUS_CODE(x, y) NanThrowError(x, y)

using namespace node;
using namespace v8;


NAN_METHOD(phi2) {
    NanScope();

    if (args.Length() < 1)
        return THROW_ERROR_EXCEPTION("You must provide one argument.");

    Local<Object> target = args[0]->ToObject();

    if(!Buffer::HasInstance(target))
        return THROW_ERROR_EXCEPTION("Argument should be a buffer object.");

    char * input = Buffer::Data(target);
    char *output = (char*) malloc(sizeof(char) * 32);

    uint32_t input_len = Buffer::Length(target);
    
    phi2_hash(input, output);


    NanReturnValue(
        NanNewBufferHandle(output, 32)
    );
}



void init(Handle<Object> exports) {
  
    exports->Set(NanNew<String>("phi2"), NanNew<FunctionTemplate>(phi2)->GetFunction()); 
}

NODE_MODULE(multihashing, init)
