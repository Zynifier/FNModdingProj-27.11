// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortOnTimeHitInfo.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FOnTimeHitCallback);

USTRUCT()
struct FOnTimeHitInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnTimeHitCallback TimeCallback;

};

