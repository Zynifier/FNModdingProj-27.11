// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/ManagerParticipantSubsetID.h"
#include "UObject/Class.h"

bool FManagerParticipantSubsetID::operator==(const FManagerParticipantSubsetID& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FManagerParticipantSubsetID& Value)
{
	return 0;
}
