// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "Frontend/Spatial/SpatialItemPreviewScreen.h"
#include "SpatialCustomizationRoom.generated.h"

class UAthenaSpatialCustomizationCategories;
class UAthenaSpatialCustomizationRoomData;
class UAthenaSpatialCustomizationSelection;
class UAthenaSpatialCustomizationSubscreenBase;
class UCommonButtonLegacy;
class UFortGameStateComponent_EventLevel;
enum class ESpatialCustomizationRoomState : uint8;

UENUM(BlueprintType)
enum class ESpatialCustomizationRoomState : uint8
{
	None = 0,
	CategorySelection = 1,
	CustomizationSelection = 2,
};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaSpatialCustomizationRoom : public UAthenaSpatialItemPreviewScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRoomStateChanged(ESpatialCustomizationRoomState CurrentRoomState, ESpatialCustomizationRoomState PreviousRoomState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowFirstTimeInfo();

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialCustomizationRoom", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpatialCustomizationCategories> Categories;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialCustomizationRoom", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpatialCustomizationSelection> Selection;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialCustomizationRoom", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_About;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialCustomizationRoom")
	TObjectPtr<UAthenaSpatialCustomizationRoomData> CustomizationRoomData;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_EventLevel> EventGameStateComponent;

	UPROPERTY(Transient)
	TArray<FMcpVariantChannelInfo> CurrentVariantChannelStates;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaSpatialCustomizationSubscreenBase>> SubScreens;

	UPROPERTY(Transient)
	ESpatialCustomizationRoomState RoomState;

	UPROPERTY(Transient)
	FTimerHandle DelayedApplyColorHandle;

};

