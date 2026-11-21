// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateBrush.h"
#include "BlueprintContextBase.h"
#include "FortPickerData.h"
#include "FortPickerContext.generated.h"

class UFortItem;
class UFortItemDefinition;
class UFortPickerData;
class UFortSchematicItem;
class UObject;
class UTexture2D;
enum class EFortPickerMode : uint8;
enum class EFortPickerToDisplay : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPickerCommandDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickerOptionChosenDelegate, int32, PickerOption);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickerOptionSelectionMovedDelegate, int32, OptionDirection);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnShowPickerDelegate, EFortPickerMode, Mode, int32, InitialOption, bool, bIgnoreFirstAccept);

USTRUCT()
struct FFortPickerTemporaryWheelItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FText LabelOverride;

	UPROPERTY()
	TObjectPtr<UFortItemDefinition> Item;

};

USTRUCT()
struct FFortPickerTemporaryWheel
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortPickerTemporaryWheelItem> Items;

};

USTRUCT()
struct FTrackedTrapTimeAndCount
{
	GENERATED_BODY()

};

UCLASS()
class FORTNITEUI_API UFortPickerContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Setup")
	bool DoesRadialCloseOnRelease() const;

	UFUNCTION(BlueprintCallable, Category="Action")
	void GetAdjacentPickerWheelInformation(int32 Direction, FText& AdjacentTitle, bool& bCanPageThisDirection);

	UFUNCTION(BlueprintCallable, Category="Action")
	FText GetCurrentPickerDisplayName();

	UFUNCTION(BlueprintPure, Category="Action")
	int32 GetCurrentWheelIndex() const;

	UFUNCTION(BlueprintPure, Category="Content")
	UFortItem* GetListPickerOption(int32 Index) const;

	UFUNCTION(BlueprintPure, Category="Content")
	int32 GetNumPickerOptions() const;

	UFUNCTION(BlueprintCallable, Category="Action")
	void GetPickerWheelAdjacency(bool& bCanPageLeft, bool& bCanPageRight);

	UFUNCTION(BlueprintPure, Category="Content")
	void GetRadialPickerOptionImageAndLabel(int32 Index, FText& Label, FSlateBrush& Brush, TSoftObjectPtr<UTexture2D>& Icon, bool& bOptionEnabled, bool& bIsLocked) const;

	UFUNCTION(BlueprintPure, Category="Content")
	void GetRadialPickerOptionItem(int32 Index, UFortItem*& Item, bool& bOptionEnabled) const;

	UFUNCTION(BlueprintCallable, Category="Action")
	void LegacySwitchToAdjacentWheel(int32 SelectionDirection);

	UFUNCTION(BlueprintCallable, Category="Action")
	void PickerCanceled();

	UFUNCTION(BlueprintCallable, Category="Action")
	void PickerOptionAccepted(int32 Option);

	UFUNCTION(BlueprintCallable, Category="Setup")
	void RestoreInputAxes();

	UFUNCTION(BlueprintCallable, Category="Setup")
	void SetFortPickerData(UFortPickerData* Data);

	UFUNCTION(BlueprintCallable, Category="Action")
	void ShowRadialPickerMenu(EFortPickerToDisplay PickerType, int32 WheelIndex = -1, UObject* ContextObject = nullptr);

	UFUNCTION(BlueprintPure, Category="Setup")
	bool UseLeftThumbstick() const;

	UPROPERTY(BlueprintAssignable, Category="Setup")
	FOnShowPickerDelegate OnShowPicker;

	UPROPERTY(BlueprintAssignable, Category="Setup")
	FOnPickerCommandDelegate OnPickerConfirm;

	UPROPERTY(BlueprintAssignable, Category="Setup")
	FOnPickerCommandDelegate OnPickerCancel;

	UPROPERTY(BlueprintAssignable, Category="Setup")
	FOnPickerOptionSelectionMovedDelegate OnPickerOptionMoved;

	UPROPERTY(BlueprintAssignable, Category="Setup")
	FOnPickerOptionChosenDelegate OnPickerOptionChosen;

	UPROPERTY(BlueprintAssignable, Category="Setup")
	FOnPickerCommandDelegate OnPickerRefreshItems;

private:
	UPROPERTY(Transient)
	TArray<FItemDefOptionData> CustomPickerMenuItems;

	UPROPERTY(Transient)
	TArray<FSquadQuickChatOptionData> SquadChatMenuItems;

	UPROPERTY(Transient)
	TMap<TObjectPtr<UFortItemDefinition>, FTrackedTrapTimeAndCount> TrackedTrapsMap;

	UPROPERTY(Transient)
	TObjectPtr<UFortPickerData> PickerData;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortSchematicItem>> AccountTrapSchematics;

	UPROPERTY(Transient)
	TArray<FFortPickerTemporaryWheel> AvailableWheels;

	UPROPERTY(Transient)
	int32 CurrentWheelIndex;

	UPROPERTY(Transient)
	TMap<TObjectPtr<UObject>, int32> ConsumableStackCount;

	UPROPERTY(Transient)
	TMap<FGameplayTag, FText> CategoryTitles;

	UPROPERTY(Transient)
	TArray<FGameplayTag> CategoryTags;

};

