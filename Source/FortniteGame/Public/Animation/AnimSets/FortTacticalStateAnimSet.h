// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTacticalStateAnimSet.generated.h"

class UAnimSequenceBase;

USTRUCT(BlueprintType)
struct FFortTacticalStateAnimSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortTacticalStateAnimSet")
	UAnimSequenceBase* SprintStart;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortTacticalStateAnimSet")
	UAnimSequenceBase* SprintLoop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortTacticalStateAnimSet")
	UAnimSequenceBase* FallToSprint;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortTacticalStateAnimSet")
	UAnimSequenceBase* DoorBashToSprint;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortTacticalStateAnimSet")
	UAnimSequenceBase* JumpStart;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortTacticalStateAnimSet")
	UAnimSequenceBase* FallLoop;

};

