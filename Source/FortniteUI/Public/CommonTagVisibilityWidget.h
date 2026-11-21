// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ContentWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "GameplayTagContainer.h"
#include "CommonTagVisibilityWidget.generated.h"

class APlayerController;
class ULocalPlayer;

UCLASS()
class UCommonTagVisibilityWidget : public UContentWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Common Tag Visibility Widget")
	void Initialize(ULocalPlayer* OwningLocalPlayer, APlayerController* OwningPlayerController);

protected:
	UFUNCTION()
	void HandleOnHUDElementVisibilityChanged(const FGameplayTagContainer& HiddenHUDElementTags);

	UFUNCTION(BlueprintImplementableEvent, Category="Visibility")
	void OnVisibilitySetEvent(ESlateVisibility InVisibility);

	UPROPERTY(EditAnywhere, Category="HUD")
	FGameplayTagContainer HUDElementTag;

};

