// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Extensibility/FortCosmeticFlowOption.h"
#include "FortCosmeticOption_Test.generated.h"

UENUM()
enum class ECosmeticTestOperationType : uint8
{
	Multiply = 0,
	Add = 1,
	None = 2,
};

USTRUCT()
struct FCosmeticTestCalculationData
{
	GENERATED_BODY()

};

USTRUCT()
struct FCosmeticTestCalculationHandler
{
	GENERATED_BODY()

};

UCLASS(meta=(InnateVariance))
class UFortCosmeticFlowOption_TestAdd : public UFortCosmeticFlowOption
{
	GENERATED_BODY()

};

UCLASS(meta=(InnateVariance))
class UFortCosmeticFlowOption_TestAddOne : public UFortCosmeticFlowOption_TestAdd
{
	GENERATED_BODY()

};

UCLASS(meta=(InnateVariance))
class UFortCosmeticFlowOption_TestAddTwo : public UFortCosmeticFlowOption_TestAdd
{
	GENERATED_BODY()

};

UCLASS(meta=(InnateVariance))
class UFortCosmeticFlowOption_TestAddZero : public UFortCosmeticFlowOption_TestAdd
{
	GENERATED_BODY()

};

UCLASS(meta=(InnateVariance))
class UFortCosmeticFlowOption_TestMultiply : public UFortCosmeticFlowOption
{
	GENERATED_BODY()

};

UCLASS(meta=(InnateVariance))
class UFortCosmeticFlowOption_TestMultiplyByOne : public UFortCosmeticFlowOption_TestMultiply
{
	GENERATED_BODY()

};

UCLASS(meta=(InnateVariance))
class UFortCosmeticFlowOption_TestMultiplyByTwo : public UFortCosmeticFlowOption_TestMultiply
{
	GENERATED_BODY()

};

UCLASS(meta=(InnateVariance))
class UFortCosmeticFlowOption_TestMultiplyByZero : public UFortCosmeticFlowOption_TestMultiply
{
	GENERATED_BODY()

};

