// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMovementMode_ExtType.generated.h"

UENUM(BlueprintType)
enum class EFortMovementModeExt_UpdateResult : uint8
{
	Updating = 0,
	Active = 1,
	Active_Layered = 2,
	Ended = 3,
};

USTRUCT()
struct FMovementMode_ExtID
{
	GENERATED_BODY()

private:
	UPROPERTY()
	uint32 MovementMode_ExtCRC_ID;


	FORTNITEGAME_API bool operator==(const FMovementMode_ExtID& Other) const;
	friend FORTNITEGAME_API uint32 GetTypeHash(const FMovementMode_ExtID& Value);
};

