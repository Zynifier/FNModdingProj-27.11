// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/HUD/Radials/FortRadialPickerEntry.h"
#include "FortConversationOption.generated.h"

class UCommonVisibilitySwitcher;
class UFortItem;
class UObject;
class USoundBase;

UCLASS(Abstract)
class UFortConversationOption : public UFortRadialPickerEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetUnlockLevel() const;

	UFUNCTION(BlueprintPure)
	bool IsAvailable() const;

	UFUNCTION(BlueprintPure)
	bool IsLocked() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnOptionConfirmed();

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnSetupFromDisplayAsset(UObject* DisplayAsset);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnSetupFromItemDef(UFortItem* Item);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnSetupPivotFromRadialInformation(int32 NumElements, int32 ItemIndex);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cosmetic")
	TObjectPtr<USoundBase> OnOptionConfirmedSound;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Cosmetic")
	TObjectPtr<USoundBase> OnOptionHoveredSound;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortConversationOption", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_DisplayAsset;

	UPROPERTY(EditDefaultsOnly, Category="UI", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> DefaultSoftTaskIcon;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSoftObjectPtr<USoundBase> DefaultConfirmChoiceSound;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSoftObjectPtr<USoundBase> DefaultHoverChoiceSound;

};

