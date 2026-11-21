// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortLockerBuiltInEmoteWidget.generated.h"

class UFortCosmeticItemCard;
class UFortMontageItemDefinitionBase;
enum class EAthenaLockerInfoRestrictionWarning : uint8;

UCLASS()
class UFortLockerBuiltInEmoteWidget : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Exclusive Item")
	void OnUpdateAccessRestrictionWarning(bool bShouldShow, EAthenaLockerInfoRestrictionWarning WarningType);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLockerBuiltInEmoteWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCosmeticItemCard> Card_Item;

	UPROPERTY(Transient)
	TObjectPtr<UFortMontageItemDefinitionBase> EmoteDefinition;

};

