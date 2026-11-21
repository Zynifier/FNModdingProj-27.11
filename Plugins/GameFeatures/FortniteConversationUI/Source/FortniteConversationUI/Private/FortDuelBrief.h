// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemTransactionBrief.h"
#include "FortDuelBrief.generated.h"

class UCommonRichTextBlock;
class UCommonTileView;
class UFortItem;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortDuelBrief : public UFortItemTransactionBrief
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void DisplayLootItems(const TArray<UFortItem*>& Items);

private:
	UPROPERTY(EditAnywhere, Category="FortDuelBrief")
	FText TextTemplate;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDuelBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_Objective;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDuelBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTileView> TileView;

};

