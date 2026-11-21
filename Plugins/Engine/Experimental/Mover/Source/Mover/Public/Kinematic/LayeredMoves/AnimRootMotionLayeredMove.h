// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LayeredMove.h"
#include "AnimRootMotionLayeredMove.generated.h"

class UAnimMontage;

/** Anim Root Motion Move: handles root motion from a montage played on the associated mesh */
USTRUCT(BlueprintType)
struct MOVER_API FLayeredMove_AnimRootMotion : public FLayeredMoveBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	TObjectPtr<UAnimMontage> Montage;

	// Montage position when started (in unscaled seconds). 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	float StartingMontagePosition;

	// Rate at which this montage is intended to play

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	float PlayRate;

};

