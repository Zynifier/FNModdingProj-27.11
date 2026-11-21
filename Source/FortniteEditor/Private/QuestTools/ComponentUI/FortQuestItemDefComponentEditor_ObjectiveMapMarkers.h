// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/ComponentUI/FortQuestItemDefComponentEditor_Objective.h"
#include "FortQuestItemDefComponentEditor_ObjectiveMapMarkers.generated.h"

class UFortMapMarkerIconOverrideComboBox;
class UMapMarkerTagsStatusWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortQuestItemDefComponentEditor_ObjectiveMapMarkers : public UFortQuestItemDefComponentEditor_Objective
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortQuestItemDefComponentEditor_ObjectiveMapMarkers")
	FName MapName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentEditor_ObjectiveMapMarkers", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMapMarkerIconOverrideComboBox> ComboBox_IconOverrides;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentEditor_ObjectiveMapMarkers", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMapMarkerTagsStatusWidget> Widget_MapMarkerTagsStatus;

private:
	UFUNCTION()
	void HandleIconOverrideChanged(const FName SelectedIconOverride);

};

