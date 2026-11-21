// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortBattlePassTileBase.h"
#include "FortBattlePassTile.generated.h"

class UFortLazyImage;
class UImage;
enum class EBattlePassCurrencyType : uint8;

UCLASS(Abstract, MinimalAPI)
class UFortBattlePassTile : public UFortBattlePassTileBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool HasPrerequisites() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnpreviewed();

protected:
	UFUNCTION(BlueprintPure)
	bool IsAffordable() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnAffordabilityChanged(const bool bHasEnougCurrency);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHighlighted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLockedProgressUpdated(const float Progress, const int32 CurrentlyOwnedRewards, const int32 NeededRewards);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLockedStateUpdated(const bool OwnsBattlePass, const bool ParentUnlocked, const bool HasRemainingPrerequisites, const bool bIsDelayed);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetCurrencyAndPrice(const EBattlePassCurrencyType Currency, const int32 Price);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetTrack(const bool bIsFreeTrack, const bool bOwnsBattlePass);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTilePreviewCycled();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnhighlighted();

	UPROPERTY(BlueprintReadWrite, Export, Category="FortBattlePassTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_RewardItem;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassTile", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Currency;

	UPROPERTY(BlueprintReadOnly, Category="FortBattlePassTile")
	bool bIsOnBulkBuyMode;

};

