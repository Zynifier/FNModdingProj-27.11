// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortItemQuantityPair.h"
#include "FortExpeditionRewardsWidget.generated.h"

class UCommonTileView;
class UFortExpeditionItem;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllExpeditionsCollected);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortExpeditionRewardsWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Expedition")
	void ProcessNextReward();

	UFUNCTION(BlueprintNativeEvent, Category="Expedition")
	void RefreshRewardsUI(const UFortExpeditionItem* Expedition, bool bExpeditionSucceeded, const TArray<FFortItemInstanceQuantityPair>& Rewards);

	UPROPERTY(BlueprintAssignable, Category="Expedition")
	FOnAllExpeditionsCollected OnAllExpeditionsCollected;

protected:
	UFUNCTION()
	void HandleCollectionExpeditionCompleted(bool bMcpSuccess, const UFortExpeditionItem* Expedition, bool bExpeditionSuccess, const TArray<FFortItemInstanceQuantityPair>& Rewards);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortExpeditionRewardsWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTileView> RewardsTileView;

	UPROPERTY(BlueprintReadOnly, Category="Expedition")
	bool bPendingCollection;

};

