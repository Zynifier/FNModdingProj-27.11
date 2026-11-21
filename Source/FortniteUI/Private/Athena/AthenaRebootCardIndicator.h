// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaMarkedActorIndicator.h"
#include "AthenaRebootCardIndicator.generated.h"

class UCommonTextBlock;
class UImage;
class UTextBlock;
class UWidgetAnimation;

UCLASS(Abstract)
class UAthenaRebootCardIndicator : public UAthenaMarkedActorIndicator
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleDisplayForSelf(bool bSelf);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaRebootCardIndicator", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaRebootCardIndicator", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_PlayerMarker;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaRebootCardIndicator", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> TimeText;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaRebootCardIndicator", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> UpdateTime;

};

