// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "SpatialStyleCard.generated.h"

class UFortCosmeticItemCard;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaSpatialStyleCard : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnStyleImageSet(bool bUnlocked);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialStyleCard", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortCosmeticItemCard> ItemCard_Style;

};

