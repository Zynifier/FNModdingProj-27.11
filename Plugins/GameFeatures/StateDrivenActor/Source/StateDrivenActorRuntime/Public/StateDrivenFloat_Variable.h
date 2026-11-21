// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateDrivenFloat.h"
#include "StateDrivenFloat_Variable.generated.h"

USTRUCT(meta=(DisplayName="Variable"))
struct FStateDrivenFloat_Variable : public FStateDrivenFloat_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenFloat_Variable")
	int32 VariableIndex;

};

