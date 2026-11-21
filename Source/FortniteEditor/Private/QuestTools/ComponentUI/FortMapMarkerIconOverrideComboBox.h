// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "Types/SlateEnums.h"
#include "FortMapMarkerIconOverrideComboBox.generated.h"

class UComboBoxKey;
class UDataTable;
class UFortMapMarkerIconOverrideComboBoxEntry;
class UWidget;
enum class EMapMarkerIconOverrideComboBoxEntryType : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMapMarkerIconOverrideComboBox : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnIconOverrideSelectionChanged, const FName, SelectedIconOverride);

public:
	UPROPERTY(BlueprintAssignable, Category="Event")
	FOnIconOverrideSelectionChanged OnIconOverrideSelectionChanged;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortMapMarkerIconOverrideComboBox", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UComboBoxKey> ComboBox_Icons;

private:
	UFUNCTION(BlueprintPure)
	UWidget* GenerateMapIconOverrideEntry(const FName IconName, const EMapMarkerIconOverrideComboBoxEntryType Type) const;

	UFUNCTION(BlueprintCallable)
	void HandleSelectedIconChanged(const FName SelectedIconName, const ESelectInfo::Type SelectionType);

	UPROPERTY(EditDefaultsOnly, Category="FortMapMarkerIconOverrideComboBox")
	TSoftObjectPtr<UDataTable> MapMarkersIconDataTable;

	UPROPERTY(EditDefaultsOnly, Category="FortMapMarkerIconOverrideComboBox")
	TSubclassOf<UFortMapMarkerIconOverrideComboBoxEntry> MapMarkerIconOverrideEntryClass;

};

