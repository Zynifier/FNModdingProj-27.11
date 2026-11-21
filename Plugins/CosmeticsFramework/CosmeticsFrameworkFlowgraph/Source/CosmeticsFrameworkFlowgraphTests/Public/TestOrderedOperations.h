// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OrderedOperation.h"
#include "TestOrderedOperations.generated.h"

USTRUCT()
struct FOperationSequenceData_TestInitialData
{
	GENERATED_BODY()

};

USTRUCT()
struct FOperationSequenceData_TestOperationData
{
	GENERATED_BODY()

};

UCLASS()
class UOrderedOperation_TestOperation_AddValue : public UOrderedOperation
{
	GENERATED_BODY()

};

UCLASS()
class UOrderedOperation_TestOperation_InitialValue : public UOrderedOperation
{
	GENERATED_BODY()

};

UCLASS()
class UOrderedOperation_TestOperation_MultiplyValue : public UOrderedOperation
{
	GENERATED_BODY()

};

UCLASS()
class UOrderedOperation_TestOperation_NegateValue : public UOrderedOperation
{
	GENERATED_BODY()

};

