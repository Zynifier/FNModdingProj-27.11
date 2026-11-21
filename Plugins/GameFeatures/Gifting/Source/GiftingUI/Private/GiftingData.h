// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortGameFeatureData.h"
#include "GiftingData.generated.h"

class UAthenaGiftingScreen;

UCLASS()
class UFortGiftingData : public UFortGameFeatureData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortGiftingData")
	TSoftClassPtr<UAthenaGiftingScreen> GiftingScreenClass;

};

