// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Components/ListViewBase.h"
#include "HardcoreModifierSelectionScreen.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UHardcoreModifierListView;
class UHardcoreModifierPreviewPane;

UCLASS()
class UHardcoreModifierListView : public UListViewBase
{
	GENERATED_BODY()

public:
	UHardcoreModifierListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

UCLASS(Abstract, BlueprintType, meta=(DisableNativeTick))
class UHardcoreModifierSelectionScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void ApplyModifiers();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_Heading;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHardcoreModifierListView> ListView_Challenges;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHardcoreModifierPreviewPane> PreviewPane_Modifier;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Save;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

};

