// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Misc/Timespan.h"
#include "FortBattlePassRewardGridHeader.generated.h"

enum class ERewardPageType : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class BATTLEPASSBASE_API UFortBattlePassRewardGridHeader : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortBattlePassRewardGridHeader(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	int32 GetPageNumber() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnBattlePassLevelSet(const int32 BattlePassLevel);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPageLocked(const int32 RequiredLevel, const int32 RequiredRewards, const bool IsTimeLocked, FTimespan TimeRemaining);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPageNumberSet(const int32 InPageNumber);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPageUnlocked(const int32 PurchasedRewards, const int32 TotalRewards);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPageCustomName(const FText& CustomName);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPageType(const ERewardPageType PageType);

};

