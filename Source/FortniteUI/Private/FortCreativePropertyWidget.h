// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GameplayTagContainer.h"
#include "Types/SlateEnums.h"
#include "Creative/FortCreativeStatOption.h"
#include "FortPlaylistUserOptions.h"
#include "FortCreativePropertyWidget.generated.h"

class UColorOptionObjectWrapper;
class UCommonButtonLegacy;
class UEditableText;
class UFortCreativeDeviceButtonComponent;
class UFortCreativePropertyEditorDialogBase;
class UFortCreativePropertyNumericEntry;
class UFortEditableFilteredCountedTextBox;
class UIconOptionObjectWrapper;
class ULevelOptionObjectWrapper;
class UObject;
class UUserWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewLevelResult, bool, bSucceeded);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativePropertyEditWidgetBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnModified(bool bModified);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_PostInitEditWidget();

	UFUNCTION(BlueprintPure)
	virtual FText GetEntryDescriptionText() const;

	UFUNCTION(BlueprintPure)
	virtual FText GetEntryDisplayName() const;

	UFUNCTION(BlueprintPure)
	virtual FText GetEntryDisplayValue() const;

	UFUNCTION(BlueprintPure)
	bool GetIsModified() const;

	UFUNCTION(BlueprintPure)
	virtual FText GetStepperLabelForIndex(const int32 Index) const;

	UFUNCTION(BlueprintCallable)
	void SetIsModified(bool bModified);

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="CreativePropertyEditWidgetBase", meta=(EditInline="true"))
	TObjectPtr<UUserWidget> ExtraContentWidget;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="CreativePropertyEditWidgetBase", meta=(EditInline="true"))
	TObjectPtr<UFortCreativePropertyEditorDialogBase> DialogWidget;

	UPROPERTY(EditDefaultsOnly, Category="CreativePropertyEditWidgetBase")
	TSubclassOf<UUserWidget> ExtraContentWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="CreativePropertyEditWidgetBase")
	bool bAutoCreateDialogWidget;

	UPROPERTY(EditDefaultsOnly, Category="CreativePropertyEditWidgetBase")
	TSubclassOf<UFortCreativePropertyEditorDialogBase> DialogWidgetClass;

	UPROPERTY(BlueprintReadOnly, Category="Numeric Input")
	float DeviceOptionValueMin;

	UPROPERTY(BlueprintReadOnly, Category="Numeric Input")
	float DeviceOptionValueMax;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnEditWidgetClicked();

	UFUNCTION(BlueprintPure)
	bool IsDialogOpen() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnEditDialogOpenStateChanged(const bool bIsOpen);

	UFUNCTION(BlueprintImplementableEvent)
	void OnEditWidgetSelectedChanged(const bool bSelected);

	UFUNCTION(BlueprintNativeEvent)
	bool RefreshGrantedContextTags();

	UFUNCTION(BlueprintCallable)
	void RequestCloseDialog(const bool bSetFocusToOptionsList = true);

	UFUNCTION(BlueprintPure)
	const FText& RequestDeviceName() const;

	UFUNCTION(BlueprintCallable)
	void RequestSelected(UObject* ObjectToSelect, const bool bNavigateToItem);

	UFUNCTION(BlueprintCallable, meta=(BlueprintSetter))
	void SetCurrentIndexInStepperValue(int32 InStepperValue);

	UPROPERTY(BlueprintReadOnly, Category="CreativePropertyEditWidgetBase")
	TArray<FText> AvailableStepperValueLabels;

	UPROPERTY(BlueprintSetter=SetCurrentIndexInStepperValue, Category="CreativePropertyEditWidgetBase")
	int32 CurrentIndexInStepperValue;

	UPROPERTY(BlueprintReadOnly, Category="CreativePropertyEditWidgetBase")
	int32 StartingIndexInStepperValue;

	UPROPERTY(BlueprintReadOnly, Category="CreativePropertyEditWidgetBase")
	FGameplayTagContainer CachedGrantedContextTags;

	UPROPERTY(EditDefaultsOnly, Category="CreativePropertyEditWidgetBase")
	bool bAlwaysShowEditWidget;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="CreativePropertyEditWidgetBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Collapse;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativePropertyEditWidgetDeviceButtonComponentBase : public UCreativePropertyEditWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FText GetButtonLabel() const;

	UFUNCTION(BlueprintPure)
	UFortCreativeDeviceButtonComponent* GetDeviceButtonComponent() const;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortCreativeDeviceButtonComponent> DeviceButtonComponent;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativePropertyEditWidgetUserOptionBase : public UCreativePropertyEditWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	UObject* GetInitializingObject() const;

