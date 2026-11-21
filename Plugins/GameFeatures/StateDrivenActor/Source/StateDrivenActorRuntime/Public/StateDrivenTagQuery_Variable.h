// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateDrivenTagQuery.h"
#include "StateDrivenTagQuery_Variable.generated.h"

USTRUCT(meta=(DisplayName="Variable"))
struct FStateDrivenTagQuery_Variable : public FStateDrivenTagQuery_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenTagQuery_Variable")
	int32 VariableIndex;

};

