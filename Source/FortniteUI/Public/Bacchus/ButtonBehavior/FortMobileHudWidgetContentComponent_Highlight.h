// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/ButtonBehavior/FortMobileHudWidgetContentComponent.h"
#include "FortMobileHudWidgetContentComponent_Highlight.generated.h"

class UUserWidget;

UCLASS()
class UFortMobileHudWidgetContentComponent_Highlight : public UFortMobileHudWidgetContentComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Highlight")
	FGameplayTag HighlightTag;

	UPROPERTY(EditDefaultsOnly, Category="Highlight")
	TSoftClassPtr<UUserWidget> HighlightWidgetSoftClass;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> CurrentHighlight;

};

