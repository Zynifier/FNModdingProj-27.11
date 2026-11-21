// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortMobileHUDLayoutToolV2_PresetEditorTool.generated.h"

class UFortMobileEditableText;
class UFortMobileHUDLayoutToolV2;
class UHUDLayoutToolV2_Button;
class UVerticalBox;

UCLASS(meta=(DisableNativeTick))
class UFortMobileHUDLayoutToolV2_PresetEditorTool : public UCommonUserWidget
{
	GENERATED_BODY()

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMobileHUDLayoutToolV2> HUDLayoutToolV2;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMobileEditableText> EditableText_PresetContainerTag;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMobileEditableText> EditableText_PresetTag;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMobileEditableText> EditableText_PresetExtensionContainerTag;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_ToggleSavingToExtension;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_SavePreset;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_CreateHotfix;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_Close;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_ExtensionSection;
#endif

};

