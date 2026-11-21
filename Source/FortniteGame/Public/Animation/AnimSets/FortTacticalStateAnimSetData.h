// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortTacticalStateAnimSetData.generated.h"

class UAnimSequenceBase;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortTacticalStateAnimSetData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TacticalSprint")
	UAnimSequenceBase* SprintStart;

	UPROPERTY(EditAnywhere, Category="TacticalSprint")
	UAnimSequenceBase* SprintLoop;

	UPROPERTY(EditAnywhere, Category="TacticalSprint")
	UAnimSequenceBase* FallToSprint;

	UPROPERTY(EditAnywhere, Category="TacticalSprint")
	UAnimSequenceBase* DoorBashToSprint;

	UPROPERTY(EditAnywhere, Category="TacticalJump")
	UAnimSequenceBase* JumpStart;

	UPROPERTY(EditAnywhere, Category="TacticalJump")
	UAnimSequenceBase* FallLoop;

};

