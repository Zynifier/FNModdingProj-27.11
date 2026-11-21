// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ValkyrieScratchManifestDescriptor.generated.h"

USTRUCT()
struct FValkyrieScratchManifestDescriptor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> Files;

};

