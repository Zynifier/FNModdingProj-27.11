// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortEventTrackerModule.generated.h"

class UCommonButtonBase;
class UEventScreenListView;
class UFortCTAButton;
class UFortEventScreenData;
class UFortEventTokenCollectionWidget;
class UFortLazyImage;
class UTexture;

UCLASS()
class UFortEventTrackerModule : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortEventTrackerModule(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintPure)
	const UFortEventScreenData* GetEventScreenData() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnModuleInitialized(const UFortEventScreenData* InEventScreenData);

};

UCLASS()
class UFortEventTrackerModule_Banner : public UFortEventTrackerModule
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCTACompleted(const bool bIsComplete);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateBannerText(const FText& BannerText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateHeaderCTAText(const FText& HeaderCTAText);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTrackerModule_Banner", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_BannerArt;

};

UCLASS()
class UFortEventTrackerModule_Collection : public UFortEventTrackerModule
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnGatherTokenCollectionWidgets(TArray<UFortEventTokenCollectionWidget*>& OutCollectionWidgets) const;

};

UCLASS()
class UFortEventTrackerModule_CustomText : public UFortEventTrackerModule
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateText(const FText& CustomText);

};

UCLASS()
class UFortEventTrackerModule_EventDetails : public UFortEventTrackerModule
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateEventTimeRemaining(const FText& OutEventTimeRemaining);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateEventDetailsText(const FText& OutEventName, const FText& OutEventDescription);

};

UCLASS()
class UFortEventTrackerModule_Header : public UFortEventTrackerModule
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateEventResourceHeader(const FText& Header, const int32 ResourceValue);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateEventResourceStarterHeader(const FText& Header);

};

UCLASS()
class UFortEventTrackerModule_PremiumUpsell : public UFortEventTrackerModule
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	bool IsPremiumTrackOwned() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnIconLoaded(const UTexture* LoadedTexture);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateText(const FText& HeaderText, const FText& BodyText);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTrackerModule_PremiumUpsell", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_Prompt;

	UPROPERTY(EditAnywhere, Category="FortEventTrackerModule_PremiumUpsell")
	FText PromptTextUnowned;

	UPROPERTY(EditAnywhere, Category="FortEventTrackerModule_PremiumUpsell")
	FText PromptTextOwned;

};

UCLASS()
class UFortEventTrackerModule_ProgressiveRewards : public UFortEventTrackerModule
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateCompletionMessage(const bool bIsComplete, const FText& CompletionText);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTrackerModule_ProgressiveRewards", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UEventScreenListView> ListView_Rewards;

};

UCLASS()
class UFortEventTrackerModule_RewardDetails : public UFortEventTrackerModule
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateCompletedReward(const TArray<FText>& RewardNames);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateNextRewardDetails(const TArray<FText>& RewardNames, const int32 ResourceNeeded);

protected:
	UFUNCTION(BlueprintPure)
	bool IsPremiumTrackOwned() const;

};

UCLASS()
class UFortEventTrackerModule_RewardRemaining : public UFortEventTrackerModule
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateRemaining(const int32 ResourceNeeded, const int32 TotalResourceRequired, const bool bRequiresPremiumTrackPurchase);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTrackerModule_RewardRemaining", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PurchasePremium;

};

