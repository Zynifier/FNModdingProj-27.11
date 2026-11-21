// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ManagerParticipantSubsetID.generated.h"

USTRUCT(BlueprintType)
struct FManagerParticipantSubsetID
{
	GENERATED_BODY()

private:
	UPROPERTY()
	uint32 InternalId;


	FORTNITEGAME_API bool operator==(const FManagerParticipantSubsetID& Other) const;
	friend FORTNITEGAME_API uint32 GetTypeHash(const FManagerParticipantSubsetID& Value);
};