private:
	UPROPERTY(Transient)
	TObjectPtr<UObject> OptionDataObject;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativePropertyEditWidgetDirectNumericInputBase : public UCreativePropertyEditWidgetUserOptionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_PostNumericUpdateEditWidget(bool IsCustomValue);

	UFUNCTION(BlueprintCallable)
	void CheckIsNumeircValueModified();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Numeric Input")
	void HandleNumericEntryChanged(float InValue);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Numeric Input")
	void HandleNumericEntryCommited(float InValue, ETextCommit::Type CommitInfo);

	UFUNCTION(BlueprintCallable)
	void OnRotated();

	UFUNCTION(BlueprintCallable, Category="Numeric Input")
	FString ParseTeamOrClassOptionsAsString(const FString& OriginalString);

	UFUNCTION(BlueprintCallable, Category="Numeric Input")
	void SetNumericEntryEditable(bool bIsEditable);

	UFUNCTION(BlueprintPure, Category="Numeric Input")
	void TryGetCurrentOptionValue(FString& Data) const;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="Numeric Input", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCreativePropertyNumericEntry> CreativeProperty_NumericEntry;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativePropertyEditWidgetIconBase : public UCreativePropertyEditWidgetUserOptionBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CreativePropertyEditWidgetIconBase")
	TArray<TObjectPtr<UIconOptionObjectWrapper>> IconOptionObjects;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativePropertyEditWidgetLevelListBase : public UCreativePropertyEditWidgetUserOptionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateCurrentLevelOptionName(const FText& UpdatedLevelName);

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CreativePropertyEditWidgetLevelListBase")
	TArray<TObjectPtr<ULevelOptionObjectWrapper>> LevelOptionObjects;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativePropertyEditWidgetInstancedLevelList : public UCreativePropertyEditWidgetLevelListBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void HandleNewLevelButtonClicked();

protected:
	UFUNCTION()
	void ClientLevelListUpdated();

	UPROPERTY(Transient)
	TArray<TObjectPtr<ULevelOptionObjectWrapper>> OldLevelOptionObjects;

	UPROPERTY(BlueprintReadOnly, Category="CreativePropertyEditWidgetInstancedLevelList")
	bool bWaitingForNewLevel;

	UPROPERTY(BlueprintAssignable)
	FOnNewLevelResult OnNewLevelResult;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativePropertyEditWidgetMessageComponentBase : public UCreativePropertyEditWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void HandleChannelNumericEntryChanged(const FText& Text);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void HandleChannelNumericEntryCommitted(const FText& InText, ETextCommit::Type CommitInfo);

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativePropertyEditWidgetMessageComponentBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditableText_NumericEntry;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativePropertyEditWidgetMusicTrackBase : public UCreativePropertyEditWidgetUserOptionBase
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativePropertyEditWidgetStatListBase : public UCreativePropertyEditWidgetUserOptionBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CreativePropertyEditWidgetStatListBase")
	TArray<FCreativeStatOption> StatOptions;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativePropertyEditWidgetStringBase : public UCreativePropertyEditWidgetUserOptionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const int32 GetEntryCharacterLimit() const;

protected:
	UFUNCTION(BlueprintNativeEvent)
	bool HandlesCharLimitValidation() const;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="CreativePropertyEditWidgetStringBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortEditableFilteredCountedTextBox> FilteredTextEntry_Widget;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativePropertyEditWidgetTintedIconIntBase : public UCreativePropertyEditWidgetUserOptionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FPlaylistOptionTintedIconIntValue GetCustomValueOption() const;

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CreativePropertyEditWidgetTintedIconIntBase")
	TArray<TObjectPtr<UColorOptionObjectWrapper>> ColorOptionObjects;

};

