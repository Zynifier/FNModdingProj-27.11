// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "CommonPopupButtonLegacy.generated.h"

class UCommonPopupMenuLegacy;
class UMenuAnchor;
class UUserWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class COMMONUILEGACY_API UCommonPopupButtonLegacy : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="CommonPopupButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMenuAnchor> PopupMenuAnchor;

private:
	UFUNCTION()
	UUserWidget* GetMenuAnchorWidget();

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UCommonPopupMenuLegacy> PopupMenu;

};

