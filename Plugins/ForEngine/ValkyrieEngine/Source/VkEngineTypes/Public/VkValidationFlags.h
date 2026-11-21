// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VkValidationFlags.generated.h"

UENUM()
enum class EVkValidationFlags : uint8
{
	None = 0,
	VF_IgnoreValidation = 1,
	//

	VF_AllowMissingGameFeatureDataAsset = 2,
	//
//

	VF_AllowEngineContent = 4,
	//
//
// 

	VF_AllowGameContent = 8,
	//
//
// 
//

	VF_NoPreCheckVerse = 16,
};

USTRUCT()
struct VKENGINETYPES_API FVkMetaDataFlags
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<FString, FString> _validation_flags;

};

