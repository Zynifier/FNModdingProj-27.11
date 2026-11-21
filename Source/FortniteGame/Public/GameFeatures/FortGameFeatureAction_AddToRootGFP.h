// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_AddToRootGFP.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Add To RootGFP"))
class UFortGameFeatureAction_AddToRootGFP : public UGameFeatureAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="RootGFPs to Add To", meta=(GetOptions="GetRootGFPOptions"))
	TSet<FString> RootGFPsToAddTo;

private:
	UFUNCTION()
	TArray<FString> GetRootGFPOptions() const;

};

