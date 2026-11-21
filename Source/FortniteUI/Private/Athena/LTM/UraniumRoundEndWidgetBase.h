// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/UraniumWidgetBase.h"
#include "UraniumRoundEndWidgetBase.generated.h"

class UOverlay;
class UPerkIntroScreenWidget;
class UUserWidget;

UCLASS()
class UUraniumRoundEndWidgetBase : public UUraniumWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void AttempShowRoundInfo();

	UFUNCTION()
	void HandleShowRoundIntro();

	UFUNCTION()
	void HandleUpdateRoundEndVisibility(bool bNewVisibility);

	UFUNCTION()
	void NativeOnPerkIntroFinished();

	UPROPERTY(EditAnywhere, Category="UraniumRoundEndWidgetBase", meta=(AllowedClasses="/Script/FortniteUI.PerkIntroScreenWidget"))
	TSubclassOf<UUserWidget> RoundInfoWidgetClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="UraniumRoundEndWidgetBase", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UOverlay> RoundInfoOverlay;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPerkIntroScreenWidget> PerkIntroScreenWidget;

};

