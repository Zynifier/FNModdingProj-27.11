// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAnimInput_PatrolAnimSet.generated.h"

class UAnimMontage;
class UAnimSequence;
class UBlendSpace;

USTRUCT(BlueprintType)
struct FFortAnimInput_PatrolAnimSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	TObjectPtr<UAnimSequence> PatrolIdlePose;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	TObjectPtr<UAnimSequence> PatrolIdleAdditive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	TObjectPtr<UAnimMontage> AdditiveHitReactMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	TObjectPtr<UAnimMontage> FullBodyHitReactMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	TObjectPtr<UAnimMontage> PatrolToAlertMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	TObjectPtr<UAnimMontage> AlertToCombatMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	TObjectPtr<UBlendSpace> WalkBlendSpaceCore;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	TObjectPtr<UBlendSpace> WalkBlendSpaceAdditive;

};

