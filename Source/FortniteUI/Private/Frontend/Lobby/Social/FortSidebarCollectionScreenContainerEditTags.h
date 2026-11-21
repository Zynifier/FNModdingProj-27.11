// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaCollectionScreenContainer.h"
#include "FortSidebarCollectionScreenContainerEditTags.generated.h"

class UCommonActivatableWidget;
class UCommonButtonBase;
class UHorizontalBox;
class USidebarTagsEditorHeaderWidget;
enum class ESocialTagCategory : uint8;

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSidebarCollectionScreenContainerEditTags : public UAthenaCollectionScreenContainer
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ToggleTagsInfoTooltip();

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Tab Title Change"))
	void BP_OnCollectionTabTitleChange(const ESocialTagCategory& TagCategory);

private:
	UFUNCTION(BlueprintCallable)
	void UpdateInputActionVisibility();

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USidebarTagsEditorHeaderWidget> HeaderWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarCollectionScreenContainerEditTags", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> TagsInfoTooltip;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_AddTag;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_ReplaceTag;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_RemoveTag;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> RemoveTagButton;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TouchBack;

	UPROPERTY(Config)
	bool bPurgeSystemTagsCacheOnCheckForReady;

};

