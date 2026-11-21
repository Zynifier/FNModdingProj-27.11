// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialInteractionButton.h"
#include "FortSidebarSocialInteractionButton.generated.h"

class UCommonActionWidget;

UENUM(BlueprintType)
enum class EFortSidebarSocialInteractionArrow : uint8
{
	None = 0,
	Up = 1,
	Down = 2,
	Left = 3,
	Right = 4,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSidebarSocialInteractionButton : public USocialInteractionButton
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ShowAlternateInputAction(const bool bShow);

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortSidebarSocialInteractionButton")
	EFortSidebarSocialInteractionArrow ArrowDirection;

	UPROPERTY(BlueprintReadOnly, Export, Category="Input", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonActionWidget> AlternateInputActionWidget;

};

