// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "FortCosmeticLoadoutPartyReplState.generated.h"

USTRUCT(BlueprintType)
struct FCosmeticLoadoutPartyReplState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString BackpackPersistentName;

	UPROPERTY()
	FString BannerIconId;

	UPROPERTY()
	FString BannerColorId;

	UPROPERTY()
	int32 BattlePassLevel;

	UPROPERTY()
	int32 BattlePassSelfBoostXp;

	UPROPERTY()
	int32 BattlePassFriendBoostXp;

	UPROPERTY()
	FDisplayManagerVariantData AthenaCharacterVariantInfo;

};

