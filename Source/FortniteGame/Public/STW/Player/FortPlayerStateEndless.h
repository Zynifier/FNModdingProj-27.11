// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "STW/Player/FortPlayerStatePvE.h"
#include "FortPlayerStateEndless.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortPlayerStateEndless : public AFortPlayerStatePvE
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="FortPlayerStateEndless")
	void AddBluGloActivityScoreForPlayer(const FVector& BurnerLocation);

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortPlayerStateEndless", meta=(ClampMin="0", UIMin="0"))
	int32 BluGloActivityScore;

};

