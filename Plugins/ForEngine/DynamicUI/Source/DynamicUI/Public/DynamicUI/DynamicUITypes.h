// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DynamicUITypes.generated.h"

class AActor;

UENUM()
enum class EDynamicUIDebugDisplayMode : uint8
{
	Hide = 0,
	ShowSelected = 1,
	ShowAll = 2,
};

UENUM()
enum class EDynamicUIUnallowedBehavior : int32
{
	Hide = 0,
	Collapse = 1,
	Destroy = 2,
};

UENUM()
enum class EDynamicUIZOrder : int32
{
	Back = 1000,
	Middle = 2000,
	Front = 3000,
	Custom = 2500,
	// Values used only from code and only in special cases

	CustomMin = 0 UMETA(Hidden),
	// Min value of the custom z order

	CustomMax = 5000 UMETA(Hidden),
	// Max value of the custom z order

	Loading = 30000 UMETA(Hidden),
	// Used for widgets shown during loading screen

	Top = 50000 UMETA(Hidden),
};

USTRUCT()
struct FDynamicUIDirectorData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TSoftClassPtr<AActor> DirectorClass;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> Instance;

};

USTRUCT()
struct FDynamicUIPlayerData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TMap<FString, FDynamicUIDirectorData> ActiveDirectors;

};

USTRUCT()
struct FDynamicUISceneData
{
	GENERATED_BODY()

};

