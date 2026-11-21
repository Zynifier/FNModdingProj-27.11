// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "XpEverywhereAccoladesWidget.generated.h"

class UFortAccoladeItemDefinition;
class UTexture2D;
enum class EFortSimulatedXPSize : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UXpEverywhereAccoladesWidget : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void CloseWidget();

	UFUNCTION(BlueprintPure)
	bool HasMoreXPEvents() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnEventAdded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStompedByOtherWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void OpenWidget(const UFortAccoladeItemDefinition* AccoladeDef, const int32 XpValue, const FText& DisplayName, const TSoftObjectPtr<UTexture2D>& AccoladeLargePreviewImageOverride, const FText& SimulatedName, const FText& SimulatedText, const EFortSimulatedXPSize SimulatedXPSize);

private:
	UPROPERTY(EditDefaultsOnly, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

};

