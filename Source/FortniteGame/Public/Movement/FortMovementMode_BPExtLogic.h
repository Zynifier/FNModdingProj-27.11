// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Movement/FortMovementMode_BaseExtLogic.h"
#include "FortMovementMode_BPExtLogic.generated.h"

enum class EFortMovementModeExt_UpdateResult : uint8;

UCLASS(BlueprintType, Blueprintable)
class FORTNITEGAME_API UFortMovementMode_BPExtLogic : public UFortMovementMode_BaseExtLogic
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="PhysUpdate"))
	void BP_PhysUpdate(const float DeltaTime, const FVector& InVelocity, const FVector& InAcceleration, FVector& ResultVelocity, FVector& ResultAcceleration);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="UpdateBeforeCharacterMovement"))
	EFortMovementModeExt_UpdateResult BP_UpdateBeforeCharacterMovement(float DeltaTime);

};

