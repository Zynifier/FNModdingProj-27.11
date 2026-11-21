// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonBase.h"
#include "FortCreativePropertyKnobEntry.generated.h"

class UCommonTextBlock;
class UCommonVisibilitySwitcher;
class UCreativePropertyEditWidgetBase;
class UNamedSlot;
class UPanelWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativePropertyKnobEntry : public UCommonButtonBase, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnKnobEntryEditWidgetContextTagsChanged);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKnobEntryEditWidgetStateChanged, bool, bOpened);

public:
	UFUNCTION(BlueprintCallable)
	void ClearModified();

	UFUNCTION(BlueprintCallable)
	void ForceFocusWidget();

	UFUNCTION(BlueprintPure)
	bool GetIsModified();

	UPROPERTY(BlueprintAssignable)
	FOnKnobEntryEditWidgetStateChanged OnKnobEntryEditWidgetStateChanged;

	UPROPERTY(BlueprintAssignable)
	FOnKnobEntryEditWidgetContextTagsChanged OnKnobEntryEditWidgetContextTagsChanged;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnModified(bool bModified);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_PostInitSummaryData(UCreativePropertyEditWidgetBase* CustomEditWidget);

	UFUNCTION(BlueprintCallable)
	void SetIsModified(bool bModified);

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCreativePropertyKnobEntry", meta=(EditInline="true"))
	TObjectPtr<UCreativePropertyEditWidgetBase> EntryEditWidget;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyKnobEntry")
	TSubclassOf<UCreativePropertyEditWidgetBase> FallbackEditWidget;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyKnobEntry")
	TSubclassOf<UCreativePropertyEditWidgetBase> FallbackUserOptionEditWidget;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyKnobEntry")
	TSubclassOf<UCreativePropertyEditWidgetBase> FallbackStringUserOptionEditWidget;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyKnobEntry")
	TSubclassOf<UCreativePropertyEditWidgetBase> FallbackMusicUserOptionEditWidget;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyKnobEntry")
	TSubclassOf<UCreativePropertyEditWidgetBase> FallbackMessageComponentEditWidget;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyKnobEntry")
	TSubclassOf<UCreativePropertyEditWidgetBase> FallbackDeviceButtonComponentEditWidget;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyKnobEntry")
	TSubclassOf<UCreativePropertyEditWidgetBase> FallbackColorUserOptionEditWidget;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyKnobEntry")
	TSubclassOf<UCreativePropertyEditWidgetBase> FallbackIconUserOptionEditWidget;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyKnobEntry")
	TSubclassOf<UCreativePropertyEditWidgetBase> FallbackEventDescriptorUserOptionEditWidget;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyKnobEntry")
	TSubclassOf<UCreativePropertyEditWidgetBase> FallbackEventFunctionUserOptionEditWidget;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyKnobEntry")
	TSubclassOf<UCreativePropertyEditWidgetBase> FallbackNumericUserOptionEditWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyKnobEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_Content;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyKnobEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_SummaryBox;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyKnobEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_ContentBox;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyKnobEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_DisplayName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyKnobEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_DisplayedValue;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyKnobEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UNamedSlot> NamedSlot_ExtraContent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_DebugText;

#if WITH_EDITORONLY_DATA
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyKnobEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> DebugText_Data;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyKnobEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> DebugText_ClassName;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyKnobEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> DebugText_WidgetName;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyKnobEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> DebugText_OptionValueName;
#endif

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCreativePropertyEditWidgetBase> CustomEditWidgetForSanitizeQuery;

};

