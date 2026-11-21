// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Movement/FortMovementMode_ExtType.h"
#include "FortMovementMode_ExtRegistry.generated.h"

class UFortMovementMode_BaseExtLogic;

UCLASS()
class FORTNITEGAME_API UFortMovementMode_ExtRegistry : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TSet<TSubclassOf<UFortMovementMode_BaseExtLogic>> RegisteredExtLogic;

	UPROPERTY(Transient)
	TMap<FMovementMode_ExtID, TObjectPtr<UFortMovementMode_BaseExtLogic>> RegisteredMovementModeExtentionLogic;

};

