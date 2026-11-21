// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "FortAthenaMakeMathVariableStateTreeTask.generated.h"

USTRUCT()
struct FFortAthenaIntStateTreeParameter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	int32 Int;

};

USTRUCT(meta=(DisplayName="(Fortnite) Arithmetic: Make Int"))
struct FFortAthenaMakeIntVariableStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bResetOnReselect;

};

USTRUCT()
struct FFortAthenaMakeIntVariableStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	int32 DefaultIntValue;

	UPROPERTY(EditAnywhere, Category="Output")
	FFortAthenaIntStateTreeParameter OutInt;

};

