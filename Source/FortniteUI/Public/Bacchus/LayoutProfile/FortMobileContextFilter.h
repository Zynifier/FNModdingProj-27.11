// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortMobileContextFilter.generated.h"

USTRUCT()
struct FFortMobileContextFilter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMobileContextFilter", meta=(Categories="HUDLayout.Context"))
	FGameplayTagContainer ShownInContexts;

	UPROPERTY(EditAnywhere, Category="FortMobileContextFilter", meta=(Categories="HUDLayout.Context"))
	FGameplayTagContainer HiddenInContexts;

};

