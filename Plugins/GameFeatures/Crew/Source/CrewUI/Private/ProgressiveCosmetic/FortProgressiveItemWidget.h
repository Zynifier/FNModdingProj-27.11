// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Subscriptions/FortProgressiveItemTypes.h"
#include "FortProgressiveItemWidget.generated.h"

class UAthenaItemShopReactiveTileText;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortProgressiveItemWidget : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnHighlighted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPeekStateChanged(bool bIsInPeekState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStageItemChanged(const FProgressiveStageItemInfo& InStageItemInfo);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTileMaterialLoaded(const bool bSubscribed);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnhighlighted();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemShopReactiveTileText> TileText_ItemName;

	UPROPERTY(Transient)
	FProgressiveStageItemInfo StageItemInfo;

};

