// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortActorIndicatorWidget.h"
#include "FortCreativeInfoIndicatorWidget.generated.h"

class UFortKeybindWidget;
enum class EFortBuildingInteraction : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(Category="Fortnite UI | Creative", ClassGroup="UI"))
class UFortCreativeInfoIndicatorWidget : public UFortActorIndicatorWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetKeyBindWidgetBoundAction(UFortKeybindWidget* FortKeyBindWidget, const FName ActionName, const EFortBuildingInteraction InteractionType);

};

