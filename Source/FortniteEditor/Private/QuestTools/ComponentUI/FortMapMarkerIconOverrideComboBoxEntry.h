// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "FortMapMarkerIconOverrideComboBoxEntry.generated.h"

class UCommonTextBlock;
class UFortLazyImage;

UENUM(BlueprintType)
enum class EMapMarkerIconOverrideComboBoxEntryType : uint8
{
	Item = 0,
	Content = 1,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMapMarkerIconOverrideComboBoxEntry : public UEditorUtilityWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortMapMarkerIconOverrideComboBoxEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_Icon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMapMarkerIconOverrideComboBoxEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_IconName;

};

