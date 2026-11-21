// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUITypes.h"
#include "Store/FortStoreFrontOfferDetailsWidgetBase.h"
#include "FortLlamaStoreInspectionScreen.generated.h"

class UCommonTileView;
class UFortCardPackItem;
class UObject;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class UFortLlamaStoreInspectionScreen : public UFortStoreFrontOfferDetailsWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	EInputActionState GetInspectChoiceInputState() const;

	UFUNCTION(BlueprintPure)
	UFortCardPackItem* GetSelectedCardPack() const;

	UFUNCTION(BlueprintPure)
	bool IsItemChoicePack(UObject* ItemToCheck) const;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLlamaStoreInspectionScreen", meta=(EditInline="true"))
	TObjectPtr<UCommonTileView> GrantedItemTileView;

	UPROPERTY(BlueprintReadWrite, Category="FortLlamaStoreInspectionScreen")
	bool bIsInChoiceViewMode;

};

