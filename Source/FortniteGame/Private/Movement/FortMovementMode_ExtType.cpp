// Copyright Epic Games, Inc. All Rights Reserved.

#include "Movement/FortMovementMode_ExtType.h"
#include "UObject/Class.h"

bool FMovementMode_ExtID::operator==(const FMovementMode_ExtID& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FMovementMode_ExtID& Value)
{
	return 0;
}
