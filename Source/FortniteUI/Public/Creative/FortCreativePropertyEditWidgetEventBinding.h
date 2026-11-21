// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortCreativePropertyWidget.h"
#include "FortCreativePropertyEditWidgetEventBinding.generated.h"

class UCommonButtonBase;
class UCommonTextBlock;
class UUserWidget;
enum class EFortGameplayEventReferenceType : uint8;

UCLASS(Abstract, Blueprintable, meta=(DisableNativeTick, NotBlueprintType="true"))
class UFortCreativePropertyEditWidgetEventBinding : public UCreativePropertyEditWidgetUserOptionBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnHideBindings();

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsAnySubItemSelectedChanged(const bool bIsAnySubItemSelected);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNumAvailableDevicesChanged(const int32 NumAvailableDevices);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNumEventReferencesChanged(const int32 NumEventReferences);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPropertyNameSet(const FText& PropertyName);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowBindings();

private:
	UFUNCTION(BlueprintPure)
	EFortGameplayEventReferenceType GetEventReferenceType() const;

	UFUNCTION(BlueprintPure)
	bool IsShowingBindings() const;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyEditWidgetEventBinding", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PropertyName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyEditWidgetEventBinding", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_AddBinding;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyEditWidgetEventBinding")
	TSubclassOf<UUserWidget> EntryClass;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyEditWidgetEventBinding")
	FDataTableRowHandle ShowHideBindingsInputAction;

};

