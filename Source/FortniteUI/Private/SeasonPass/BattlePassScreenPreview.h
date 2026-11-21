// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/DataAsset.h"
#include "CommonButtonLegacy.h"
#include "BattlePassScreenPreview.generated.h"

class UAthenaCharacterItemDefinition;
class UBattlePassPreviewDisplayData;
class UBattlePassScreenPreviewRewardWidget;
class UBattlePassScreenPurchaseButton;
class UBattlePassVBuckSummary;
class UCommonTextBlock;
class UFortItem;
class UFortLazyImage;
class UMaterialInstance;
enum class EBattlePassPurchaseButtonLayout : uint8;

UENUM(BlueprintType)
enum class EBattlePassPurchaseButtonLayout : uint8
{
	Normal = 0,
	Bundle = 1,
	Normal_PaysForSelf = 2,
};

USTRUCT(BlueprintType)
struct FBattlePassCharacterPreviewDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassCharacterPreviewDisplayData")
	TObjectPtr<UAthenaCharacterItemDefinition> CharacterItemDef;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BattlePassCharacterPreviewDisplayData")
	TObjectPtr<UMaterialInstance> PreviewMaterial;

};

USTRUCT()
struct FPreviewRewardData
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FPreviewUnlockRewardData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PreviewUnlockRewardData")
	int32 Currency;

	UPROPERTY(BlueprintReadOnly, Category="PreviewUnlockRewardData")
	int32 NumAdditionalRewards;

	UPROPERTY(BlueprintReadOnly, Category="PreviewUnlockRewardData")
	int32 TotalRewards;

	UPROPERTY(BlueprintReadOnly, Category="PreviewUnlockRewardData")
	int32 NumCharacters;

	UPROPERTY()
	TArray<FPreviewRewardData> Characters;

	UPROPERTY()
	TArray<FPreviewRewardData> AdditionalRewards;

};

USTRUCT(BlueprintType)
struct FPreviewUnlockData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PreviewUnlockData")
	FPreviewUnlockRewardData InstantRewards;

	UPROPERTY(BlueprintReadOnly, Category="PreviewUnlockData")
	FPreviewUnlockRewardData EarnedRewards;

	UPROPERTY(BlueprintReadOnly, Category="PreviewUnlockData")
	FText ChapterNumberText;

	UPROPERTY(BlueprintReadOnly, Category="PreviewUnlockData")
	FText SeasonNumberText;

	UPROPERTY(BlueprintReadOnly, Category="PreviewUnlockData")
	FText SummaryText;

	UPROPERTY(BlueprintReadOnly, Category="PreviewUnlockData")
	bool bPaysForSelf;

};

UCLASS(BlueprintType)
class UBattlePassPreviewDisplayData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="BattlePassPreviewDisplayData")
	TObjectPtr<UMaterialInstance> CurrencyMaterialInstance;

	UPROPERTY(EditAnywhere, Category="BattlePassPreviewDisplayData")
	TArray<FBattlePassCharacterPreviewDisplayData> CharacterPreviewDisplayData;

};

UCLASS(meta=(DisableNativeTick))
class UBattlePassScreenPreview : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleOnGainedFocus();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCyclePreviewReward(const UFortItem* NextReward, bool bReadyToUnlock, int32 LevelUnlocked);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitData(const FPreviewUnlockData& Data, const UFortItem* SinglePreviewCycleReward, bool bReadyToUnlock, int32 LevelUnlocked, bool bPurchasedAnnualPass);

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreview", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassScreenPreviewRewardWidget> Character_Widget1;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreview", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassScreenPreviewRewardWidget> Character_Widget2;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreview", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassScreenPreviewRewardWidget> Character_Widget3;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreview", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassScreenPreviewRewardWidget> Character_Widget4;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreview", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassScreenPreviewRewardWidget> Character_Widget5;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreview", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassScreenPreviewRewardWidget> Character_Widget6;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreview", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassScreenPreviewRewardWidget> Character_Widget7;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreview", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassScreenPreviewRewardWidget> Currency_Widget;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreview", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassScreenPurchaseButton> Button_PurchaseBattlePass;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreview", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassScreenPurchaseButton> Button_PurchaseBattlePassBundle;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreview", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_InstantUnlockTotalRewardCount;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreview", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_InstantUnlockSpecificSummary;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreview", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_InstantAdditionalRewards;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassVBuckSummary> Widget_VBuckSummary;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UBattlePassScreenPreviewRewardWidget>> CharacterWidgets;

	UPROPERTY(Transient)
	FPreviewUnlockData PreviewUnlockData;

	UPROPERTY(EditAnywhere, Category="BattlePassScreenPreview")
	TObjectPtr<UBattlePassPreviewDisplayData> PreviewDisplayData;

	UPROPERTY(EditAnywhere, Category="BattlePassScreenPreview")
	float PreviewCycleRate;

};

UCLASS()
class UBattlePassScreenPreviewRewardWidget : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetDataForCharacter(bool bIsReadyToUnlock, float LayoutPosition);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetDataForCurrency(float LayoutPosition);

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreviewRewardWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RewardName;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreviewRewardWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_Reward;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreviewRewardWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RewardLevel;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreviewRewardWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Currency;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPreviewRewardWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_AdditionalCurrency;

};

UCLASS()
class UBattlePassScreenPurchaseButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetData(EBattlePassPurchaseButtonLayout LayoutType);

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPurchaseButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FinalCost;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPurchaseButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PurchaseTitle;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPurchaseButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PurchaseSubtitle;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPurchaseButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_OriginalCost;

	UPROPERTY(BlueprintReadOnly, Export, Category="BattlePassScreenPurchaseButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_DiscountedPercentage;

};

