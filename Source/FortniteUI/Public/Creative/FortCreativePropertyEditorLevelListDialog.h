// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/FortCreativePropertyEditorDialogBase.h"
#include "FortCreativePropertyEditorLevelListDialog.generated.h"

class UCommonButtonBase;
class UCommonListView;
class UFortEditableFilteredCountedTextBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativePropertyEditorLevelListDialog : public UFortCreativePropertyEditorDialogBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyEditorLevelListDialog", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortEditableFilteredCountedTextBox> FilteredTextEntry_Widget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyEditorLevelListDialog", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_Levels;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativePropertyEditorInstancedLevelListDialog : public UFortCreativePropertyEditorLevelListDialog
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	bool ValidateLevelNameText(const FString& LevelName);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyEditorInstancedLevelListDialog", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> IconButton_NewLevel;

};

