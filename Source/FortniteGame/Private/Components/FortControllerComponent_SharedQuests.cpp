// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_SharedQuests.h"

UFortControllerComponent_SharedQuests::UFortControllerComponent_SharedQuests(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UFortControllerComponent_SharedQuests::CanGrantSharedQuests() const
{
	return false;
}
