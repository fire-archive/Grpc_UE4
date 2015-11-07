// Fill out your copyright notice in the Description page of Project Settings.
#include "ProtoRPC_UE4PrivatePCH.h"

#include "AllowWindowsPlatformTypes.h"
#include "HttpRpcChannel.h"

using google::protobuf::Closure;
using google::protobuf::Message;
using google::protobuf::MethodDescriptor;
using google::protobuf::RpcController;

HttpRpcChannel::HttpRpcChannel(const FString& ServiceUri)
    : serviceUri_(ServiceUri) {}

HttpRpcChannel::~HttpRpcChannel() {}

void HttpRpcChannel::CallMethod(const MethodDescriptor* method, RpcController* controller, const Message* request, Message* response, Closure* done) {}

