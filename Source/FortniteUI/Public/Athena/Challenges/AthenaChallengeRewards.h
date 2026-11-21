// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/UserWidgetPool.h"
#include "Components/SlateWrapperTypes.h"
#include "AthenaChallengeRewards.generated.h"

class UAthenaChallengeComponentWidget;
class UAthenaChallengeRewardItem;
class UFortDynamicEntryBox;
class UFortItemDefinition;
class UFortQuestDefinitionComponent_CustomRewardWidget;
class UOverlay;
class UUserWidget;

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FChallengeRewardCarouselData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> Widget;

	UPROPERTY(Transient)
	TObjectPtr<UFortItemDefinition> ItemDefinition;

};

UCLASS(Abstract, meta=(Category="FortniteUI", DisableNativeTick))
class UAthenaChallengeRewards : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaChallengeRewards(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void SetIsSelected(const bool bIsSelected);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnItemPresented(const UFortItemDefinition* Item);

	UPROPERTY(EditAnywhere, Category="AthenaChallengeRewards")
	bool bEnableRewardCountText;

	UPROPERTY(EditAnywhere, Category="AthenaChallengeRewards")
	ESlateVisibility DisabledVisibility;

	UPROPERTY(EditDefaultsOnly, Category="AthenaChallengeRewards")
	TSoftClassPtr<UAthenaChallengeRewardItem> ItemRewardWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaChallengeRewards")
	TMap<TSubclassOf<UFortQuestDefinitionComponent_CustomRewardWidget>, TSoftClassPtr<UAthenaChallengeComponentWidget>> CustomRewardWidgetClassesDictionary;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> ItemContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="AthenaChallengeRewardsMultiMarker"))
	TObjectPtr<UFortDynamicEntryBox> DynamicBox_MultiMarkers;

	UPROPERTY(Transient)
	TArray<FChallengeRewardCarouselData> CarouselData;

	UPROPERTY(Transient)
	FUserWidgetPool RewardWidgetsPool;

};

