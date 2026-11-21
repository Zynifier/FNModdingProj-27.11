// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PanelWidget.h"
#include "GameplayTagContainer.h"
#include "FortActorCanvas.generated.h"

class UFortActorCanvasSlot;
class UFortActorIndicatorWidget;

UCLASS(MinimalAPI)
class UFortActorCanvas : public UPanelWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Canvas Panel")
	UFortActorCanvasSlot* AddActorIndicator(UFortActorIndicatorWidget* Indicator);

protected:
	UFUNCTION()
	void OnHUDElementVisibilityChanged(const FGameplayTagContainer& HiddenHUDElementTags);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	FGameplayTagContainer DefaultHUDElementTags;

	UPROPERTY(EditAnywhere, Category="ActorIndicator")
	bool bDrawElementsInOrder;

};

