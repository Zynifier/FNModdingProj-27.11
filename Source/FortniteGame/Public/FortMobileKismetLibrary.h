// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortMobileKismetLibrary.generated.h"

UCLASS(MinimalAPI)
class UFortMobileKismetLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static bool Get3DTouchEnabled();

	UFUNCTION(BlueprintPure)
	static bool GetAutoFireEnabled();

	UFUNCTION(BlueprintPure)
	static bool GetDedicatedButtonEnabled();

	UFUNCTION(BlueprintPure)
	static bool GetTapToFireEnabled();

};

