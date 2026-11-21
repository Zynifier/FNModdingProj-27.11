// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAnimInput_RandomizeMontageSection.generated.h"

class UAnimSequenceBase;

USTRUCT(BlueprintType)
struct FFortAnimInput_RandomizeMontageSection
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UAnimSequenceBase> CurrentAnimation;

	UPROPERTY(Transient)
	FName MontageSectionName;

	UPROPERTY(Transient)
	float TimeUntilNextSectionChange;

	UPROPERTY(Transient)
	int32 CurrentSectionParamIndex;

};

