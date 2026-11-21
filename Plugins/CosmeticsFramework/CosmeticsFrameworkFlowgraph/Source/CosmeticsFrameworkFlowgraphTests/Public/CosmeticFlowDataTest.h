// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CosmeticFlowDataTest.generated.h"

USTRUCT()
struct FCosmeticFlowData_TestStructBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FCosmeticFlowData_TestStructDerived : public FCosmeticFlowData_TestStructBase
{
	GENERATED_BODY()

};

