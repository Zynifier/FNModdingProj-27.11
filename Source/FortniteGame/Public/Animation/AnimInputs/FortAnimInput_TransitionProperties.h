// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAnimInput_TransitionProperties.generated.h"

USTRUCT(BlueprintType)
struct FFortAnimInput_TransitionProperties
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Transitions")
	uint8 bTransition_DoubleJump_Fast : 1;

	UPROPERTY(BlueprintReadOnly, Category="Transitions")
	uint8 bTransition_DoubleJump : 1;

};

