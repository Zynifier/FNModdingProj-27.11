// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "EditorUtilityWidget.h"
#include "InstancedStruct.h"
#include "Types/SlateEnums.h"
#include "QuestEditorBase.generated.h"

class UCommonButtonGroupBase;
class UDataTable;
class UHorizontalBox;
class UImage;
class UObject;
class UQuestTabButton;
class UScrollBox;
class USearchableStringComboBox;

USTRUCT(BlueprintType)
struct FQuestEditorCommonData
{
	GENERATED_BODY()

};

UCLASS(Abstract)
class UQuestEditorBase : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void OpenSelectedAssets() const;

protected:
	UFUNCTION()
	void HandleEditorProfileChanged(const FString& SelectedItem, ESelectInfo::Type SelectionType);

	UPROPERTY(BlueprintReadOnly, Export, Category="QuestEditorBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<USearchableStringComboBox> ComboBox_Profiles;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuestEditorBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HorizontalBox_QuestTabs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest Editor Profiles")
	TSoftObjectPtr<UDataTable> ProfilesDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest Editor Profiles")
	FString DefaultProfile;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuestEditorBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> Tab_Box;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuestEditorBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_QuestTabs;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuestEditorBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ScrollLeft;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuestEditorBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ScrollRight;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> QuestTabs;

	UPROPERTY(EditAnywhere, Category="QuestEditorBase")
	TSoftClassPtr<UQuestTabButton> QuestTabButtonClass;

	UPROPERTY(meta=(BaseStruct="/Script/FortniteEditor.QuestEditorCommonData"))
	FInstancedStruct InstancedCommonData;

	UPROPERTY(EditAnywhere, Category="QuestEditorBase")
	TSoftClassPtr<UObject> DefaultQuestAssetClass;

private:
	UFUNCTION()
	void UpdateScrollIndicatorsVisibility(ESlateVisibility NewVisibility);

};

