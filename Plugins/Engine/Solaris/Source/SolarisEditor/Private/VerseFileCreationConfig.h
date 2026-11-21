// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VerseFileCreationConfig.generated.h"

/** Parameters for creating a verse file */
USTRUCT()
struct FVerseFileCreationConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FString FileContent;

};

