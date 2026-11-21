// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Types/SlateEnums.h"
#include "QuestTools/ComponentUI/FortQuestItemDefComponentEditor.h"
#include "FortQuestItemDefComponentEditor_MapMarkers.generated.h"

class UComboBoxKey;
class UFortMapMarkerIconOverrideComboBox;
class UMapMarkerTagsStatusWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortQuestItemDefComponentEditor_MapMarkers : public UFortQuestItemDefComponentEditor
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentEditor_MapMarkers", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UComboBoxKey> ComboBox_MapNames;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefComponentEditor_MapMarkers")
	FGameplayTagContainer QuestItemDefMarkerTags;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentEditor_MapMarkers", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMapMarkerIconOverrideComboBox> ComboBox_IconOverrides;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentEditor_MapMarkers", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMapMarkerTagsStatusWidget> Widget_MapMarkerTagsStatus;

private:
	UFUNCTION()
	void HandleIconOverrideChanged(const FName SelectedIconOverride);

	UFUNCTION()
	void HandleMapSelectionChanged(FName SelectedMapName, ESelectInfo::Type SelectionType);

};

