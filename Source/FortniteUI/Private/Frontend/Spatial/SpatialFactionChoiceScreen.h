// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "SpatialFactionChoiceScreen.generated.h"

class UCommonButtonLegacy;

UCLASS(Abstract, BlueprintType, Blueprintable)
class USpatialFactionChoiceScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFactionChosenDynamic);

public:
	UPROPERTY(BlueprintAssignable)
	FOnFactionChosenDynamic BP_OnFactionChosen;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="SpatialFactionChoiceScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_FactionChoice1;

	UPROPERTY(BlueprintReadOnly, Export, Category="SpatialFactionChoiceScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_FactionChoice2;

};

