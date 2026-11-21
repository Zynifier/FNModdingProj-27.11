// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortMediaUCPInView.generated.h"

UCLASS(BlueprintType)
class UFortMediaUCPInView : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void FireUCPInViewCallback(bool bInView);

};

