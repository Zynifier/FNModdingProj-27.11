// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OperationSequence.h"
#include "OperationSequenceTest.generated.h"

class UOperationSequenceTest_HandleInner;

USTRUCT()
struct FOperationSequenceData_TestInner
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UOperationSequenceTest_HandleInner> Inner;

};

UCLASS(NotBlueprintable, meta=(NotBlueprintType="true"))
class UOperationSequenceTest_HandleInner : public UObject
{
	GENERATED_BODY()

};

UCLASS(NotBlueprintable, meta=(NotBlueprintType="true"))
class UOperationSequenceTest_HandleOuter : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOperationSequenceHandle SequenceHandle;

};

