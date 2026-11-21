// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAnimInput_AimScrambleDataHelper.generated.h"

USTRUCT(BlueprintType)
struct FFortAnimInput_AimScrambleDataHelper
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="FortAnimInput_AimScrambleDataHelper")
	float AimPitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="FortAnimInput_AimScrambleDataHelper")
	float AimYaw;

	UPROPERTY(Transient)
	uint8 bIsAimDataScambled : 1;

};

