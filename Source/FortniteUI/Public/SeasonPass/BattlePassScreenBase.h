// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortRarityData.h"
#include "Frontend/FortItemPreviewScreen.h"
#include "SeasonPass/BattlePassTypes.h"
#include "BattlePassScreenBase.generated.h"

class AFortItemPreviewWorld;
class UAthenaAboutModal;
class UAthenaSeasonItemDefinition;
class UFortAccountItemDefinition;
class UFortActivatableMovieWidget;
class UFortItemDefinition;
class UFortSeasonLevelConfirmationScreen;
class UFortStreamMediaSource;
enum class EBattlePassView : uint8;

UCLASS(Abstract)
class FORTNITEUI_API UBattlePassScreenBase : public UFortItemPreviewScreen
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanEquipCurrentReward() const;

	UFUNCTION(BlueprintCallable)
	void EquipCurrentReward();

	UFUNCTION(BlueprintPure)
	virtual int32 GetNumberOfRewardsToPurchase() const;

	UFUNCTION(BlueprintPure)
	bool IsCurrentRewardEquipped() const;

	UFUNCTION(BlueprintPure)
	bool IsCurrentRewardOwned() const;

	UFUNCTION(BlueprintCallable)
	bool ShouldPlayBPVideo(bool bAllowUpdate = true);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnBattlePassViewChanged(EBattlePassView NewView);

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemEquipped(bool bSuccess);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNoCurrentSeason();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRequestViewReward();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRequestViewRewardComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetDifferentBPText();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPurchasedAnnualPass(bool bIsPurchased);

	UFUNCTION(BlueprintImplementableEvent)
	void OnVariantUpdate(int32 CurrentIndex, int32 TotalNumVariants);

	UFUNCTION(BlueprintImplementableEvent)
	void OnViewReward(FFortRarityItemData Rarity, bool bNoReward, const UFortItemDefinition* RewardItem);

	UPROPERTY(EditDefaultsOnly, Category="BattlePassScreenBase")
	float BackgroundTransitionTimerDelay;

	UPROPERTY(EditAnywhere, Category="BattlePassScreenBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle RefundGiftToken;

	UPROPERTY(EditDefaultsOnly, Category="BattlePassScreenBase")
	TSoftClassPtr<UFortSeasonLevelConfirmationScreen> SeasonLevelPurchaseScreenClass;

	UPROPERTY(EditDefaultsOnly, Category="BattlePassScreenBase")
	TSoftClassPtr<UAthenaAboutModal> SeasonAboutScreenClass;

	UPROPERTY(EditAnywhere, Category="BattlePassScreenBase")
	FGameplayTagContainer WrapPreviewExcludedTags;

	UPROPERTY(BlueprintReadOnly, Category="BattlePassScreenBase", meta=(AllowPrivateAccess="true"))
	EBattlePassView CurrentView;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaSeasonItemDefinition> SeasonData;

	UPROPERTY(Transient)
	TObjectPtr<AFortItemPreviewWorld> CachedVaultWorld;

	UPROPERTY(Transient)
	TObjectPtr<UFortAccountItemDefinition> LastViewedItem;

	UPROPERTY(EditDefaultsOnly, Category="BattlePassScreenBase")
	bool bShouldShowAboutModalInNewSeason;

	UPROPERTY(EditDefaultsOnly, Category="Video")
	TSoftClassPtr<UFortActivatableMovieWidget> SeasonMovieWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="Video")
	TObjectPtr<UFortStreamMediaSource> VideoStream_Source;

};

