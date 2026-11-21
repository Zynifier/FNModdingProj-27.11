// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaMarkedActorIndicator.h"
#include "AthenaContextTutorialIndicator.generated.h"

class UOverlay;

UCLASS(Abstract)
class UAthenaContextTutorialIndicator : public UAthenaMarkedActorIndicator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetCurrentDotProduct() const;

	UFUNCTION(BlueprintPure)
	float GetMaxOffscreenTreshold() const;

	UFUNCTION(BlueprintPure)
	float GetMaxTreshold() const;

	UFUNCTION(BlueprintPure)
	float GetMinTreshold() const;

	UFUNCTION(BlueprintImplementableEvent)
	void PlayBounceAnimation();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayInAnimation();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayOutAnimation();

	UFUNCTION(BlueprintImplementableEvent)
	void SetIndicatorText(const FText& Text);

	UFUNCTION(BlueprintImplementableEvent)
	void SetScreenPercent(float Percent);

protected:
	UFUNCTION(BlueprintCallable)
	void SwitchIndicatorSize();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ActorIndicator", meta=(BlueprintProtected="true"))
	float OffscreenMaxTreshold;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaContextTutorialIndicator", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Icon_1;

	UPROPERTY(EditAnywhere, Category="AthenaContextTutorialIndicator")
	float ScreenEdgePaddingSizePercent;

};

