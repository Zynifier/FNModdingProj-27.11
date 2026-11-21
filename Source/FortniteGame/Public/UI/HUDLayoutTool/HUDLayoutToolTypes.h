// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanelSlot.h"
#include "GameplayTagContainer.h"
#include "UI/Bacchus/BacchusHudTypes.h"
#include "HUDLayoutToolTypes.generated.h"

UENUM(BlueprintType)
enum class EFireModeType : uint8
{
	//go to whatever the user setting is 

	Unset = 0,
	TapToShoot = 1,
	FireButton = 2,
	AutoFire = 3,
	ForceTouch = 4,
	Custom = 5,
	MAX = 6,
};

UENUM(BlueprintType)
enum class ELayoutDataType : uint8
{
	Custom = 0,
	DefaultToolLayout = 1,
	DefaultGameLayout = 2,
	MAX_Local = 3,
	CustomCloudLayout = 4,
};

USTRUCT(BlueprintType)
struct FFireModeData
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Category="FireModeData", meta=(AllowPrivateAccess="TRUE"))
	bool bAutoFireIsEnabled;

	UPROPERTY(BlueprintReadOnly, Category="FireModeData", meta=(AllowPrivateAccess="TRUE"))
	bool b3DTouchEnabled;

	UPROPERTY(BlueprintReadOnly, Category="FireModeData", meta=(AllowPrivateAccess="TRUE"))
	bool bTapToShootEnabled;

	UPROPERTY(BlueprintReadOnly, Category="FireModeData", meta=(AllowPrivateAccess="TRUE"))
	bool bAlwaysShowDedicatedButton;

	UPROPERTY(BlueprintReadOnly, Category="FireModeData", meta=(AllowPrivateAccess="TRUE"))
	EFireModeType FireModeType;

};

USTRUCT()
struct FHUDLayoutDataEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag VisualType;

	UPROPERTY()
	FAnchorData AnchroData;

	UPROPERTY()
	int32 ZOrder;

	UPROPERTY(EditAnywhere, Category="HUDLayoutDataEntry")
	EBacchusHUDStateType BuildVisibility;

	UPROPERTY(EditAnywhere, Category="HUDLayoutDataEntry")
	EBacchusHUDStateType CombatVisibility;

	UPROPERTY(EditAnywhere, Category="HUDLayoutDataEntry")
	EBacchusHUDStateType EditVisibility;

	UPROPERTY(EditAnywhere, Category="HUDLayoutDataEntry")
	EBacchusHUDStateType CreativeVisibility;

	UPROPERTY()
	float Property_0;

	UPROPERTY()
	float Property_1;

	UPROPERTY()
	float Property_2;

	UPROPERTY()
	float Property_3;

	UPROPERTY()
	TMap<FName, float> FloatProperties;

};

USTRUCT()
struct FHUDLayoutData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FHUDLayoutDataEntry> LayoutEntries;

};

