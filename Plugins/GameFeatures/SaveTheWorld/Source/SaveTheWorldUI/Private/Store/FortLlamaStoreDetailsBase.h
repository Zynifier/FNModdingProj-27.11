// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortLlamaStoreDetailsBase.generated.h"

class UCommonTileView;
class UFortStoreFrontOfferInfo;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(DisableNativeTick))
class UFortLlamaStoreDetailsBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortLlamaStoreDetailsBase")
	void SetScrollWidget();

	UFUNCTION(BlueprintImplementableEvent, Category="FortLlamaStoreDetailsBase")
	void StartUpgradingToGold();

	UFUNCTION(BlueprintImplementableEvent, Category="FortLlamaStoreDetailsBase")
	void StartUpgradingToSilver();

protected:
	UFUNCTION(BlueprintPure, Category="FortLlamaStoreDetailsBase")
	int32 GetChoiceItemCount() const;

	UFUNCTION(BlueprintPure, Category="FortLlamaStoreDetailsBase")
	int32 GetNewItemCount() const;

	UFUNCTION(BlueprintPure, Category="FortLlamaStoreDetailsBase")
	int32 GetNotInCollectionBookCount() const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortLlamaStoreDetailsBase")
	void OnOfferInfoChanged(int32 CurrentOfferRarity);

	UPROPERTY(BlueprintReadOnly, Category="FortLlamaStoreDetailsBase")
	TObjectPtr<UFortStoreFrontOfferInfo> OfferInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLlamaStoreDetailsBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTileView> ItemTileView;

};

