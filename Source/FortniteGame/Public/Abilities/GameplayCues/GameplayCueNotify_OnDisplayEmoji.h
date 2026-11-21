// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Abilities/GameplayCues/GameplayCueNotify_OnShowEmoji.h"
#include "GameplayCueNotify_OnDisplayEmoji.generated.h"

UCLASS(HideCategories=("Replication"), meta=(Category="GameplayCue", DisplayName="GCN OnDisplayEmoji Burst"))
class UGameplayCueNotify_OnDisplayEmoji : public UGameplayCueNotify_OnShowEmoji
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="GCN OnDisplayEmoji")
	FVector RelativeLocationOffset;

};

