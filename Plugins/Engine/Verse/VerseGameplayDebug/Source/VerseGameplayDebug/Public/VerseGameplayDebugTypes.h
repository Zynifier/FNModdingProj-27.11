// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VerseGameplayDebugTypes.generated.h"

// Temporary struct used to carry cheat messages between valkyrie editor and server side script

USTRUCT()
struct FVerseGameplayStringDebugMessage
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName Name;

	UPROPERTY()
	FString String;

};

