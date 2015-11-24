#!/bin/bash

for protofile in `ls -1 example_protos/`; do
  protobuf-3.0.0-beta-1-ue4-binaries/Release/protoc.exe -I=example_protos/ \
      --cpp_out=ProtoRPC_UE4/Source/ProtoRPC_UE4/GeneratedProtoStubs \
      --java_out=appengine-auth-svc/src example_protos/$protofile
done

