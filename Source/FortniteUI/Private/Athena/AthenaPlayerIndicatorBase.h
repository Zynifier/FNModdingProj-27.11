// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortActorIndicatorWidget.h"
#include "AthenaPlayerIndicatorBase.generated.h"

class AFortPlayerStateAthena;
class UUserWidget;
enum class ETeamMemberState : uint8;
enum class EUIExtensionSlot : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaPlayerIndicatorBase : public UFortActorIndicatorWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Being Revived State Changed"))
	void BP_OnHandleBeingRevivedStateChanged(bool bIsBeingRevived, float MaxReviveTime);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle DBNO State Changed"))
	void BP_OnHandleDBNOStateChanged(bool bIsDBNO);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Pin Color Changed"))
	void BP_OnHandlePinColorChanged(const FLinearColor& PinColor);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Player Name Replicated"))
	void BP_OnHandlePlayerNameReplicated(const FString& PlayerName);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Player State Set"))
	void BP_OnHandlePlayerStateSet(AFortPlayerStateAthena* PlayerStateAthena);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Talking State Changed"))
	void BP_OnHandleTalkingStateChanged(bool bIsTalking);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Team Member State Changed"))
	void BP_OnHandleTeamMemberStateChanged(ETeamMemberState TeamMemberState);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Update WorldName Visibility"))
	void BP_UpdateWorldNameVisibility(bool bDisplayWorldName);

	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetCreated(UUserWidget* Widget, EUIExtensionSlot SlotType);

private:
	UFUNCTION()
	void HandleCurrentPawnChanged();

	UPROPERTY(EditAnywhere, Category="AthenaPlayerIndicatorBase")
	FVector2D MinMaxSizeDistance;

	UPROPERTY(EditAnywhere, Category="AthenaPlayerIndicatorBase")
	FVector2D MinMaxScale;

	UPROPERTY(EditAnywhere, Category="AthenaPlayerIndicatorBase")
	float FarAwayScaleMultiplier;

	UPROPERTY(EditAnywhere, Category="AthenaPlayerIndicatorBase")
	FVector RelativeLocationWhenDBNO;

	UPROPERTY(EditAnywhere, Category="AthenaPlayerIndicatorBase")
	FVector RelativeLocationWhenNotDBNO;

	UPROPERTY(EditAnywhere, Category="AthenaPlayerIndicatorBase")
	FVector2D UnscaledScreenSpaceRelativeOffset;

};

