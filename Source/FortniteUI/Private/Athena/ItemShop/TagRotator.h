// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "TagRotator.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaItemShopTagRotator : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnActiveStatusChanged(bool bIsActive);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTagEnter();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTagExit();

	UFUNCTION(BlueprintCallable)
	void UpdateTagText();

private:
	UPROPERTY(EditAnywhere, Category="Rotator Settings")
	float TimeBetweenTitleChanges;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopTagRotator", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TagCallout;

};

