// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortCreativeIndexedObjectRegisterComponent.h"

bool UFortCreativeIndexedObjectRegisterComponent::AddObjectToIndex(TArray<FFortObjectArray>& RegisterArray, UObject* Item, int32 Index)
{
	return false;
}

const TArray<FFortObjectArray>& UFortCreativeIndexedObjectRegisterComponent::GetAllRegisteredObjects() const
{
	static TArray<FFortObjectArray> Dummy;
	return Dummy;
}

int32 UFortCreativeIndexedObjectRegisterComponent::GetIndexForObject(UObject* Object) const
{
	return int32();
}

void UFortCreativeIndexedObjectRegisterComponent::GetRegisterAtIndex(int32 Index, bool& bIsValid, FFortObjectArray& Register)
{
}

UObject* UFortCreativeIndexedObjectRegisterComponent::GetRegisteredObject(EFortArrayElementPosition Element, int32 Index)
{
	return nullptr;
}

void UFortCreativeIndexedObjectRegisterComponent::PrintRegister(const UObject* WorldContextObject, const FString& PrefixText) const
{
}

void UFortCreativeIndexedObjectRegisterComponent::RemoveEmptyIndicesFromEnd()
{
}

void UFortCreativeIndexedObjectRegisterComponent::RemoveObjectFromIndex(TArray<FFortObjectArray>& RegisterArray, UObject* Item, bool& WasRemoved, int32& RemovedIndex, int32 Index)
{
}

void UFortCreativeIndexedObjectRegisterComponent::SetDebugLogging(EIndexObjectRegisterLogType NewLogType, EFortNetworkScope NewLogScope)
{
}
