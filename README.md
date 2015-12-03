# Proto3RPC_UE4
Unreal Engine support for Google Protocol Buffers (v3) &amp; RPC mechanisms.

The goal of this project is to provide framework code and samples which can be used
to integrate into projects for the purpose of allowing UnrealEngine based clients and
servers to seamlessly communicate with the Google Cloud Platform via Protocol Buffers.

For UE4 this has been accomplished by porting libproto into UE4's build system. This
was deemed a necessary burden to take on due to UE4's apparent inability to import
a static library which is linked with during compilation. UE4's plug-in architecture
only supports /MT DLL targets for Windows, which mean they run on their own heaps.
The upshot of this approach is that there are no windows specific wrappers required,
and that the code should build on XBox/PS targets without too much fiddling.

For more information on how to use protocol buffers, see either the sample projects
or for more depth visit http://developers.google.com/protocol-buffers.

CONTENTS;
  - protobuf-3.0.0-beta-1-ue4/
    - Googles proto3 source with compiler mods for UE4.
  - protobuf-3.0.0-beta-1-ue4-binaries/
    - Binaries built from the above.
  - protobuf-java-3.0.0-beta-1/
    - Googles proto3 java source; needed to build proto3 .JARs for app engine.
  - example_protos/ 
    - Example protos for a game 'session' service.
  - ProtoRPC_UE4/
    - UE4 project which contains a port of libprotobuf, an RPC implementation based
      on the FHTTPModule, and an example of how to use protos via the sample protos.
  - aappengine-auth-svc/
    - AppEngine service (JAVA) which contains a vendorized proto3 .JAR and
      an example server for the sample app.

CAVEATS / KNOWN ISSUES:
  - Streaming RPC's are not currently supported. This will take some time.
  - The binary transport is not yet tested.

TODO:
  - Extract AppEngine RpcController and dispatch logic into a generic helper.
  - Clean up comments and documentation.
  - Investigate moving back to a UE4 plugin since we're building all the code.
  - Add binary HTTP transport
  - Add GZIP support.
  - Port to gRPC.

Notes:

