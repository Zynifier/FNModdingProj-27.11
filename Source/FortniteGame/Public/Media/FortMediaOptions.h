// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EpicMediaOptions.h"
#include "FortMediaOptions.generated.h"

UCLASS(BlueprintType)
class UFortMediaOptions : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static FEpicMediaOptions GetMediaOptions();

};

