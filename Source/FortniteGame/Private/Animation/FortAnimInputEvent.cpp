// Copyright Epic Games, Inc. All Rights Reserved.

#include "Animation/FortAnimInputEvent.h"

UFortAnimInputEvent* UFortAnimInputEvent::CreateAnimInputEvent(FName InEventName)
{
	return nullptr;
}

bool UFortAnimInputEvent::IsNamed(FName InEventName) const
{
	return false;
}

UFortAnimInputEvent_AnimClass* UFortAnimInputEvent_AnimClass::CreateAnimInputEvent_AnimClass(FName InEventName, TSubclassOf<UAnimInstance> InValue)
{
	return nullptr;
}

UFortAnimInputEvent_Bool* UFortAnimInputEvent_Bool::CreateAnimInputEvent_Bool(FName InEventName, bool bInValue)
{
	return nullptr;
}

UFortAnimInputEvent_Float* UFortAnimInputEvent_Float::CreateAnimInputEvent_Float(FName InEventName, float InValue)
{
	return nullptr;
}

UFortAnimInputEvent_Vector* UFortAnimInputEvent_Vector::CreateAnimInputEvent_Vector(FName InEventName, FVector InValue)
{
	return nullptr;
}
