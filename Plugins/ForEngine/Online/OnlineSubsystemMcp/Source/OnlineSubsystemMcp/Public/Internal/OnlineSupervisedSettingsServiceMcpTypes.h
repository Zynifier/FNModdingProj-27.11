// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSupervisedSettingsServiceMcpTypes.generated.h"

UENUM(BlueprintType)
enum class ESupervisedSettingsRestrictiveOrder : uint8
{
	FirstRestrictive = 0,
	FirstPermissive = 1,
	LowRestrictive = 2,
	LowPermissive = 3,
	FalseRestrictive = 4,
	FalsePermissive = 5,
	None = 6,
};

UENUM(BlueprintType)
enum class ESupervisedSettingsValueType : uint8
{
	Boolean = 0,
	/*Numeric not supported yet, to do when a numeric setting is needed*/
	Numeric = 1,
	Option = 2,
	None = 3,
};

