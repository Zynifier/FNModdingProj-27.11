// Copyright Epic Games, Inc. All Rights Reserved.

#include "ModuleBoundary/PrimitiveModularCrosstalkInterface.h"

void IPrimitiveModularCrosstalkInterface::BindNoParamEventToTaggedDelegate(const FName& DelegateTag, UObject* Object, const FName& CallbackEventName)
{
}

int32 IPrimitiveModularCrosstalkInterface::GetTaggedIntPayload(const FName& Tag)
{
	return int32();
}

UObject* IPrimitiveModularCrosstalkInterface::GetTaggedObjectPayload(const FName& Tag)
{
	return nullptr;
}

FString IPrimitiveModularCrosstalkInterface::GetTaggedStringPayload(const FName& Tag)
{
	return FString();
}

void IPrimitiveModularCrosstalkInterface::SendTagAsPayload(const FName& Tag)
{
}

void IPrimitiveModularCrosstalkInterface::SendTaggedIntPayload(const FName& Tag, int32 Payload)
{
}

void IPrimitiveModularCrosstalkInterface::SendTaggedObjectPayload(const FName& Tag, UObject* Payload)
{
}

void IPrimitiveModularCrosstalkInterface::SendTaggedStringPayload(const FName& Tag, const FString& Payload)
{
}

void IPrimitiveModularCrosstalkInterface::UnbindNoParamEventFromTaggedDelegate(const FName& DelegateTag, UObject* Object)
{
}

void IPrimitiveModularCrosstalkInterface::UnbindObjectCallbacksFromAllTaggedDelegates(UObject* Object)
{
}
