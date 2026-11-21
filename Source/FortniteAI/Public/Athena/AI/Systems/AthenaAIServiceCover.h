// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/Systems/AthenaAIService.h"
#include "AthenaAIServiceCover.generated.h"

class UAthenaAIServiceCover;
class UNavigationQueryFilter;
class UObject;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UAthenaAIServiceCover : public UAthenaAIService
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, meta=(WorldContext="WorldContextObject"))
	static UAthenaAIServiceCover* GetAthenaAIServiceCover(const UObject* WorldContextObject);

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaAIServiceCover", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UNavigationQueryFilter> CoverPositionFilterClass;

};

