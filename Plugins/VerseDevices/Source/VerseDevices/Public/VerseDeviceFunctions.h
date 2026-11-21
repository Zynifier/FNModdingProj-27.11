// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VerseDeviceFunctions.generated.h"

class AController;

USTRUCT()
struct FVerseDeviceFunctionPayload
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AController> Instigator;

};

