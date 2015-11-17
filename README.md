# Proto3RPC_UE4
Unreal Engine support for Google Protocol Buffers (v3) &amp; RPC mechanisms.

The goal of this project is to provide libraries and samples which can be used to
integrate into projects for the purpose of allowing UnrealEngine based clients and
servers to seamlessly communicate with the Google Cloud Platform.

CONTENTS;
  - protobuf-3.0.0-beta-1-ue4/
    - Googles proto3 source with mods for Windows/UE4.
  - protobuf-3.0.0-beta-1-ue4-binaries/
    - Binaries built from the above.
  - example_protos/ 
    - Example protos for a game 'session' service.
  - ProtoRPC_UE4/
    - UE4 project which contains the RPC code and an example of how to use
      protos via the sample protos.
  - appengine/
    - AppEngine service (JAVA) which contains a vendorized proto3 .JAr and
      an example server for the sample app.

TODO:
  - Add proto3 binaries for XBox/PS4.
  - Flush out the appengine service.
  - Port to gRPC.

Notes:

1. When you configure the protobuf libraries for building you need to ensure
   you have PROTOBUF_USE_DLLS defined as well as enable shared library
   building via cmake.
