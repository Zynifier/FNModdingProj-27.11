// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "MapMarkerTagsStatusWidget.generated.h"

class UExpandableArea;
class UHorizontalBox;
class UTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UMapMarkerTagsStatusWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="MapMarkerTagsStatusWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> Box_TagsOk;

	UPROPERTY(BlueprintReadOnly, Export, Category="MapMarkerTagsStatusWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> Box_PendingTagsWarning;

	UPROPERTY(BlueprintReadOnly, Export, Category="MapMarkerTagsStatusWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_PendingTagsWarning;

	UPROPERTY(BlueprintReadOnly, Export, Category="MapMarkerTagsStatusWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> Box_FailedTagsWarning;

	UPROPERTY(BlueprintReadOnly, Export, Category="MapMarkerTagsStatusWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_FailedTagsWarning;

	UPROPERTY(BlueprintReadOnly, Export, Category="MapMarkerTagsStatusWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> Box_FailedTagsWithChildrenWarning;

	UPROPERTY(BlueprintReadOnly, Export, Category="MapMarkerTagsStatusWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_FailedTagsWithChildrenWarning;

	UPROPERTY(BlueprintReadOnly, Export, Category="MapMarkerTagsStatusWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> Box_TagsNotInConfig;

	UPROPERTY(BlueprintReadOnly, Export, Category="MapMarkerTagsStatusWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_TagsNotInConfigWarning;

	UPROPERTY(BlueprintReadOnly, Export, Category="MapMarkerTagsStatusWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UExpandableArea> ExpandableArea_AdditionalInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="MapMarkerTagsStatusWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_AdditionalInfo;

};

