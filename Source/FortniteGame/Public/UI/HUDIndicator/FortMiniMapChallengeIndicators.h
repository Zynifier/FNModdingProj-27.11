// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "UI/HUDIndicator/FortMiniMapIndicator.h"
#include "FortMiniMapChallengeIndicators.generated.h"

class UFortControllerComponent_AthenaQuestsPinner;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortMiniMapChallengeIndicators : public UFortMiniMapIndicator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortMiniMapChallengeIndicators")
	FSlateBrush DefaultPinnedQuestIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="FortMiniMapChallengeIndicators")
	FVector2D PinnedQuestIconScale;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UFortControllerComponent_AthenaQuestsPinner* QuestPinner;

};

