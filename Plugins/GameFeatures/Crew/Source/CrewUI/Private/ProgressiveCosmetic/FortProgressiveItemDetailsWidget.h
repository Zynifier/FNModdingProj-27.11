// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortProgressiveItemDetailsWidget.generated.h"

class UAthenaRewardItemTypeRarityTag;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortProgressiveItemDetailsWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortProgressiveItemDetailsWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CosmeticStage;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortProgressiveItemDetailsWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_UnlockCriteria;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_UnlockCriteriaContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortProgressiveItemDetailsWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaRewardItemTypeRarityTag> Widget_ItemTypeRarityTag;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Tag_Owned;

};

