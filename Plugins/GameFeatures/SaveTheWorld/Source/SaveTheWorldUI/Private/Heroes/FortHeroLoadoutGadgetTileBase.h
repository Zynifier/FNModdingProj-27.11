// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortHeroLoadoutGadgetTileBase.generated.h"

class UCommonLazyImage;
class UCommonTextBlock;
class UFortGadgetItemDefinition;
class URichTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortHeroLoadoutGadgetTileBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnGadgetUpdated(bool bIsValidGadget);

	UFUNCTION(BlueprintCallable)
	void SetGadgetToRepresent(const UFortGadgetItemDefinition* GadgetItemDefinition);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_GadgetName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> Image_Icon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_Description;

	UPROPERTY(Transient)
	TObjectPtr<UFortGadgetItemDefinition> GadgetToRepresent;

};

