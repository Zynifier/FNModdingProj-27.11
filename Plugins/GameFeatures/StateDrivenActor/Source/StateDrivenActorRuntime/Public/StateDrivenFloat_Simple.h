// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateDrivenFloat.h"
#include "StateDrivenFloat_Simple.generated.h"

USTRUCT(meta=(DisplayName="Simple"))
struct FStateDrivenFloat_Simple : public FStateDrivenFloat_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenFloat_Simple")
	float Value;

};

