// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TriState.h"
#include "FortLocomotionAnimSetData.generated.h"

class UAnimSequenceBase;
class UBlendSpace;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortLocomotionAnimSetData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Config")
	ETriState EnableAdditiveLeans;

	UPROPERTY(EditAnywhere, Category="Config")
	ETriState UseMovementAdditiveForOneHandedTransitions;

	UPROPERTY(EditAnywhere, Category="Config")
	ETriState PlayMovementTransitions;

	UPROPERTY(EditAnywhere, Category="Base")
	UBlendSpace* MovementBlendSpaceTargeting;

	UPROPERTY(EditAnywhere, Category="Base")
	UBlendSpace* MovementBlendSpaceTargetingRightFootForward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	UBlendSpace* MovementBlendSpace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	UBlendSpace* MovementBlendSpaceNo45s;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	UAnimSequenceBase* Start_N;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	UAnimSequenceBase* Start_S;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	UAnimSequenceBase* Start_E;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	UAnimSequenceBase* Start_W;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	UAnimSequenceBase* Stop_N;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	UAnimSequenceBase* Stop_S;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	UAnimSequenceBase* Stop_E;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	UAnimSequenceBase* Stop_W;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	UAnimSequenceBase* Pivot_N;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	UAnimSequenceBase* Pivot_S;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	UAnimSequenceBase* Pivot_E;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	UAnimSequenceBase* Pivot_W;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Leans")
	UBlendSpace* CrouchAdditiveLean;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Leans")
	UBlendSpace* AdditiveLean;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additive")
	UAnimSequenceBase* AdditiveStart_N;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additive")
	UAnimSequenceBase* AdditiveStart_S;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additive")
	UAnimSequenceBase* AdditiveStart_E;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additive")
	UAnimSequenceBase* AdditiveStart_W;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additive")
	UAnimSequenceBase* AdditiveStop_N;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additive")
	UAnimSequenceBase* AdditiveStop_S;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additive")
	UAnimSequenceBase* AdditiveStop_E;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additive")
	UAnimSequenceBase* AdditiveStop_W;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additive")
	UAnimSequenceBase* AdditivePivot_N;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additive")
	UAnimSequenceBase* AdditivePivot_S;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additive")
	UAnimSequenceBase* AdditivePivot_E;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Additive")
	UAnimSequenceBase* AdditivePivot_W;

};

