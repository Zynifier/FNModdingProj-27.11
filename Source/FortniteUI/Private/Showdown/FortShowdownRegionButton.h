// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonPopupButtonLegacy.h"
#include "FortShowdownRegionButton.generated.h"

class UCommonTextBlock;
class UFortShowdownRegionPopupMenu;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShowdownRegionButtonOpenChanged, bool, bIsOpen);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShowdownRegionChanged);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortShowdownRegionButton : public UCommonPopupButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ClosePopup();

	UPROPERTY(BlueprintAssignable)
	FOnShowdownRegionButtonOpenChanged OnPopupChanged;

	UPROPERTY(BlueprintAssignable)
	FOnShowdownRegionChanged OnRegionChanged;

protected:
	UPROPERTY(EditAnywhere, Category="FortShowdownRegionButton")
	TSubclassOf<UFortShowdownRegionPopupMenu> BindingMenuClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="Text Block", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RegionName;

private:
	UFUNCTION()
	void HandlePopupChanged(bool bIsOpen);

	UFUNCTION()
	void HandleRegionSelectedChanged(int32 SelectedButtonIndex);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortShowdownRegionPopupMenu> RegionMenuInstance;

};

