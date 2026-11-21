// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetUserData.h"
#include "Animation/FortHarvesterSwing.h"
#include "FortHarvesterToolAssetUserData.generated.h"

class UAnimSequence;

UCLASS(Config=Game, MinimalAPI, BlueprintType)
class UFortHarvesterToolAssetUserData : public UAssetUserData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Harvester Tool Animation")
	TArray<FFortHarvesterSwing> Swings;

	UPROPERTY(EditAnywhere, Category="Harvester Tool Animation")
	TObjectPtr<UAnimSequence> Bounce;

};

