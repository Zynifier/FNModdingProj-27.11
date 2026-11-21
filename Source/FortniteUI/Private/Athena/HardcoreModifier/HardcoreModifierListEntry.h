// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "CommonUserWidget.h"
#include "HardcoreModifierListEntry.generated.h"

class UButton;
class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UHardcoreModifierListEntry : public UCommonUserWidget, public IUserListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetMaxLevelCompleted(int32 MaxLevel);

	UPROPERTY(BlueprintReadOnly, Export, Category="HardcoreModifierListEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Modifier;

protected:
	UFUNCTION()
	virtual void HandleEntryClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleModifierEnabled(bool bModifierEnabled);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> Button_ClickCatcher;

};

