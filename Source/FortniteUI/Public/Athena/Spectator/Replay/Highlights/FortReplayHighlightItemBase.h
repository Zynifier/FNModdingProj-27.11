// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "CommonButtonLegacy.h"
#include "Player/FortPlayerControllerSpectating.h"
#include "FortReplayHighlightItemBase.generated.h"

class UFortReplayHighlightItemBase;
class UImage;
class UTextBlock;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReplayHighlightHighlightDelegate, UFortReplayHighlightItemBase*, Sender);

UCLASS(Abstract)
class UFortReplayHighlightItemBase : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void HandlePlayItemClicked();

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> TextBlock_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> TextBlock_Duration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortReplayHighlightItemBase")
	TMap<EHighlightReelTypes, FSlateBrush> IconMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortReplayHighlightItemBase")
	FSlateBrush DefaultIcon;

};

