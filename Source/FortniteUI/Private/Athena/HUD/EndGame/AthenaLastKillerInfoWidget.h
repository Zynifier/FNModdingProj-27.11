// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "AthenaLastKillerInfoWidget.generated.h"

class UFortWeaponItemDefinition;
class UTexture2D;
class UUserWidget;
enum class EUIExtensionSlot : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FShouldShowDeathReport, bool, bHasDeathReport);

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaLastKillerInfoWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Extension Widget Created"))
	void BP_HandleExtensionWidgetCreated(UUserWidget* Widget, EUIExtensionSlot SlotType);

	UFUNCTION(BlueprintImplementableEvent)
	void SetKillerHealthAndShield(float HealthPercent, float ShieldPercent, float OvershieldPercent);

	UFUNCTION(BlueprintImplementableEvent)
	void SetKillerName(const FString& PlayerName, const FString& PlayerID);

	UFUNCTION(BlueprintImplementableEvent)
	void SetKillerWeaponIconAndName(UTexture2D* IconTexture, const UFortWeaponItemDefinition* ItemDef);

	UFUNCTION(BlueprintImplementableEvent)
	void SetNumOfKillerKills(int32 NumOfKillers);

	UPROPERTY(BlueprintAssignable)
	FShouldShowDeathReport ShouldShowDeathReport;

	UPROPERTY(EditAnywhere, Category="AthenaLastKillerInfoWidget")
	float TimeToWait;

};

