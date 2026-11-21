// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/TimerHandle.h"
#include "FortTypes.h"
#include "FortUITypes.h"
#include "FortCollectionBookRewardCardWidget.generated.h"

class UFortItem;
class UFortMultiSizeItemCard;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCollectionBookRewardCardWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDisplayedItemChangedEvent, UFortItem*, DisplayedItem);

public:
	UFUNCTION(BlueprintCallable, Category="CollectionBook")
	virtual void ClearRewards();

	UFUNCTION(BlueprintPure, Category="CollectionBook")
	virtual bool HasRewards() const;

	UFUNCTION(BlueprintCallable, Category="CollectionBook")
	virtual void SetRewards(const FFortRewardInfo& Rewards);

	UPROPERTY(BlueprintAssignable, Category="Item Picker")
	FOnDisplayedItemChangedEvent OnDisplayedItemChangedEvent;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMultiSizeItemCard> ItemCardWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UWidget> MultiItemRewardOverlay;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UWidget> ChoiceRewardOverlay;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> CheckmarkImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collection Book")
	float UpdateCardInterval;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collection Book")
	EFortItemCardSize ItemCardSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collection Book")
	bool bDisplayAsRewardCard;

	UPROPERTY(Transient)
	FFortRewardInfo RepresentedRewards;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItem>> DummyItems;

	UPROPERTY(Transient)
	FTimerHandle UpdateCardTimer;

};

