// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Heroes/FortHeroSpecialization.h"

const TArray<TSoftObjectPtr<UCustomCharacterPart>>& UFortHeroSpecialization::GetCharacterPartPtrs() const
{
	static TArray<TSoftObjectPtr<UCustomCharacterPart>> Dummy;
	return Dummy;
}
