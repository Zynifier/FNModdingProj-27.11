// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Abilities/GameplayCues/GameplayCueNotify_OnShowEmoji.h"
#include "GameplayCueNotify_OnPreviewEmoji.generated.h"

UCLASS(HideCategories=("Replication"), meta=(Category="GameplayCue", DisplayName="GCN OnPreviewEmoji Burst"))
class UGameplayCueNotify_OnPreviewEmoji : public UGameplayCueNotify_OnShowEmoji
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="GCN OnPreviewEmoji")
	FVector RelativeLocationOffset;

	UPROPERTY(EditDefaultsOnly, Category="GCN OnPreviewEmoji")
	FVector InitialVelocityOffset;

};

