// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Movement/FortMovementComp_Character.h"
#include "FortMovementComp_AIChar.generated.h"

UCLASS(MinimalAPI)
class UFortMovementComp_AIChar : public UFortMovementComp_Character
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="AI")
	uint8 bDeimos : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="AI")
	uint8 bConsiderPawnAsWalkable : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="Avoidance")
	FVector CustomRVOAvoidanceOriginOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AdvancedDisplay, Category="Avoidance")
	float CustomRVOAvoidanceRadius;

	UPROPERTY(EditAnywhere, Category="AI")
	uint8 bForceUseOfOwnerRenderingTime : 1;

};

